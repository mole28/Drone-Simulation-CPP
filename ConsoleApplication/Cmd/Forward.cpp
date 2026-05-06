#include "Forward.h"
#include "../Tile.h"

#include <sstream>

namespace jb
{

void CmdForward::execute(const OutPutContext& output) const
{
    Position newPosition = advance(m_position, m_compass);
    std::stringstream report;

    if (m_grid.getTile(newPosition.getX(), newPosition.getY()).canOccupy())
    {
        report << "forward\n";
        m_position = newPosition;
    }
    else
    {
        report << "Blocked: Cannot move forward\n";
    }

    output.output(report.str());
}

unsigned int CmdForward::getEnergyConsumption() const
{ 
    return 10;
}

} // jb