#include "CmdFixedConsumption.h"

namespace jb
{

CmdFixedConsumption::CmdFixedConsumption(Command* cmd, unsigned int energy)
    : m_cmd(cmd), m_energy(energy)
{
}

CmdFixedConsumption::~CmdFixedConsumption()
{
    delete m_cmd;
}

void CmdFixedConsumption::execute(const OutPutContext& output) const
{
    if (m_cmd)
    {
        m_cmd->execute(output);
    }
}

unsigned int CmdFixedConsumption::getEnergyConsumption() const
{
    return m_energy;
}

} // jb