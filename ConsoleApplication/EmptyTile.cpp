#include "EmptyTile.h"

namespace jb 
{
std::string EmptyTile::symbol() const
{
    return "[.]";
}

bool EmptyTile::canOccupy() const
{ 
    return true; 
}

}