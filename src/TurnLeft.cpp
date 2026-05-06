#include "TurnLeft.h"
#include "Compass.h"
#include "OutPutContext.h"

#include <sstream>

namespace jb
{

void TurnLeft::execute(const OutPutContext& output) const
{
turnLeft(&m_compass);

std::stringstream ss;
ss << "turned left." << m_compass.getHeading() << "\n";

output.output(ss.str());
}

} // jb