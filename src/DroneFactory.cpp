#include "DroneFactory.h"

#include <iostream>
#include <map>

namespace jb
{

static std::map<char, DroneConfig> DRONE_CONFIGS;

DroneConfig DroneFactory::createDrone(char type)
{
    if (DRONE_CONFIGS.empty())
    {
        DRONE_CONFIGS.emplace('A', DroneConfig(300, std::make_unique<SensorA>()));
        DRONE_CONFIGS.emplace('B', DroneConfig(500, std::make_unique<SensorB>()));
        DRONE_CONFIGS.emplace('C', DroneConfig(400, std::make_unique<SensorC>()));
    }
    return std::move(DRONE_CONFIGS.at(type));
}

} // jb