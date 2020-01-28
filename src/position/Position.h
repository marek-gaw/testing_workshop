#ifndef POSITION_H
#define POSITION_H

#include <tuple>

class Position
{
public:
    Position(int x, int y);
    void getDistanceTo(int x, int y);
    int getDistanceTo(std::tuple<int, int>(pos));
    int getDistanceTo(const Position& p);

    int getX();
    int getY();

private:
    int xpos;
    int ypos;
};

#endif // POSITION_H
