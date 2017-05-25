//
// Created by Dimitar on 25.5.2017 г..
//

#include "Spreadsheet.h"

Spreadsheet::Spreadsheet() {
    sheet = new SRow[10];
    capacity = 10;
    current = 0;
}

Spreadsheet::Spreadsheet(const Spreadsheet &ss) {
    Copy(ss);
}

Spreadsheet &Spreadsheet::operator=(const Spreadsheet &ss) {
    if(this == &ss){
        return *this;
    }
    delete[]sheet;
    Copy(ss);
    return *this;
}

Spreadsheet::~Spreadsheet() {
    delete[]sheet;
}

void Spreadsheet::add(const SRow &sr) {
    if(capacity == current){
        resize();
    }
    sheet[current] = sr;
    ++current;
}

void Spreadsheet::Copy(const Spreadsheet &ss) {
    capacity = ss.capacity;
    current = ss.current;
    sheet = new SRow[capacity];
    for(int i = 0; i<current; ++i){
        sheet[i] = ss.sheet[i];
    }
}

void Spreadsheet::resize() {
    SRow* tmp = sheet;
    sheet = new SRow[2*capacity];
    capacity*=2;
    for(int i = 0; i<current; ++i){
        sheet[i] = tmp[i];
    }
    delete[] tmp;
}

std::ostream& operator<<(std::ostream& os, const Spreadsheet& ss){
    for(int i = 0; i<ss.current; ++i){
        os<<ss.sheet[i]<<std::endl;
    }
    return os;
}
