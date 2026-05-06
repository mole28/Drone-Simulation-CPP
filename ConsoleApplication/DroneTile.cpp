#include "DroneTile.h"

namespace jb
{

std::string DroneTile::symbol() const
{
    return "[D]";
}

bool DroneTile::canOccupy() const
{ 
    return false;
}

} //jb