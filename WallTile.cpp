#include "WallTile.h"

namespace jb 
{

std::string WallTile::symbol() const 
{
    return "#";
}
bool WallTile::canOccupy() const
{ 
    return false; 
}

}