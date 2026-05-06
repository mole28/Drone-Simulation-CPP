#ifndef __Position_h__
#define __Position_h__

#include "Compass.h"

namespace jb
{

class Position
{
public:
	Position(int x, int y) : m_x(x), m_y(y) 
	{
	}

	Position(const Position& other) = default;
	Position& operator=(const Position& other) = default;
	~Position() = default;

	int getX() const;
	int getY() const;

private:
	int m_x;
	int m_y;
};

Position advance(const Position& currentLocation, const Compass& heading);

} // jb

#endif
