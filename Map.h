#ifndef __Map_h__
#define __Map_h__

#include "Command.h"
#include "OutputContext.h" 

namespace jb
{
class WorldGrid;

class CmdMap : public Command
{
public:
    CmdMap(const WorldGrid* grid);

    virtual void execute(const OutputContext& output) const override;
    virtual unsigned int getEnergyConsumption() const override { return 0; }

private:
    const WorldGrid& m_grid;
};
} // jb
#endif