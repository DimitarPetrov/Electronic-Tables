//
// Created by Dimitar on 21.5.2017 г..
//

#include "Cell.h"
#include <iostream>

#include <iostream>
#include <cstring>
#include "Recognition.h"

Cell::Cell(const char *rc) {
    rawContent = new char[strlen(rc) + 1];
    strcpy(rawContent, rc);
    ClearWhitespaces(rawContent);
}

Cell::Cell(const Cell &c) {
    Copy(c);
}

Cell &Cell::operator=(const Cell &c) {
    if(this == &c){
        return *this;
    }
    delete[] rawContent;
    Copy(c);
    return *this;
}

Cell::~Cell() {
    delete[] rawContent;
}

void Cell::Copy(const Cell &c) {
    rawContent = new char[strlen(c.rawContent) + 1];
    strcpy(rawContent, c.rawContent);
    ClearWhitespaces(rawContent);
}


std::ostream& operator<<(std::ostream &os, const Cell &c) {
    return c.Print(os);
}

char *Cell::getRawContent() const {
    return rawContent;
}
