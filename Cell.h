//
// Created by mohamed on 9/6/21.
//

#ifndef GAMEOFLIFE_CELL_H
#define GAMEOFLIFE_CELL_H

#include <string>

class Cell {
private:
    virtual std::string getRepresentation() = 0;

public:
    virtual ~Cell() = default;

    virtual bool getValue() = 0;


    friend std::ostream& operator <<(std::ostream& out, Cell& cell);
};



#endif //GAMEOFLIFE_CELL_H
