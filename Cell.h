//
// Created by Dimitar on 21.5.2017 г..
//

#ifndef ELECTRONIC_TABLES_CELL_H
#define ELECTRONIC_TABLES_CELL_H

#include <iostream>
//Абстрактен клас за Клетка
class Cell {
public:
    Cell(const char* rc);
    Cell(const Cell& c);
    Cell& operator=(const Cell& c);

    virtual std::ostream& Print(std::ostream& os) const = 0;
    friend std::ostream&operator<<(std::ostream& os, const Cell& c);

    virtual Cell* Clone() const = 0;

    char *getRawContent() const;

    virtual ~Cell();

protected:
    //член данна пазеща необработеното съдържаниие на клетката.
    char* rawContent;
private:
    void Copy(const Cell& c);
};


#endif //ELECTRONIC_TABLES_CELL_H
