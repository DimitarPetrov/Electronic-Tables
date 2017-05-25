//
// Created by Dimitar on 21.5.2017 г..
//

#ifndef ELECTRONIC_TABLES_CELL_H
#define ELECTRONIC_TABLES_CELL_H

#include <iostream>

class Cell {
public:
    Cell(){rawContent = nullptr;};
    Cell(const char* rc);
    Cell(const Cell& rc);
    Cell& operator= (const Cell& rc);
    virtual ~Cell();

    const char* getContent() const;
    virtual void setContent(const char* rc = "");

    virtual std::ostream& Print(std::ostream& os) const;
    friend std::ostream&operator<<(std::ostream& os, const Cell& c);

private:
    char* rawContent;
    void Copy(const Cell& c);
};


#endif //ELECTRONIC_TABLES_CELL_H
