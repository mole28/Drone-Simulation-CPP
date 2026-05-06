#ifndef __DroneScanner_h__
#define __DroneScanner_h__

#include "Position.h"
#include "Command.h"
#include "TheSensor.h"
#include "DroneTile.h"

#include <vector>

namespace jb
{

class WorldGrid;
class Tile;
class OutPutContext;

class DroneScanner : public Command
{
public:
    DroneScanner(const WorldGrid* grid, const Position* position, const Compass* compass,
        const TheSensor* sensor, const std::vector<Position>& allDrones);

    virtual void execute(const OutPutContext& output) const override;
    virtual unsigned int getEnergyConsumption() const override;

    class Iterator;

    static constexpr int SizeOfPovFront = 2;
    static constexpr int SizeOfPovBack = 1;
    static constexpr int SizeOfPovLeft = 1;
    static constexpr int SizeOfPovRight = 1;

private:
    Iterator begin() const;
    Iterator end() const;

    const WorldGrid& m_grid;
    const Position& m_position;
    const Compass& m_compass;
    const TheSensor* m_sensor;
    const std::vector<Position>& m_allDrones;

    char extractTileChar(const Tile* tile) const;
    Position m_fwd_vec;
    Position m_right_vec;
    Position calculateTargetPosition(int row, int col) const;
    char determineSymbol(const Tile* tile, int row, int col) const;

    static constexpr char SYMBOL_EGO = 'E';
};

class DroneScanner::Iterator
{
public:
    Iterator(const WorldGrid& grid, Position currentCoordinate,
        Position fwd, Position right, int row, int col);

    const Tile* operator*() const;
    Iterator& operator++();
    bool operator!=(const Iterator& other) const;

private:
    const WorldGrid& m_grid;
    Position m_currentCoordinate;
    Position m_fwd;
    Position m_right;
    int m_row;
    int m_col;
};

} // jb

#endif