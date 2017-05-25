//
// Created by Dimitar on 21.5.2017 г..
//

#include "Cell.h"
#include <iostream>
#include <cstring>

Cell::Cell(const char *rc) {
    rawContent = new char[strlen(rc) + 1];
    strcpy(rawContent, rc);
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
}

std::ostream &Cell::Print(std::ostream &os) const {
    os<<"rawContent: "<<rawContent;
    return os;
}


std::ostream& operator<<(std::ostream &os, const Cell &c) {
    return c.Print(os);
}

const char *Cell::getContent() const {
    return rawContent;
}

void Cell::setContent(const char *rc) {
    delete[] rawContent;
    rawContent = new char[strlen(rc) + 1];
    strcpy(rawContent, rc);
}
