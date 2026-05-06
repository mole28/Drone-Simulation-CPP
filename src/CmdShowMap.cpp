#include "CmdShowMap.h"
#include "WorldGrid.h"
#include "Position.h"
#include "Tile.h"
#include "OutPutContext.h"

#include <sstream>

namespace jb
{

CmdShowMap::CmdShowMap(WorldGrid* grid, const Position* currentPos, const std::vector<Position>& others)
	: m_grid(grid), m_currentPos(currentPos), m_others(others)
{
}

void CmdShowMap::execute(const OutPutContext& output) const
{
	std::stringstream ss;

	for (int y = 0; y < m_grid->getHeight(); ++y)
	{
		for (int x = 0; x < m_grid->getWidth(); ++x)
		{
			if (x == m_currentPos->getX() && y == m_currentPos->getY())
			{
				ss << "D";
			}
			else
			{
				Tile* tile = &m_grid->getTile(x, y);
				ss << (tile ? tile->symbol() : ".");
			}
		}
		ss << "\n";
	}
	output.output(ss.str());
}

unsigned int CmdShowMap::getEnergyConsumption() const
{
	return 0;
}

} // jb