#include "Forward.h"
#include "Tile.h"
#include "OutPutContext.h"

#include <sstream>

namespace jb
{

Forward::Forward(WorldGrid* grid, Position* pos, Compass& compass):
    m_grid(*grid), m_position(*pos), m_compass(compass)
{
}

void jb::Forward::execute(const OutPutContext& output) const
{
    Position newPosition = advance(m_position, m_compass);
    std::stringstream report;

    if (m_grid.isInBounds(newPosition.getX(), newPosition.getY()) &&
        m_grid.getTile(newPosition.getX(), newPosition.getY()).canOccupy())
    {
        report << "forward\n";
        m_position = newPosition; 
    }
    else
    {
        report << "blocked\n";
    }
    output.output(report.str());
}

Position Forward::advance(const Position& p, const Compass& c) const
{
    return p; 
}

} // jb