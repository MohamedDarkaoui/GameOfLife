//
// Created by mohamed on 9/6/21.
//

#include "Cell.h"

std::ostream &operator<<(std::ostream &out, Cell& cell) {
    out << cell.getRepresentation();
    return out;
}
