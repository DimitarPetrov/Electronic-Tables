//
// Created by Dimitar on 25.5.2017 г..
//

#include "IntCell.h"
#include <stdlib.h>


IntCell::IntCell(const char *c):Cell(c){
    content = formatFix(c);
}

std::ostream &IntCell::Print(std::ostream &os) const {
    return os<<content;
}

int IntCell::formatFix(const char *c) {
    return atoi(c);
}

Cell *IntCell::Clone() const {
    return new IntCell(rawContent);
}


