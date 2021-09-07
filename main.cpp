#include <iostream>
#include "Grid.cpp"
#include "AliveCell.h"
#include "DeadCell.h"
#include "Game.cpp"

int main() {

    try {
        std::function<bool(bool, int)> rule = [](bool isAlive, int nrNeighbors) {
            if (isAlive) {
                if (nrNeighbors == 2 || nrNeighbors == 3)
                    return true;
                else if (nrNeighbors == 4 || nrNeighbors < 2)
                    return false;
            } else {
                if (nrNeighbors == 3)
                    return true;
            }
            return false;
        };

        Game<15, 30> game(rule, 500);
        game[std::array<int, 2>{7, 14}]; // initialize alive cell at (7 , 14)
        game[{7, 15}]; // initialize alive cell at (7 , 15)
        game[{7, 16}]; // initialize alive cell at (7 , 16)
        game[{7, 17}]; // initialize alive cell at (7 , 17)
        game[{7, 18}]; // initialize alive cell at (7 , 18)


        game.live();
    }
    catch(std :: out_of_range &e){
        std::cout<<e.what()<<std::endl ;
    }
}
