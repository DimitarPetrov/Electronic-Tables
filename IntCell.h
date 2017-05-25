//
// Created by Dimitar on 25.5.2017 г..
//

#ifndef ELECTRONIC_TABLES_INTCELL_H
#define ELECTRONIC_TABLES_INTCELL_H

#include "Cell.h"

class IntCell: public Cell {
public:
    IntCell(const char* c = "");
    virtual std::ostream& Print(std::ostream& os) const override;
    virtual ~IntCell(){}
    virtual Cell* Clone() const override;

private:
    int content;

    int formatFix(const char* c);
};


#endif //ELECTRONIC_TABLES_INTCELL_H
