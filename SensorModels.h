#ifndef __SensorModels_h__
#define __SensorModels_h__

#include "TheSensor.h"

namespace jb
{

class SensorA : public TheSensor
{
public:
    virtual unsigned int getEnergyCost() const override { return 10; } //an arbitrary number
};

class SensorB : public TheSensor
{
public:
    virtual unsigned int getEnergyCost() const override { return 20; } //an arbitrary number
};

class SensorC : public TheSensor
{
public:
    virtual unsigned int getEnergyCost() const override { return 30; } //an arbitrary number
};

} // jb

#endif