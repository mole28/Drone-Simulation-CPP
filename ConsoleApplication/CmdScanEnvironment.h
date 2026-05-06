#ifndef __CmdScanEnvironment_h__
#define __CmdScanEnvironment_h__

#include "Cmd/Command.h"
#include "Position.h"

namespace jb
{

class WorldGrid;

class CmdScanEnvironment : public Command
{
public:
    CmdScanEnvironment(const WorldGrid* grid, const Position* position,
                       const std::vector<Position>& allDrones);

    virtual void execute(const OutPutContext& output) const override;
    virtual unsigned int getEnergyConsumption() const override;

private:
    const WorldGrid& m_grid;
    const Position& m_position;
    const std::vector<Position>& m_allDrones;
    bool isTileOccupiedByDrone(int x, int y) const;
};

} // jb

#endif