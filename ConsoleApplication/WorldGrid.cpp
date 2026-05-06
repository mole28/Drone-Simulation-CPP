#include "WorldGrid.h"
#include "EmptyTile.h"
#include "WallTile.h"
#include "ExitTile.h"
#include "DroneTile.h"

namespace jb
{

EmptyTile WorldGrid::EMPTY{};
WallTile  WorldGrid::WALL{};
ExitTile  WorldGrid::EXIT{};
DroneTile WorldGrid::OTHER{};

WorldGrid::WorldGrid() 
	: m_grid{} 
{                                        // =======  
	m_grid[0][0] = &WALL;                // = #   =
	m_grid[1][1] = &WALL;                // = #   =
	m_grid[2][2] = &WALL;                // =  #  =   |
	m_grid[3][3] = &WALL;                // =   # =   |
	m_grid[4][0] = &WALL;			     // =#   #=  \|/
	m_grid[4][3] = &WALL;		         // = #  E=   N
	m_grid[5][1] = &WALL;				 // =======
	m_grid[5][4] = &EXIT;  
}

Tile &WorldGrid::getTile(int x, int y) const
{
	if (x < 0 || y < 0 || x >= static_cast<int>(ROW_SIZE) || y >= static_cast<int>(NUM_ROWS))
	{
		return WALL;
	}

	Tile *tile = m_grid[y][x];
	return tile ? *tile : EMPTY;
}

int WorldGrid::getWidth() const 
{ 
	return static_cast<int>(ROW_SIZE);
}

int WorldGrid::getHeight() const 
{ 
	return static_cast<int>(NUM_ROWS); 
}

} // jb
