//
// Created by Dimitar on 25.5.2017 г..
//

#ifndef ELECTRONIC_TABLES_SPREADSHEET_H
#define ELECTRONIC_TABLES_SPREADSHEET_H

#include "SRow.h"

class Spreadsheet {
public:
    Spreadsheet();
    Spreadsheet(const Spreadsheet& ss);
    Spreadsheet&operator= (const Spreadsheet& ss);
    ~Spreadsheet();

    void add(const SRow& sr);
    void empty();

    friend std::ostream&operator<<(std::ostream& os, const Spreadsheet& ss);
    friend std::istream& operator>>(std::istream& in , Spreadsheet& ss);
    //функция изчисляваща всички формули в прочетената таблица.
    void FinalState();

    bool Edit(int row, int col, char* a);
    void Print() const;

private:
    SRow* sheet;
    int current;
    int capacity;

    void resize();
    void Copy(const Spreadsheet& ss);
    //функция изчисляваща дадена формула.
    double CalculateFormula(char* cell);
    //функция превръщаща стринговете и препратките към клетки във всяка формула в числа.
    double ConvertToNumber(char* a);
};


#endif //ELECTRONIC_TABLES_SPREADSHEET_H
