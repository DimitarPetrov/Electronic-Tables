//
// Created by Dimitar on 25.5.2017 г..
//

#include "StringCell.h"
#include <cstring>

StringCell::StringCell(const char *c):Cell(c) {
    char tmp[strlen(c)];
    strcpy(tmp,c);
    content = new char[strlen(formatFix(tmp)) + 1];
    strcpy(content, formatFix(tmp));
}

std::ostream &StringCell::Print(std::ostream &os) const {
    return os<<content;
}

StringCell::~StringCell() {
    delete[] content;
}

const char *StringCell::formatFix(char *c) {
    for(int i = strlen(c)-1; c[i]== ' '; --i){
        c[i] = 0;
    }
    for(int i = 0; i < strlen(c) && c[i] == ' ';){
        for(int j = i; j < strlen(c)-1; ++j){
            c[j] = c[j+1];
        }
        c[strlen(c)-1] = 0;
    }
    return c;
}

StringCell::StringCell(const StringCell &sc):Cell(sc) {
    Copy(sc);
}

StringCell &StringCell::operator=(const StringCell &sc) {
    if(this == &sc){
        return *this;
    }
    delete[]content;
    Cell::operator=(sc);
    Copy(sc);
    return *this;
}

void StringCell::Copy(const StringCell &sc) {
    content = new char[strlen(sc.content) + 1];
    strcpy(content,sc.content);
}

Cell *StringCell::Clone() const {
    return new StringCell(rawContent);
}
