//
// Created by Dimitar on 21.5.2017 г..
//

#include "Cell.h"
#include <iostream>


std::ostream& operator<<(std::ostream &os, const Cell &c) {
    return c.Print(os);
}