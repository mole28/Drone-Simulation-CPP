#include "WorldGrid.h"
#include "EmptyTile.h"
#include "WallTile.h"
#include "ExitTile.h"
#include "DroneTile.h"

namespace jb
{
const EmptyTile WorldGrid::EMPTY{};
const WallTile  WorldGrid::WALL{};
const ExitTile  WorldGrid::EXIT{};
const DroneTile WorldGrid::OTHER{};

WorldGrid::WorldGrid()
    : m_grid{}
{
    m_grid[0][0] = (Tile*)&WALL;
    m_grid[1][1] = (Tile*)&WALL;
    m_grid[2][2] = (Tile*)&WALL;
    m_grid[3][3] = (Tile*)&WALL;
    m_grid[4][0] = (Tile*)&WALL;
    m_grid[4][3] = (Tile*)&WALL;
    m_grid[5][1] = (Tile*)&WALL;
    m_grid[5][4] = (Tile*)&EXIT;

}

Tile& WorldGrid::getTile(int x, int y) const
{
    if (!isInBounds(x, y))
    {
        return (Tile&)WALL;
    }

    Tile* tile = m_grid[y][x];

    return tile ? *tile : (Tile&)EMPTY;
}

bool WorldGrid::isInBounds(int x, int y) const
{
    return (x >= 0 && x < static_cast<int>(ROW_SIZE) &&
        y >= 0 && y < static_cast<int>(NUM_ROWS));
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