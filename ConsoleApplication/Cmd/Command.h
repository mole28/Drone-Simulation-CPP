#ifndef __Command_h__
#define __Command_h__

#include "../BaseEssentials.h"
#include "../OutPutContext.h"

namespace jb
{

class Command : private BaseEssentials
{
public:
	virtual ~Command() = default;
	virtual void execute(const OutPutContext& output) const = 0;
	virtual unsigned int getEnergyConsumption() const = 0;

private:
};

} // jb

#endif