#ifndef __DroneTile_h__
#define __DroneTile_h__

#include "Tile.h"

namespace jb
{

class DroneTile : public Tile
{
public:
    virtual bool canOccupy() const override;
    virtual std::string symbol() const override;
};

} // jb

#endif