#ifndef __ExitTile_h__
#define __ExitTile_h__

#include "Tile.h"

namespace jb
{

class ExitTile : public Tile
{
public:
	virtual bool canOccupy() const override;
	virtual std::string symbol() const override;

private:
};

} // jb

#endif