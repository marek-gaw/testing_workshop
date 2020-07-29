#pragma once

#include <string>
#include <vector>

class HackerRankSolution {
public:

    int solve(std::vector<int> data, std::vector<std::vector<int>>& obst);

private:

    int queensAttack(int n, int k, int r_q, int c_q, std::vector<std::vector<int>> obstacles);


};
