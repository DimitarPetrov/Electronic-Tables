//
// Created by Dimitar on 25.5.2017 г..
//

#ifndef ELECTRONIC_TABLES_STRINGCELL_H
#define ELECTRONIC_TABLES_STRINGCELL_H

#include "Cell.h"

class StringCell: public Cell {
public:
    StringCell(const char* c = "");
    StringCell(const StringCell& sc);
    StringCell&operator=(const StringCell& sc);
    virtual std::ostream& Print(std::ostream& os)const override;
    virtual Cell* Clone() const override;

    char *getContent() const;

    virtual ~StringCell();

private:
    char* content;

    void Copy(const StringCell& sc);
    const char* formatFix( char* c);
};


#endif //ELECTRONIC_TABLES_STRINGCELL_H
