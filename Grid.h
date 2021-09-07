//
// Created by mohamed on 9/6/21.
//

#ifndef GAMEOFLIFE_GRID_H
#define GAMEOFLIFE_GRID_H

#include <array>
#include <memory>
#include <stdexcept>
#include <iostream>
#include "Cell.h"


template<unsigned int ROW, unsigned int COL>
class Grid {

private:
    std::array<std::array<std::unique_ptr<Cell>, COL>,ROW> grid;

public:
    void gridObject(unsigned int row, unsigned int col, std::unique_ptr<Cell> cell_ptr);

    unsigned int getNrAliveNeighbors(unsigned int row, unsigned int col);

    std::unique_ptr<Cell>& getCellFromGrid(unsigned int row, unsigned int col);

    void print();
};




#endif //GAMEOFLIFE_GRID_H
