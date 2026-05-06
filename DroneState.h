#ifndef __DroneState_h__
#define __DroneState_h__

#include "Compass.h"
#include "Position.h" 

namespace jb
{

class DroneState
{
public:
    DroneState() : m_pos(0, 0), m_compass(NORTH), m_energy(300), m_isAlive(true)
    {
    }

    const Position& getPos() const;
    Compass getCompass() const;
	unsigned int getEnergy() const;
    Compass* getCompassPtr();
    Position& getPosNonConst();
	bool isAlive() const;
    void kill();
    void setEnergy(unsigned int energy);

private:
    Position m_pos;
    Compass m_compass;
    unsigned int m_energy;
    bool m_isAlive;
};

} // jb

#endif