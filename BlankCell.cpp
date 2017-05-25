//
// Created by Dimitar on 21.5.2017 г..
//

#include "BlankCell.h"

BlankCell::BlankCell() {
    setContent();
}

//std::ostream &BlankCell::Print(std::ostream &os)const {
//    os<<content;
//}

void BlankCell::setContent(const char *c) {
    delete[] content;
    content = new char[3];
    content[0] = '\'';
    content[1] = '\'';
    content[2] = '\0';
}
