//
// Created by Dimitar on 21.5.2017 г..
//

#ifndef ELECTRONIC_TABLES_BLANKCELL_H
#define ELECTRONIC_TABLES_BLANKCELL_H

#include "Cell.h"

class BlankCell:public Cell{
public:
    BlankCell();
    virtual void setContent(const char* c = "") override;
    //virtual std::ostream& Print(std::ostream& os)const override;
private:

};


#endif //ELECTRONIC_TABLES_BLANKCELL_H
