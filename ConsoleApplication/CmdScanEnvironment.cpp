#include "CmdScanEnvironment.h"
#include "WorldGrid.h"
#include "Tile.h"

#include <sstream>

namespace jb
{

    CmdScanEnvironment::CmdScanEnvironment(const WorldGrid* grid, const Position* position, const std::vector<Position>& allDrones)
    : m_grid(*grid), m_position(*position), m_allDrones(allDrones)
{
}

void CmdScanEnvironment::execute(const OutPutContext& output) const
{
    std::stringstream report;
    report << "Map View:\n";    

    for (int y = 0; y < m_grid.getHeight(); ++y)
    {
        for (int x = 0; x < m_grid.getWidth(); ++x)
        {
            if (isTileOccupiedByDrone(x, y))
            {
                report << "[D] ";
            }
            else
            {
                report << m_grid.getTile(x, y).symbol() << " ";
            }
        }
        report << "\n";
    }
    output.output(report.str());
}

bool CmdScanEnvironment::isTileOccupiedByDrone(int x, int y) const
{
    if (x == m_position.getX() && y == m_position.getY())
    {
        return true;
    }

    for (std::vector<Position>::const_iterator it = m_allDrones.begin();
        it != m_allDrones.end();
        ++it)
    {
        if (it->getX() == x && it->getY() == y)
        {
            return true;
        }
    }
    return false;
}

unsigned int CmdScanEnvironment::getEnergyConsumption() const
{ 
     return 0; 
}

} // jb  