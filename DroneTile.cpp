#include "DroneTile.h"
        
namespace jb
{

bool DroneTile::canOccupy() const
{
    return false;
}

std::string DroneTile::symbol() const
{
    return "D";
}

}