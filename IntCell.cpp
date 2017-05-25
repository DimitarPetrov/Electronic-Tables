//
// Created by Dimitar on 25.5.2017 г..
//

#include "IntCell.h"


IntCell::IntCell(const char *rc) : Cell(rc) {
    content =
}

std::ostream &IntCell::Print(std::ostream &os) const {
    return Cell::Print(os);
}

int IntCell::formatFix(const char *rc) {

}
