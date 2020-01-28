#include <gtest/gtest.h>

#include "../src/position/Position.h"

TEST(Position, Getter) {
    Position p(1,2);

    ASSERT_EQ(1, p.getX());
    ASSERT_EQ(2, p.getY());
}

TEST(Position, Distance) {
    Position p1(0,0);
    Position p2(3,4);

    ASSERT_EQ(5, p1.getDistanceTo(p2));
    ASSERT_EQ(5, p2.getDistanceTo(p1));
}
