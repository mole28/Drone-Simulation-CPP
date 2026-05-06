#include "CmdScanEnvironment.h"
#include "WorldGrid.h"
#include "Position.h"
#include "Tile.h"
#include "OutPutContext.h"

#include <sstream>

namespace jb
{

CmdScanEnvironment::CmdScanEnvironment(WorldGrid& grid, Position& position, const std::vector<Tile*>& allDrones)
	: m_grid(grid), m_position(position), m_allDrones(allDrones)
{
}

void CmdScanEnvironment::execute(const OutPutContext& output) const
{
	std::stringstream report;
	report << "Scanning environment at (" << m_position.getX() << "," << m_position.getY() << ")\n";

	for (auto drone : m_allDrones)
	{
		if (drone)
		{
			report << "Detected entity at unknown distance.\n";
		}
	}
	output.output(report.str());
}

unsigned int jb::CmdScanEnvironment::getEnergyConsumption() const
{
	return 2; 
}

} // jb