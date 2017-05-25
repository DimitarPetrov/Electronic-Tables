//
// Created by Dimitar on 21.5.2017 г..
//

#ifndef ELECTRONIC_TABLES_BLANKCELL_H
#define ELECTRONIC_TABLES_BLANKCELL_H

#include "Cell.h"

class BlankCell:public Cell{
public:
    BlankCell();
    virtual std::ostream& Print(std::ostream& os)const override;
private:
    char content[3];

    void formatFix(const char* rc);
};


#endif //ELECTRONIC_TABLES_BLANKCELL_H
