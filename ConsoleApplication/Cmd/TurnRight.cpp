#include "TurnRight.h"
#include "../Compass.h"

#include <sstream>

namespace jb
{

void CmdTurnRight::execute(const OutPutContext& output) const
{
	turnRight(&m_compass);

	std::stringstream report;
	report << "turned right." << m_compass.getHeading() << "\n";

	output.output(report.str());
}

unsigned int CmdTurnRight::getEnergyConsumption() const  
{ 
	return 5;
}

} // jb