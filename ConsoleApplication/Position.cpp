#include "Position.h"

#include <map>

namespace jb
{

struct PositionDelta
{
	int deltaX;
	int deltaY;
};

int Position::getX() const
{ 
	return m_x;
}

int Position::getY() const
{ 
	return m_y;
}

using DeltasMap = std::map<Compass, const PositionDelta>;
static const DeltasMap DELTAS 
{ 
	{ NORTH, { 0,  1 } }, 
	{ EAST,  { 1,  0 } }, 
	{ SOUTH, { 0, -1 } }, 
	{ WEST,  { -1, 0 } }
};

Position advance(const Position &currentLocation, const Compass &heading)
{
	DeltasMap::const_iterator deltaItr = DELTAS.find(heading);
	if (deltaItr == DELTAS.end())
	{
		throw std::exception{"Unprocessable compass heading"};
	}
	return Position(currentLocation.getX() + deltaItr->second.deltaX, currentLocation.getY() + deltaItr->second.deltaY);
}

} // jb
