//
// Created by mohamed on 9/6/21.
//

#include "Game.h"

template<unsigned int ROW, unsigned int COL>
void Game<ROW, COL>::live() {
    for(int i = 0; i < iterations; i++){

        usleep(500000);
        system("clear");

        Grid<ROW,COL> grid2;
        grid.print();
        std::cout<<"\n";
        for(int row = 0; row < ROW; row++){
            for(int col = 0; col < COL; col++){
                bool isAlive = grid.getCellFromGrid(row,col)->getValue();
                int nrNeighbors = grid.getNrAliveNeighbors(row,col);

                if (rule(isAlive, nrNeighbors))
                    grid2.gridObject(row, col, std::make_unique<AliveCell>());
                else
                    grid2.gridObject(row, col, std::make_unique<DeadCell>());

            }
        }
        grid = std::move(grid2);
    }
}

template<unsigned int ROW, unsigned int COL>
Game<ROW, COL>::Game(std::function<bool(bool, int)> rule, unsigned int iterations) : rule(std::move(rule)),
iterations(iterations){
    for(int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            grid.gridObject(i,j, std::make_unique<DeadCell>());
        }
    }
}

template<unsigned int ROW, unsigned int COL>
Game<ROW, COL> &Game<ROW, COL>::operator[](std::array<int, 2> arr) {
    grid.gridObject(arr[0],arr[1], std::make_unique<AliveCell>());
    return *this;
}
