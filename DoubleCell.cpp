//
// Created by Dimitar on 25.5.2017 г..
//

#include "DoubleCell.h"
#include <stdlib.h>

DoubleCell::DoubleCell(const char *c):Cell(c) {
    content = formatFix(c);
}

std::ostream &DoubleCell::Print(std::ostream &os) const {
    return os<<content;
}

double DoubleCell::formatFix(const char *c) {
    return atof(c);
}

Cell *DoubleCell::Clone() const {
    return new DoubleCell(rawContent);
}

double DoubleCell::getContent() const {
    return content;
}

DoubleCell::DoubleCell(double a):Cell(""), content(a) {

}
