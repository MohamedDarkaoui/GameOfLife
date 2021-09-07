//
// Created by mohamed on 9/6/21.
//

#ifndef GAMEOFLIFE_DEADCELL_H
#define GAMEOFLIFE_DEADCELL_H

#include "Cell.h"

class DeadCell : public Cell{
private:
    std::string getRepresentation() override;

public:
    ~DeadCell() override = default;

    bool getValue() override;
};


#endif //GAMEOFLIFE_DEADCELL_H
