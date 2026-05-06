#ifndef __CmdFixeConsumption_h__
#define __CmdFixeConsumption_h__

#include "Command.h"
#include "OutPutContext.h"

namespace jb
{

class CmdFixeConsumption : public Command 
{
public:
    CmdFixeConsumption(Command* realCommand, unsigned int fixedCost)
        : m_realCommand(realCommand), m_fixedCost(fixedCost) 
    {
    }

    virtual ~CmdFixeConsumption() override 
    {
        if (m_realCommand) {
            delete m_realCommand;
        }
    }

    virtual void execute(const jb::OutPutContext& output) const override 
    {
        if (m_realCommand) {
            m_realCommand->execute(output);
        }
    }

    virtual unsigned int getEnergyConsumption() const override 
    {
        return m_fixedCost;
    }

private:
    Command* m_realCommand;
    unsigned int m_fixedCost;
};

}

#endif