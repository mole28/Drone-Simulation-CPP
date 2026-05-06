#ifndef __Forward_h__
#define __Forward_h__

#include "Command.h"
#include "Position.h"
#include "WorldGrid.h"
#include "OutPutContext.h"
#include "Compass.h"

namespace jb
{

class OutPutContext;

class Forward : public Command
{
public:
	Forward(WorldGrid* grid, Position* pos, Compass& compass);
	virtual void execute(const jb::OutPutContext& output) const override;
	virtual unsigned int getEnergyConsumption() const override { return 0; }

private:
	WorldGrid& m_grid;
	Position& m_position;
	const Compass& m_compass;

	Position advance(const Position& pos, const Compass& compass) const;
};

} // jb

#endif