#include "Command.h"

#include <iostream>
#include <string>

ForwardCommand::ForwardCommand(Drone& drone, Map& map)
    : m_drone(drone), m_map(map) 
{
}

void ForwardCommand::execute() const 
{
    int nextX = m_drone.getX();
    int nextY = m_drone.getY();
    std::string direction = m_drone.getCompass().getCurrentDirectionName();

    if (direction == "NORTH") nextY--;
    else if (direction == "SOUTH") nextY++;
    else if (direction == "EAST") nextX++;
    else if (direction == "WEST") nextX--;

    if (m_map.isOutOfBounds(nextX, nextY))
    {
        std::cout << "Cannot move: Out of bounds!" << std::endl;
        return;
    }

    Cell& targetCell = m_map.getCell(nextX, nextY);

    if (!targetCell.isPassable()) 
    {
        std::cout << "Obstacle detected! Movement blocked." << std::endl;
    }
    else 
    {
        m_drone.setLocation(nextX, nextY);
        std::cout << "Moved to (" << m_drone.getX() << ", " << m_drone.getY() << ")" << std::endl;

        if (targetCell.isExit()) 
        {
            std::cout << "Target Reached! Simulation Complete." << std::endl;
            exit(0);
        }
    }
}

TurnRightCommand::TurnRightCommand(Drone& drone) : m_drone(drone)
{
}

void TurnRightCommand::execute() const 
{
    m_drone.getCompass().rotateRight();
    std::cout << "Turned Right. New direction: " << m_drone.getCompass().getCurrentDirectionName() << std::endl;
}

TurnLeftCommand::TurnLeftCommand(Drone& drone) : m_drone(drone) {}

void TurnLeftCommand::execute() const 
{
    m_drone.getCompass().rotateLeft();
    std::cout << "Turned Left. New direction: " << m_drone.getCompass().getCurrentDirectionName() << std::endl;
}

void QuitCommand::execute() const 
{
    std::cout << "Exiting drone simulation." << std::endl;
    exit(0);
}