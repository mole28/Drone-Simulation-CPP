#ifndef __CmdForward_h__
#define __CmdForward_h__

#include "Command.h"
#include "../WorldGrid.h"
#include "../Position.h"
#include "../Compass.h"

namespace jb
{

class CmdForward : public Command
{
public:
	CmdForward(const WorldGrid* grid, Position* position, const Compass* compass)
		: m_grid(*grid), m_position(*position), m_compass(*compass)
	{
	}

	virtual void execute(const OutPutContext& output) const override;
	virtual unsigned int getEnergyConsumption() const override;

private:
	const WorldGrid& m_grid;
	Position& m_position;
	const Compass& m_compass;
};

} // jb

#endif