#include "Position.h"

Position::Position(int x, int y)
    : xpos(x)
    , ypos(y)
{}

void Position::getDistanceTo(int x, int y)
{

}

int Position::getDistanceTo(std::tuple<int, int>(pos)){
    int distance = 0;

    return distance;
}

int Position::getDistanceTo(const Position& p) {
    int distance = 0;

    distance = xpos - p.xpos;

    return distance;
}

int Position::getX() {
    return xpos;
}

int Position::getY() {
    return ypos;
}
