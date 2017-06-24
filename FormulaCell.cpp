//
// Created by Dimitar on 25.5.2017 г..
//

#include "FormulaCell.h"
#include <cstring>
#include "Recognition.h"

FormulaCell::FormulaCell(const char *c) : Cell(c) {

}

std::ostream &FormulaCell::Print(std::ostream &os) const {
    return os << rawContent;
}

Cell *FormulaCell::Clone() const {
    return new FormulaCell(rawContent);
}

FormulaCell::~FormulaCell() {

}

