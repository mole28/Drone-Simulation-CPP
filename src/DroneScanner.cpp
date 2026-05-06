#include "DroneScanner.h"
#include "WorldGrid.h"
#include "EmptyTile.h"
#include "WallTile.h"
#include "ExitTile.h"
#include "DroneTile.h"
#include "OutPutContext.h"


#include <sstream>

namespace jb
{

DroneScanner::DroneScanner(const WorldGrid* grid, const Position* position, const Compass* compass,
    const TheSensor* sensor, const std::vector<Position>& allDrones) :
    m_grid(*grid), m_position(*position), m_compass(*compass), m_sensor(sensor),
    m_allDrones(allDrones), m_fwd_vec(0, 0), m_right_vec(0, 0)
{
    Position zero(0, 0);
    m_fwd_vec = advance(zero, m_compass);
    m_right_vec = advance(zero, m_compass.roatateInStepsOf90(1));
}

DroneScanner::Iterator::Iterator(const WorldGrid& grid, Position currentCoordinate,
    Position fwd, Position right, int row, int col)
    : m_grid(grid), m_currentCoordinate(currentCoordinate), m_fwd(fwd),
    m_right(right), m_row(row), m_col(col)
{
}

void DroneScanner::execute(const OutPutContext& output) const
{
    std::stringstream report;
    report << "POV view:\n";
    const int width = SizeOfPovLeft + SizeOfPovRight + 1;

    int current_col_idx = 0;
    for (Iterator it = begin(); it != end(); ++it)
    {
        int row = SizeOfPovFront - (current_col_idx / width);
        int col = -SizeOfPovLeft + (current_col_idx % width);
        report << "[" << determineSymbol(*it, row, col) << "] ";
        if (++current_col_idx % width == 0)
        {
            report << "\n";
        }
    }
    output.output(report.str());
}

char DroneScanner::determineSymbol(const Tile* tile, int row, int col) const
{
    if (row == 0 && col == 0)
    {
        return SYMBOL_EGO;
    }
    Position targetPos = calculateTargetPosition(row, col);
    for (const Position& dronePos : m_allDrones)
    {
        if (dronePos.getX() == targetPos.getX() && dronePos.getY() == targetPos.getY())
        {
            return WorldGrid::OTHER.symbol()[1];
        }
    }
    return extractTileChar(tile);
}

char DroneScanner::extractTileChar(const Tile* tile) const
{
    if (tile)
    {
        if (tile == (Tile*)&WorldGrid::WALL)
        {
            return WorldGrid::WALL.symbol()[1];
        }
        if (tile == (Tile*)&WorldGrid::EXIT)
        {
            return WorldGrid::EXIT.symbol()[1];
        }
        if (tile == (Tile*)&WorldGrid::EMPTY)
        {
            return WorldGrid::EMPTY.symbol()[1];
        }
        return tile->symbol()[1];
    }
    return ' ';
}

Position DroneScanner::calculateTargetPosition(int row, int col) const
{
    int targetX = m_position.getX() + (row * m_fwd_vec.getX()) + (col * m_right_vec.getX());
    int targetY = m_position.getY() + (row * m_fwd_vec.getY()) + (col * m_right_vec.getY());
    return Position(targetX, targetY);
}

const Tile* DroneScanner::Iterator::operator*() const
{
    int targetX = m_currentCoordinate.getX() + (m_row * m_fwd.getX()) + (m_col * m_right.getX());
    int targetY = m_currentCoordinate.getY() + (m_row * m_fwd.getY()) + (m_col * m_right.getY());
    return &m_grid.getTile(targetX, targetY);
}

DroneScanner::Iterator& DroneScanner::Iterator::operator++()
{
    ++m_col;
    if (m_col > DroneScanner::SizeOfPovRight)
    {
        m_col = -DroneScanner::SizeOfPovLeft;
        --m_row;
    }
    return *this;
}

bool DroneScanner::Iterator::operator!=(const Iterator& other) const
{
    return (m_row != other.m_row || m_col != other.m_col);
}

DroneScanner::Iterator DroneScanner::begin() const
{
    return Iterator(m_grid, m_position, m_fwd_vec, m_right_vec, SizeOfPovFront, -SizeOfPovLeft);
}

DroneScanner::Iterator DroneScanner::end() const
{
    return Iterator(m_grid, m_position, m_fwd_vec, m_right_vec, -SizeOfPovBack - 1, -SizeOfPovLeft);
}

unsigned int jb::DroneScanner::getEnergyConsumption() const 
{
    if (!m_sensor)
    {
        return 0;
    }
    return m_sensor->getEnergyCost();
}

} // jb