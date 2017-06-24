//
// Created by Dimitar on 25.5.2017 г..
//

#include "SRow.h"
#include <cstring>
#include "BlankCell.h"
#include "DoubleCell.h"
#include "IntCell.h"
#include "FormulaCell.h"
#include "StringCell.h"
#include <ctype.h>
#include <fstream>
#include "Recognition.h"

SRow::SRow() {
    row = new Cell* [10];
    capacity = 10;
    current = 0;
}

SRow::SRow(const SRow &a) {
    Copy(a);
}

void SRow::Copy(const SRow &a) {
    capacity = a.capacity;
    current = a.current;
    row = new Cell* [a.capacity];
    for(int i = 0; i<current; ++i){
        row[i] = a.row[i]->Clone();
    }
}

SRow &SRow::operator=(const SRow &a) {
    if(this == &a){
        return *this;
    }
    Erase();
    Copy(a);
    return *this;
}

SRow::~SRow() {
    Erase();
}

void SRow::add(Cell *a) {
    if(capacity == current){
        resize();
    }
    row[current] = a->Clone();
    ++current;
}

void SRow::resize() {
    Cell** tmp = row;
    row = new Cell* [capacity*2];
    capacity *= 2;
    for(int i = 0; i< capacity/2; ++i){
        row[i] = tmp[i];
    }
}

bool SRow::remove(int indx) {
    if(indx < 0 || indx >= current){
        std::cout<<"There is no cell number "<< indx << "." <<std::endl;
        return 0;
    }
    --current;
    for(int i = indx; i<current; ++i){
        Cell* tmp;
        tmp = row[i];
        row[i] = row[i+1]->Clone();
        delete tmp;
    }
    return 1;
}

void SRow::empty() {
    for(int i = current-1; i>=0; --i){
        remove(i);
    }
}

void SRow::Erase() {
    for(int i = 0; i<current; ++i){
        delete row[i];
    }
    delete[]row;
}

std::ostream &operator<<(std::ostream &out, const SRow &a) {
    for(int i = 0; i<a.current-1; ++i){
        out<<*a.row[i] << ",";
    }
    out<<*a.row[a.current-1];
    return out;
}

std::istream &operator>>(std::istream &is, SRow &a) {
    char buffer [512];
    char cell[128] = { 0 };
    is.getline(buffer, 512);
    int j = 0;
    for(int i = 0; i<strlen(buffer); ++i){
        if(buffer[i] != ','){
            cell[j] = buffer[i];
            ++j;
        }
        if(buffer[i] == ','){
            a.RecognizeCell(cell);
            for(int k = 0; k<strlen(cell); ++k){
                cell[k] = 0;
            }
            j = 0;
        }
    }
    a.RecognizeCell(cell);
}



void SRow::RecognizeCell(char *cell) {
    if(cell[0] == 0 || (cell[0] == ' ' && cell[1] == '\0')){
        this->add(new BlankCell());
    }
    else if(isDouble(cell)){
        this->add(new DoubleCell(cell));
    }
    else if(isInt(cell)){
        this->add(new IntCell(cell));
    }
    else if(isString(cell)){
        this->add(new StringCell(cell));
    }
    else if(isFormula(cell)){
        this->add(new FormulaCell(cell));
    }
}

Cell **SRow::getRow() const {
    return row;
}


