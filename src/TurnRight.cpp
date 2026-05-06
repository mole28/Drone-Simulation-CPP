#include "TurnRight.h"
#include "Compass.h"
#include "OutPutContext.h"

#include <sstream>

namespace jb
{

void TurnRight::execute(const OutPutContext& output) const
{
	turnRight(&m_compass);

	std::stringstream ss;
	ss << "turned right." << m_compass.getHeading() << "\n";

	output.output(ss.str());
}

} // jb