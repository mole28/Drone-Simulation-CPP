#include "DroneState.h"

namespace jb
{

const Position& DroneState::getPos() const
{
	return m_pos;
}

Compass DroneState::getCompass() const
{
	return m_compass;
}

Position& DroneState::getPosNonConst()
{
	return m_pos;
}

unsigned int DroneState::getEnergy() const
{
	return m_energy;
}

bool DroneState::isAlive() const
{
	return m_isAlive;
}

void DroneState::kill()
{
    m_isAlive = false;
}

Compass* DroneState::getCompassPtr()
{
	return &m_compass;
}

void DroneState::setEnergy(unsigned int energy)
{
	m_energy = energy;
}

} // jb