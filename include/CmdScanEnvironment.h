#ifndef __CmdScanEnvironment_h__
#define __CmdScanEnvironment_h__

#include "Command.h"
#include "OutPutContext.h"

#include <vector>

namespace jb
{

class WorldGrid;
class Position;
class Tile;
class OutPutContext;

class CmdScanEnvironment : public Command
{
public:
	CmdScanEnvironment(WorldGrid& grid, Position& position, const std::vector<Tile*>& allDrones);

	virtual void execute(const OutPutContext& output) const override;
	virtual unsigned int getEnergyConsumption() const override;

private:
	WorldGrid& m_grid;
	Position& m_position;
	const std::vector<Tile*>& m_allDrones;
};

} // jb

#endif