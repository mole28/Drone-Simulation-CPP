#ifndef __CmdShowMap_h__
#define __CmdShowMap_h__

#include "Command.h"
#include "OutPutContext.h"
#include "Position.h"

#include <vector>

namespace jb
{

class WorldGrid;
class Tile;

class CmdShowMap : public Command
{
public:
    CmdShowMap(WorldGrid* grid, const Position* currentPos, const std::vector<Position>& others);

    virtual void execute(const OutPutContext& output) const override;
    virtual unsigned int getEnergyConsumption() const override;

private:
    WorldGrid* m_grid;
    const Position* m_currentPos;
    const std::vector<Position>& m_others;
};

}
#endif