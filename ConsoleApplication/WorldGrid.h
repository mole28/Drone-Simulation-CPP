#ifndef __WorldGrid_h__
#define __WorldGrid_h__

#include <array>

namespace jb
{

class EmptyTile;
class WallTile;
class ExitTile;
class DroneTile;
class Tile;

class WorldGrid
{
public:
	WorldGrid();

	Tile& getTile(int x, int y) const;

	int getWidth() const;
	int getHeight() const;

	static EmptyTile EMPTY;
	static WallTile  WALL;
	static ExitTile  EXIT;
	static DroneTile OTHER;

private:
	static constexpr size_t ROW_SIZE = 5;
	static constexpr size_t NUM_ROWS = 6;

	using Row = std::array<Tile*, ROW_SIZE>;
	using Grid = std::array<Row, NUM_ROWS>;

	Grid m_grid;
};

} // jb

#endif