#include "DroneSimulation.h"
#include "Tile.h"
#include "Cmd/Forward.h"
#include "Cmd/TurnLeft.h"
#include "Cmd/TurnRight.h"
#include "DroneScanner.h"          
#include "CmdFixedConsumption.h"
#include "CmdShowMap.h"

namespace jb 
{

DroneSimulation::DroneSimulation()
    : m_nh(DEFAULT_PORT), m_doLoop(true)
{
}

struct CmdUnknown : public Command
{
    virtual void execute(const OutPutContext& output) const override
    {
        output.output("Unknown command!!!\n");
    }
    virtual unsigned int getEnergyConsumption() const override
    {
        return 0;
    }
} static CMD_UNKNOWN;

void DroneSimulation::run()
{
    while (m_doLoop)
    {
        size_t socketId;
        std::string input;
        m_nh.GetInput(&socketId, &input);
        sendWelcomeMessage(socketId);

        if (input.empty() || input == "\r\n" || input == "\n")
        {
            continue;
        }
        m_nh.PutOutput(socketId, "[NETWORK] Processing: '" + input + "'\n");
        if (m_config == nullptr)
        {
            char type = toupper(input[0]);
            if (type == 'A' || type == 'B' || type == 'C')
            {
                m_config = std::make_unique<DroneConfig>(DroneFactory::createDrone(type));
                m_drones[socketId] = DroneState();
                m_nh.PutOutput(socketId, "Success: Drone type " + std::string(1, type) + " selected.\n");
                m_nh.PutOutput(socketId, "[INFO] Available commands: fwd, +90, -90, pov, map\n");
            }
            else
            {
                m_nh.PutOutput(socketId, "Please choose drone type first (A, B, or C):\n");
            }
            continue;
        }
        processDroneAction(socketId, input);
    }
}

void DroneSimulation::processDroneAction(size_t id, const std::string& input)
{
    if (m_drones.find(id) == m_drones.end()) 
    {
        m_drones[id] = DroneState();
    }
    DroneState& current = m_drones[id];

    if (!current.isAlive()) 
    {
        m_nh.PutOutput(id, "[OFFLINE] Connection lost: Your drone has been destroyed.\n");
        return;
    }
    resolveAndExecuteCommand(id, current, input);

    handleCollisions(id);
    const Position& p = current.getPos();
    if (current.isAlive() && m_world.getTile(p.getX(), p.getY()).shouldExit()) 
    {
        m_nh.PutOutput(id, "Mission Accomplished!!!\n");
    }
}

void DroneSimulation::executeCommand(size_t id, DroneState& current, Command& cmd)
{
    unsigned int cost = cmd.getEnergyConsumption();
    if (current.getEnergy() >= cost)
    {
        unsigned int newEnergy = current.getEnergy() - cost;
        current.setEnergy(newEnergy);

        OutPutContext context(m_nh, id);
        m_nh.PutOutput(id, "[ACTION] Executing mission step... (Energy Cost: " + std::to_string(cost) + ")\n");
        cmd.execute(context);
        m_nh.PutOutput(id, "[STATUS] Action successful. Remaining Energy: "
            + std::to_string(current.getEnergy()) + "\n");
    }
    else
    {
        m_nh.PutOutput(id, "[CRITICAL] Mission failed: Not enough energy!\n");
    }
}

std::map<std::string, Command*> DroneSimulation::createCommandsMap(DroneState& current)
{
    std::map<std::string, Command*> commands;
    if (!m_config)
    {
        return commands;
    }
    std::vector<Position> activePositions;
    for (const auto& pair : m_drones)
    {
        if (pair.second.isAlive())
        {
            activePositions.push_back(pair.second.getPos());
        }
    }
    auto rawForward = new CmdForward(&m_world, &current.getPosNonConst(), current.getCompassPtr());
    auto rawLeft = new CmdTurnLeft(current.getCompassPtr());
    auto rawRight = new CmdTurnRight(current.getCompassPtr());

    commands["map"] = new CmdShowMap(&m_world, current.getPos(), activePositions);
    commands["fwd"] = new CmdFixedConsumption(rawForward, 10);
    commands["+90"] = new CmdFixedConsumption(rawRight, 5);
    commands["-90"] = new CmdFixedConsumption(rawLeft, 5);

    if (m_config->povSensor)
    {
        auto rawPov = new DroneScanner(&m_world, &current.getPosNonConst(),
            current.getCompassPtr(), m_config->povSensor.get(), activePositions);
        commands["pov"] = new CmdFixedConsumption(rawPov, m_config->povSensor->getEnergyCost());
    }
    else
    {
        commands["pov"] = new CmdUnknown();
    }
    return commands;
}

void DroneSimulation::handleCollisions(size_t activeId)
{
    DroneState& current = m_drones[activeId];
    const Position& curPos = current.getPos();

    for (auto& [id, other] : m_drones)
    {
        const Position& otherPos = other.getPos();
        if (id != activeId && other.isAlive() &&
            otherPos.getX() == curPos.getX() &&
            otherPos.getY() == curPos.getY())
        {
            current.kill();
            other.kill();
            m_nh.PutOutput(activeId, "CRASH! You collided with drone " + std::to_string(id) +
                                        " and was destroyed!\n");
            m_nh.PutOutput(id, "CRASH! Drone " + std::to_string(activeId) +
                                " collided into you! You are destroyed!\n");
            break;
        }
    }
}

void DroneSimulation::resolveAndExecuteCommand(size_t id, DroneState& current, const std::string& input)
{
    std::string cleanS = input;

    const std::string whitespace = " \n\r\t";
    cleanS.erase(0, cleanS.find_first_not_of(whitespace));
    size_t last = cleanS.find_last_not_of(whitespace);
    if (last != std::string::npos) cleanS.erase(last + 1);

    auto commands = createCommandsMap(current); 

    if (commands.count(cleanS))
    {
        executeCommand(id, current, *commands[cleanS]);
    }
    else
    {
        m_nh.PutOutput(id, "[ERROR] Unknown command: '" + cleanS + "'. Check your keyboard language!\n");
        executeCommand(id, current, CMD_UNKNOWN);
    }
    for (auto it = commands.begin(); it != commands.end(); ++it)
    {
        delete it->second;
    }
}

void DroneSimulation::sendWelcomeMessage(size_t socketId)
{
    if (m_welcomedClients.find(socketId) == m_welcomedClients.end())
    {
        m_nh.PutOutput(socketId, "WELCOME TO DRONE SIMULATION\n");
        m_nh.PutOutput(socketId, "[SYSTEM] Please select drone type: [A], [B], or [C]\n");
        m_nh.PutOutput(socketId, "Your choice > ");
        m_welcomedClients.insert(socketId);
    }
}

} // jb