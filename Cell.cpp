//
// Created by Dimitar on 21.5.2017 г..
//

#include "Cell.h"
#include <iostream>
#include <cstring>

Cell::Cell(const char *c) {
    content = new char[strlen(c) + 1];
    strcpy(content, c);
}

Cell::Cell(const Cell &c) {
    Copy(c);
}

Cell &Cell::operator=(const Cell &c) {
    if(this == &c){
        return *this;
    }
    delete[] content;
    Copy(c);
    return *this;
}

Cell::~Cell() {
    delete[] content;
}

void Cell::Copy(const Cell &c) {
    content = new char[strlen(c.content) + 1];
    strcpy(content, c.content);
}

std::ostream &Cell::Print(std::ostream &os) const {
    os<<"Content: "<<content;
    return os;
}


std::ostream& operator<<(std::ostream &os, const Cell &c) {
    return c.Print(os);
}

const char *Cell::getContent() const {
    return content;
}
