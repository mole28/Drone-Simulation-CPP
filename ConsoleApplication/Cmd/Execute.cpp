#include "Execute.h"
#include "../OutPutContext.h"

namespace jb
{

void CmdExecute::execute(const OutPutContext& output) const
{
	m_toExecute();
}

unsigned int CmdExecute::getEnergyConsumption() const 
{
	return 0;
}

} // jb