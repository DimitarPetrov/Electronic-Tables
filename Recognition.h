//
// Created by Dimitar on 24.6.2017 г..
//

#ifndef ELECTRONIC_TABLES_RECOGNITION_H
#define ELECTRONIC_TABLES_RECOGNITION_H


//функции помагащи за определянето на типа на дадена клетка.
void ClearWhitespaces(char* a);
bool isInt(char* a);
bool isString(char* a);
bool isDouble(char* a);
bool isFormula(char* a);
bool isCellPath(char* a);

#endif //ELECTRONIC_TABLES_RECOGNITION_H
