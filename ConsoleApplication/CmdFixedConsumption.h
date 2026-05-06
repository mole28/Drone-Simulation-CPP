#ifndef __CmdFixedConsumption_h__
#define __CmdFixedConsumption_h__

#include "Cmd/Command.h"

namespace jb 
{

class CmdFixedConsumption : public Command 
{
public:
    CmdFixedConsumption(Command* cmd, unsigned int energy);

    virtual ~CmdFixedConsumption();
    virtual void execute(const OutPutContext& output) const override;
    virtual unsigned int getEnergyConsumption() const override;

private:
    Command* m_cmd;
    unsigned int m_energy;
};

} // jb

#endif