#include "Execute.h"
#include "Command.h"

namespace jb
{

Execute::Execute(Command* toExecute) : m_toExecute(toExecute) 
{
}

Execute::~Execute() 
{
    delete m_toExecute;
}

void Execute::execute(const OutPutContext& output) const
{
    if (m_toExecute) m_toExecute->execute(output);
}

unsigned int Execute::getEnergyConsumption() const 
{
    return m_toExecute ? m_toExecute->getEnergyConsumption() : 0;
}

}