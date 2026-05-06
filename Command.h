#ifndef __Command_h__
#define __Command_h__

#include "BaseEssentials.h"

namespace jb 
{

class OutPutContext;

class Command : public BaseEssentials 
{
public:
    virtual ~Command() = default;
    virtual void execute(const OutPutContext& output) const = 0;
    virtual unsigned int getEnergyConsumption() const = 0;
};

}

#endif