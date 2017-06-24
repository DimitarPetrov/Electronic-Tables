//
// Created by Dimitar on 25.5.2017 г..
//

#ifndef ELECTRONIC_TABLES_DOUBLECELL_H
#define ELECTRONIC_TABLES_DOUBLECELL_H

#include "Cell.h"

class DoubleCell: public Cell {
public:
    DoubleCell(const char* c = "");
    DoubleCell(double a);
    virtual std::ostream& Print(std::ostream& os) const override;

    virtual ~DoubleCell(){}
    virtual Cell* Clone() const override;

    double getContent() const;

private:
    double content;

    double formatFix(const char* c);
};


#endif //ELECTRONIC_TABLES_DOUBLECELL_H
