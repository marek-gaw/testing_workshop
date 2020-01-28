#pragma once

#include <vector>

class Mux {
public:
    Mux() = default;
    void translate();

    /*
     * Multiplexer funtion.
     * Optput is of constant size: 4.
     * Code is in range [0..15]
     */
    std::vector<int> plexer(int code, int input);
};
