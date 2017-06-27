//
// Created by Dimitar on 25.5.2017 г..
//

#ifndef ELECTRONIC_TABLES_INTCELL_H
#define ELECTRONIC_TABLES_INTCELL_H

#include "Cell.h"

class IntCell: public Cell {
public:
    IntCell(const char* c = "");
    IntCell(int a);
    virtual std::ostream& Print(std::ostream& os) const override;
    virtual ~IntCell(){}

    int getContent() const;

    virtual Cell* Clone() const override;

private:
    //член данна пазеща обработеното съдържание на клетката.
    int content;
    //функция обработваща съдържанието на клетката.
    int formatFix(const char* c);
};


#endif //ELECTRONIC_TABLES_INTCELL_H
