#ifndef __ExitTile_h__
#define __ExitTile_h__

#include "Tile.h"

namespace jb
{

class ExitTile : public Tile 
{
public:
	ExitTile() : Tile(EXIT) 
	{ 
	}
	virtual bool canOccupy() const;
	virtual std::string symbol() const override;

private:
};

} // jb

#endif
