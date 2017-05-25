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


private:
    SRow* sheet;
    int current;
    int capacity;

    void resize();
    void Copy(const Spreadsheet& ss);
};


#endif //ELECTRONIC_TABLES_SPREADSHEET_H
