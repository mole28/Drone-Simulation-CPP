#ifndef __TurnRight_h__
#define __TurnRight_h__

#include "Command.h"

namespace jb
{

class Compass;

class TurnRight : public Command 
{
public:
	TurnRight(Compass *compass) : m_compass(*compass) { }
	virtual void execute(const jb::OutPutContext& output) const override;
	virtual unsigned int getEnergyConsumption() const override { return 0; }

private:
	Compass &m_compass;
};

} // jb

#endif
