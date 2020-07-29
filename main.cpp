#include "iostream"
#include "include/hackerrank.hpp"

int main()
{
    // exercise: https://www.hackerrank.com/challenges/queens-attack-2/problem
    std::vector<int> sample_data1{5,3,4,3};
    std::vector<std::vector<int>> sample_obstacles1{{5,5}, {4,2}, {2,3}};

    HackerRankSolution hrs;
    hrs.solve(sample_data1, sample_obstacles1);

    return 0;
}
