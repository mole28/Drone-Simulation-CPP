#ifndef __DroneSimulation_h__
#define __DroneSimulation_h__

#include "DroneState.h"
#include "WorldGrid.h"
#include "DroneNetworkServer.h"
#include "DroneFactory.h"

#include <map>
#include <set>

namespace jb 
{

class Command;

class DroneSimulation 
{
public:
    DroneSimulation();
    void run();

private:
    void processDroneAction(size_t id, const std::string& input);
    void handleCollisions(size_t activeId);
    void executeCommand(size_t id, DroneState& current, Command& cmd);
    void sendWelcomeMessage(size_t socketId);
    void resolveAndExecuteCommand(size_t id, DroneState& current, const std::string& input);
    std::map<std::string, Command*> createCommandsMap(DroneState& current);
    std::set<size_t> m_welcomedClients;

    static constexpr int DEFAULT_PORT = 12345;

    WorldGrid m_world;
    DroneNetworkServer m_nh;
    std::map<size_t, DroneState> m_drones;
    std::unique_ptr<DroneConfig> m_config;

    bool m_doLoop;
};

} // jb

#endif