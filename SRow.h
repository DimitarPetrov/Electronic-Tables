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


private:
    Cell** row;
    int current;
    int capacity;

    void Copy(const SRow& a);
    void Erase();
    void resize();
};


#endif //ELECTRONIC_TABLES_SROW_H
