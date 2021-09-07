//
// Created by mohamed on 9/6/21.
//

#ifndef GAMEOFLIFE_GAME_H
#define GAMEOFLIFE_GAME_H

#include "Grid.h"
#include <functional>
#include <utility>
#include "AliveCell.h"
#include "DeadCell.h"
#include <unistd.h>

template<unsigned int ROW, unsigned int COL>
class Game {
private:
    std::function<bool (bool, int)> rule;
    unsigned int iterations;
    Grid<ROW, COL> grid{};

public:
    Game(std::function<bool(bool,int)>  rule, unsigned int iterations);

    void live();

    Game<ROW,COL>& operator[](std::array<int,2>);
};




#endif //GAMEOFLIFE_GAME_H
