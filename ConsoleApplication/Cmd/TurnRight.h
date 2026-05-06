#ifndef __CmdTurnRight_h__
#define __CmdTurnRight_h__

#include "Command.h"

namespace jb
{

class Compass;

class CmdTurnRight : public Command
{
public:
	CmdTurnRight(Compass* compass) : m_compass(*compass)
	{
	}

	virtual void execute(const OutPutContext& output) const override;
	virtual unsigned int getEnergyConsumption() const override;

private:
	Compass& m_compass;
};

} // jb

#endif