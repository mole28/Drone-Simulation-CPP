#ifndef __EmptyTile_h__
#define __EmptyTile_h__

#include "Tile.h"

namespace jb
{

class EmptyTile : public Tile 
{
public:
	virtual bool canOccupy() const;
	virtual std::string symbol() const override;

private:
};

} // jb

#endif
