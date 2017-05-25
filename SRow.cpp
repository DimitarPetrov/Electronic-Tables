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
    char buffer [256];
    while(is.getline(buffer, 256, ',')) {
        std::cout<<buffer<<"\n------------\n";
        if(buffer[0] == 0 || (buffer[0] == ' ' && buffer[1] == '\0')){
            a.add(new BlankCell());
        }
        else if(isDouble(buffer)){
            a.add(new DoubleCell(buffer));
        }
        else if(isInt(buffer)){
            a.add(new IntCell(buffer));
        }
        else if(isString(buffer)){
            a.add(new StringCell(buffer));
        }
//        else if(isFormula(buffer)){
//            a.add(new FormulaCell(buffer));
//        }


    }
}

void ClearWhitespaces(char* a){
    for(int i = strlen(a)-1; a[i]== ' '; --i){
        a[i] = 0;
    }
    for(int i = 0; i < strlen(a) && a[i] == ' ';){
        for(int j = i; j < strlen(a)-1; ++j){
            a[j] = a[j+1];
        }
        a[strlen(a)-1] = 0;
    }
}

bool isInt(char* a){
    bool flag = false;
    if(a[0] == '\0'){
        return 0;
    }
    ClearWhitespaces(a);
    for(int i = 1; i<strlen(a); ++i){
        if(!isdigit(a[i]) && !(isdigit(a[0]) || a[0] == '+' || a[0] == '-')){
            return 0;
        }
        flag = true;
    }
    return flag;
}

bool isString(char* a){
    ClearWhitespaces(a);
    if(a[0] == '\"' && a[strlen(a)-1] == '\"'){
        return 1;
    }
    return 0;
}

bool isFormula(char* a){
    ClearWhitespaces(a);
    if(a[0] == '='){
        return 1;
    }
    return 0;
}

bool isDouble(char* a){
    int countpts = 0;
    if(a[0] == '\0') return 0;
    ClearWhitespaces(a);
    if(isdigit(a[0]) || a[0] == '+' || a[0] == '-') {
        for(int i = 1; i < strlen(a); ++i) {
            if(a[i] == '.'){
                ++countpts;
            }
        }
        if(countpts > 1 || countpts == 0){
            return 0;
        }
        for(int i = 1; i<strlen(a); ++i){
            if(!isdigit(a[i]) && a[i] != '.'){
                return 0;
            }
        }
    } else{
        return 0;
    }
    return 1;
}