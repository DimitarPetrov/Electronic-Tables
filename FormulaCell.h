//
// Created by Dimitar on 25.5.2017 г..
//

#ifndef ELECTRONIC_TABLES_FORMULACELL_H
#define ELECTRONIC_TABLES_FORMULACELL_H

#include "Cell.h"

class FormulaCell: public Cell {
public:
    FormulaCell(const char* c = "");
    virtual std::ostream& Print(std::ostream& os) const override;
    virtual Cell* Clone() const override;
    virtual ~FormulaCell();



private:


};


#endif //ELECTRONIC_TABLES_FORMULACELL_H
