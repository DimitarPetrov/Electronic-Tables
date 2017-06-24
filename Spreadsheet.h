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

    friend std::ostream&operator<<(std::ostream& os, const Spreadsheet& ss);
    friend std::istream& operator>>(std::istream& in , Spreadsheet& ss);

    void FinalState();

    void Edit(int row, int col, char* a);

private:
    SRow* sheet;
    int current;
    int capacity;

    void resize();
    void Copy(const Spreadsheet& ss);

    double CalculateFormula(char* cell);
    double ConvertToNumber(char* a);
};


#endif //ELECTRONIC_TABLES_SPREADSHEET_H
