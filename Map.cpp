#include "Map.h"
#include "WorldGrid.h"
#include "Tile.h"
#include "OutputContext.h"

#include <sstream>

namespace jb
{
CmdMap::CmdMap(const WorldGrid* grid) : m_grid(*grid)
{
}

void CmdMap::execute(const OutputContext& output) const
{
    std::stringstream ss;
    ss << "Map View:\n";

    for (int y = 0; y < m_grid.getHeight(); ++y)
    {
        for (int x = 0; x < m_grid.getWidth(); ++x)
        {
            ss << m_grid.getTile(x, y).symbol() << " ";
        }
        ss << "\n";
    }

    output.output(ss.str());
}
} // jb