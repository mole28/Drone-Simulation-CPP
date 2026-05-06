#ifndef __DroneFactory_h__
#define __DroneFactory_h__

#include "SensorModels.h"

#include <memory>

namespace jb
{

class TheSensor;

struct DroneConfig
{
    unsigned int startingEnergy;
    std::unique_ptr<TheSensor> povSensor;

    DroneConfig(unsigned int energy, std::unique_ptr<TheSensor> sensor):
        startingEnergy{ energy }, povSensor{ std::move(sensor) }
    {
	}
};

class DroneFactory 
{
public:
    static DroneConfig createDrone(char type);
};

} // jb

#endif