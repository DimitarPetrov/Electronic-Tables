//
// Created by Dimitar on 21.5.2017 г..
//

#ifndef ELECTRONIC_TABLES_CELL_H
#define ELECTRONIC_TABLES_CELL_H

#include <iostream>

class Cell {
public:
    Cell(const char* c = nullptr);
    Cell(const Cell& c);
    Cell& operator= (const Cell& c);
    virtual ~Cell();

    const char* getContent() const;
    virtual void setContent(const char* c) = 0;

    virtual std::ostream& Print(std::ostream& os) const;
    friend std::ostream&operator<<(std::ostream& os, const Cell& c);

private:
    char* content;

    void Copy(const Cell& c);
};


#endif //ELECTRONIC_TABLES_CELL_H
