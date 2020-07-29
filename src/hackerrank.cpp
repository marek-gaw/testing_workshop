#include "include/hackerrank.hpp"
#include <iostream>
#include <algorithm>

#include <fmt/core.h>
#include <fmt/ranges.h>

int HackerRankSolution::queensAttack(int n, int k, int r_q, int c_q, std::vector<std::vector<int>> obstacles) {

    int no_of_moves = 0;
    std::vector<std::pair<int,int>> directions = {{-1,-1},
                                                  {-1,0},
                                                  {-1,1},
                                                  {0,-1},
                                                  {0,1},
                                                  {1,-1},
                                                  {1,0},
                                                  {1, 1}};

    for (const auto& dir : directions) {
        fmt::print("Checking direction:{}\n", dir);
        int row = r_q + dir.first;
        int col = c_q + dir.second;
        bool obstacle_hit = false;

        while ( (row <= n) && (row > 0) &&
                (col > 0) && (col <= n) && !obstacle_hit) {
            fmt::print("Checking position r:{},c:{}\n", row, col );

            for (const auto& o : obstacles) {
                if(o.at(0) == row && o.at(1) == col) {
                    fmt::print("Obstacle hit at r:{},c:{}\n", row, col);
                    obstacle_hit = true;
                    break;
                };
            }
            if(obstacle_hit) {
                fmt::print("No need to check this direction further\n");
                break;
            }

            fmt::print("Move possible\n");
            row+=dir.first;
            col+=dir.second;
            no_of_moves++;
        }
    }

    fmt::print("Number of moves:{}\n", no_of_moves);
    return no_of_moves;
}

int HackerRankSolution::solve(std::vector<int> data, std::vector<std::vector<int>>& obst)
{
    fmt::print("size:{}, no of obstacles:{}, queen r:{}, queen c:{}\n",data.at(0), data.at(1), data.at(2), data.at(3));

    for(const auto& i : obst) {
        fmt::print("{}\n", i);
    }

    return queensAttack(data.at(0), data.at(1), data.at(2), data.at(3), obst);
}


