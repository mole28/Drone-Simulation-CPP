#ifndef __WallTile_h__
#define __WallTile_h__

#include "Tile.h"

namespace jb
{

class WallTile : public Tile
{
public:
	virtual bool canOccupy() const override;
	virtual std::string symbol() const override;

private:
};

} // jb

#endif