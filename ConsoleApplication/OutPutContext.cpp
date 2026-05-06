#include "OutPutContext.h"

namespace jb
{
void OutPutContext::output(const std::string& str) const
{
	m_nh.PutOutput(m_socketId, str);
}
}