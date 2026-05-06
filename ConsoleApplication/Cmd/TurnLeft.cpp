#include "TurnLeft.h"
#include "../Compass.h"

#include <sstream>

namespace jb
{

void CmdTurnLeft::execute(const OutPutContext& output) const
{
	turnLeft(&m_compass);

	std::stringstream report;
	report << "turned left." << m_compass.getHeading() << "\n";

	output.output(report.str());
}

unsigned int CmdTurnLeft::getEnergyConsumption() const 
{ 
	return 5; 
}

} // jb