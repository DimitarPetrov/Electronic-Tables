//
// Created by Dimitar on 21.5.2017 г..
//

#ifndef ELECTRONIC_TABLES_BLANKCELL_H
#define ELECTRONIC_TABLES_BLANKCELL_H

#include "Cell.h"

class BlankCell:public Cell{
public:
    BlankCell(const char* c = "");
    virtual std::ostream& Print(std::ostream& os)const override;
    virtual ~BlankCell(){}
    virtual Cell* Clone() const override;

    const char *getContent() const;

private:
    char content[1];
    void formatFix(const char* rc);
};


#endif //ELECTRONIC_TABLES_BLANKCELL_H
