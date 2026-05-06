#ifndef __Execute_h__
#define __Execute_h__

#include "Command.h"

namespace jb 
{

class OutPutContext;

class Execute : public Command 
{
public:
    Execute(Command* toExecute);
    virtual ~Execute();
    virtual void execute(const OutPutContext& output) const override;
    virtual unsigned int getEnergyConsumption() const override;

private:
    Command* m_toExecute;
};

}

#endif