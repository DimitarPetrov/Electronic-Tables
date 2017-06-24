//
// Created by Dimitar on 25.5.2017 г..
//

#include "Spreadsheet.h"
#include "Recognition.h"
#include "FormulaCell.h"
#include "IntCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include <cstring>
#include <cmath>

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

std::istream &operator>>(std::istream &in, Spreadsheet &ss) {
    SRow buffer;
    while(in){
        in>>buffer;
        ss.add(buffer);
        buffer.empty();
    }
    ss.FinalState();
    return in;
}


double Spreadsheet::CalculateFormula(char *cell) {
    char left [32] = { 0 };
    char right [32] = { 0 };
    char op;
    int j = 0;
    bool flag = false;
    for(int i = 1; i<strlen(cell); ++i){
        if((cell[i] != '+' && cell[i] != '-' && cell[i] !=  '*' && cell[i] != '/' && cell[i] != '^') && !flag){
            left[j] = cell[i];
            j++;
        }
        if(cell[i] == '+' || cell[i] == '-' || cell[i] ==  '*' || cell[i] == '/' || cell[i] == '^'){
            op = cell[i];
            flag = true;
            j = 0;
        }
        if((cell[i] != '+' && cell[i] != '-' && cell[i] !=  '*' && cell[i] != '/' && cell[i] != '^') && flag){
            right[j] = cell[i];
            j++;
        }
    }
    if(op == '+'){
        return ConvertToNumber(left) + ConvertToNumber(right);
    }
    if(op == '-'){
        return ConvertToNumber(left) - ConvertToNumber(right);
    }
    if(op == '*'){
        return ConvertToNumber(left) * ConvertToNumber(right);
    }
    if(op == '/'){
        if(ConvertToNumber(right) == 0){
            throw "Error";
        }
        return ConvertToNumber(left) / ConvertToNumber(right);
    }
    if(op == '^'){
        return pow(ConvertToNumber(left), ConvertToNumber(right));
    }
}

double Spreadsheet::ConvertToNumber(char *a) {
    if(isInt(a)){
        return atoi(a);
    }
    if(isDouble(a)){
        return atof(a);
    }
    if(isCellPath(a)){
        bool flag = false;
        char row [16] = { 0 };
        char col [16] = { 0 };
        int j = 0;
        for(int i=1; i<strlen(a); ++i){
            if(isdigit(a[i]) && !flag){
                row[j] = a[i];
                ++j;
            }
            if(a[i] == 'C'){
                flag = true;
                j = 0;
            }
            if(isdigit(a[i]) && flag){
                col[j] = a[i];
                ++j;
            }

        }
        if(atoi(row)-1 > current || atoi(col) > sheet[atoi(row)-1].getCurrent()){
            return 0;
        }
        return ConvertToNumber(sheet[atoi(row)-1].getRow()[atoi(col)-1]->getRawContent());
    }
    return 0;
}

void Spreadsheet::FinalState() {
    double a;
    int b;
    for(int i = 0; i<current; ++i){
        for(int j = 0; j<sheet[i].getCurrent(); ++j){
            if(dynamic_cast<FormulaCell*>(sheet[i].getRow()[j])){
                try {
                    a = CalculateFormula(sheet[i].getRow()[j]->getRawContent());
                    b = a;
                    if(a - b == 0.0){
                        delete sheet[i].getRow()[j];
                        sheet[i].getRow()[j] = new IntCell(b);
                    }
                    else{
                        delete sheet[i].getRow()[j];
                        sheet[i].getRow()[j] = new DoubleCell(a);
                    }
                }
                catch (const char*){
                    delete sheet[i].getRow()[j];
                    sheet[i].getRow()[j] = new StringCell("ERROR");
                }
            }
        }
    }
}
