#ifndef __CmdExecute_h__
#define __CmdExecute_h__

#include "Command.h"

#include <functional>

namespace jb
{

class CmdExecute : public Command
{
public:
	explicit CmdExecute(std::function<void()> toExecute)
		: m_toExecute(std::move(toExecute)) 
	{
	}

	virtual void execute(const OutPutContext& output) const override;
	virtual unsigned int getEnergyConsumption() const override;

private:
	std::function<void()> m_toExecute;
};

} // jb

#endif
