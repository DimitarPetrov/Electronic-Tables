//
// Created by Dimitar on 21.5.2017 г..
//

#include "BlankCell.h"

BlankCell::BlankCell(const char* c):Cell(c) {
    formatFix(c);
}

void BlankCell::formatFix(const char *c) {
    content[0] = ' ';
}

std::ostream &BlankCell::Print(std::ostream &os) const {
    return os<<content;
}

Cell *BlankCell::Clone() const {
    return new BlankCell();
}

const char *BlankCell::getContent() const {
    return content;
}
