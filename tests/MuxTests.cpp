#include <gtest/gtest.h>

#include "../src/mux/Mux.hpp"

TEST(Mux, ctor) {

    ASSERT_EQ(1, 1);
    ASSERT_EQ(2, 2);
}

TEST(Mux, plexerZeroZero) {
    Mux mux;

    std::vector<int> result = mux.plexer(0,1);

    ASSERT_EQ(0, result.at(0));
}
