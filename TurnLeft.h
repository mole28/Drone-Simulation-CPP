#ifndef __TurnLeft_h__
#define __TurnLeft_h__

#include "Command.h"

namespace jb
{

class Compass;

class TurnLeft : public Command 
{
public:
	TurnLeft(Compass *compass) : m_compass(*compass) { }
	virtual void execute(const jb::OutPutContext& output) const override;
	virtual unsigned int getEnergyConsumption() const override { return 0; }

private:
	Compass &m_compass;
};

} // jb

#endif
