//
// Created by mohamed on 9/6/21.
//

#include <vector>
#include "Grid.h"

template<unsigned int ROW, unsigned int COL>
void Grid<ROW, COL>::gridObject(unsigned int row, unsigned int col, std::unique_ptr<Cell> cell_ptr) {
    if (row > ROW-1 || col > COL-1)
        throw std::out_of_range("Index for grid out of range.");

    grid[row][col] = std::move(cell_ptr);
}

template<unsigned int ROW, unsigned int COL>
void Grid<ROW, COL>::print() {
    for ( auto& row : grid ) {
        for (auto& elem : row )
            std::cout<< *elem ;
        std :: cout << std :: endl ;
    }
}

template<unsigned int ROW, unsigned int COL>
unsigned int Grid<ROW, COL>::getNrAliveNeighbors(unsigned int row, unsigned int col) {
    unsigned int nrAliveNeighbors = 0;

    if (col >= COL || row >= ROW)
        throw std::out_of_range("row or col out of range in getNrAliveNeighbors");

    std::vector<unsigned int> rows;
    std::vector<unsigned int> cols;

    unsigned int _row, row_, _col, col_;
    if (row == 0) _row = ROW-1; else _row = row-1;
    if (row == ROW-1) row_ = 0; else row_ = row+1;
    if (col == 0) _col = COL-1; else _col = col-1;
    if (col == COL-1) col_ = 0; else col_ = col+1;

    rows = {_row,row,row_};
    cols = {_col,col,col_};

    for(auto r : rows){
        for (auto c : cols){
            if (!(r == row && c == col)) {
                if (grid[r][c]->getValue()) {
                    nrAliveNeighbors++;
                }
            }
        }
    }
    return nrAliveNeighbors;
}

template<unsigned int ROW, unsigned int COL>
std::unique_ptr<Cell>& Grid<ROW, COL>::getCellFromGrid(unsigned int row, unsigned int col) {
    if(row >= ROW || col >= COL)
        throw std::out_of_range("index out of range in getCell");
    return grid[row][col];
}
