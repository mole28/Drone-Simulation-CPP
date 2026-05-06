#ifndef __CmdTurnLeft_h__
#define __CmdTurnLeft_h__ 

#include "Command.h"

namespace jb
{

class Compass;

class CmdTurnLeft : public Command
{
public:
	CmdTurnLeft(Compass* compass) : m_compass(*compass) 
	{
	}

	virtual void execute(const OutPutContext& output) const override;
	virtual unsigned int getEnergyConsumption() const override;

private:
	Compass& m_compass;
};

} // jb

#endif