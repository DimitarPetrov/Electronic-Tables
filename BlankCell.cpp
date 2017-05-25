//
// Created by Dimitar on 21.5.2017 г..
//

#include "BlankCell.h"

BlankCell::BlankCell() {
    formatFix(getContent());
}

void BlankCell::formatFix(const char *rc) {
    content[0] = ',';
    content[1] = ',';
    content[2] = '\0';
}

std::ostream &BlankCell::Print(std::ostream &os) const {
    return os<<content;
}
