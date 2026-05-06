#include "ExitTile.h"

namespace jb 
{

std::string ExitTile::symbol() const 
{
    return "E";
}
bool ExitTile::canOccupy() const
{ 
    return true;
}

}