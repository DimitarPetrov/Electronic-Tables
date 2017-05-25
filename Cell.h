//
// Created by Dimitar on 21.5.2017 г..
//

#ifndef ELECTRONIC_TABLES_CELL_H
#define ELECTRONIC_TABLES_CELL_H

#include <iostream>

class Cell {
public:
    virtual std::ostream& Print(std::ostream& os) const = 0;
    friend std::ostream&operator<<(std::ostream& os, const Cell& c);

    virtual ~Cell(){}
};


#endif //ELECTRONIC_TABLES_CELL_H
