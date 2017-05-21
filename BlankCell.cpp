//
// Created by Dimitar on 21.5.2017 г..
//

#include "BlankCell.h"

BlankCell::BlankCell() {
    content = new char[1];
    content[0] = '\0';
}

std::ostream &BlankCell::Print(std::ostream &os)const {
    os<<"\'\'";
}
