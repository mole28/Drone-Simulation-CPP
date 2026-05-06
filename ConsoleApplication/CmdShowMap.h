#ifndef __CmdShowMap_h__
#define __CmdShowMap_h__

#include "Cmd/Command.h"
#include "WorldGrid.h"
#include "Tile.h"
#include "Position.h"


namespace jb
{

class CmdShowMap : public Command
{
public:
    CmdShowMap(const WorldGrid* grid,
        const Position& currentPos,
        const std::vector<Position>& others)
        : m_grid(grid), m_currentPos(currentPos), m_otherDrones(others) {
    }

    virtual void execute(const OutPutContext& output) const override;
    unsigned int getEnergyConsumption() const;

    const WorldGrid* m_grid;
    Position m_currentPos;
	std::vector<Position> m_otherDrones;

private:
};

} //jb

#endif