#include "CmdShowMap.h"

namespace jb
{

void CmdShowMap::execute(const OutPutContext& output) const
{
    if (!m_grid)
    {
            return;
    }
    std::string fullMap = "Full World Map (@ = You, & = Others):\n";
    fullMap += "------\n";
    for (int y = 0; y < m_grid->getHeight(); ++y)
    {
        for (int x = 0; x < m_grid->getWidth(); ++x)
        {
            if (x == m_currentPos.getX() && y == m_currentPos.getY())
            {
                fullMap += " [@] ";
            }
            else
            {
                bool foundOther = false;
                for (const auto& otherPos : m_otherDrones)
                {
                    if (x == otherPos.getX() && y == otherPos.getY())
                    {
                        fullMap += " [&] ";
                        foundOther = true;
                        break;
                    }
                }
                if (!foundOther)
                {
                    fullMap += " " + m_grid->getTile(x, y).symbol() + " ";
                }
            }
        }
        fullMap += "\n";
    }
    fullMap += "------\n";
    output.output(fullMap);
}

unsigned int CmdShowMap::getEnergyConsumption() const
{
    return 20;
}

} //jb