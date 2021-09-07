//
// Created by mohamed on 9/6/21.
//

#ifndef GAMEOFLIFE_ALIVECELL_H
#define GAMEOFLIFE_ALIVECELL_H

#include "Cell.h"

class AliveCell : public Cell{

private:
    std::string getRepresentation() override;

public:
    ~AliveCell() override = default;

    bool getValue() override;

};


#endif //GAMEOFLIFE_ALIVECELL_H
