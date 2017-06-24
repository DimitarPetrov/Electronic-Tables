//
// Created by Dimitar on 25.5.2017 г..
//

#ifndef ELECTRONIC_TABLES_SROW_H
#define ELECTRONIC_TABLES_SROW_H

#include "Cell.h"

class SRow {
public:
    //Голяма 4-ка.
    SRow();
    SRow(const SRow& a);
    SRow& operator=(const SRow& a);
    ~SRow();
    //Функция добавяща елемнт в масива.
    void add(Cell* a);
    //Функция премахваща елемнт от масива по зададен индекс.
    bool remove(int indx);
    //Функция изчистваща масива;
    void empty();

    friend std::ostream& operator<<(std::ostream& out, const SRow& a);
    friend std::istream& operator>>(std::istream& is, SRow& a);

    Cell **getRow() const;

private:
    Cell** row;
    int current;
    int capacity;

    void Copy(const SRow& a);
    void Erase();
    void resize();
    void RecognizeCell(char* cell);
};



#endif //ELECTRONIC_TABLES_SROW_H
