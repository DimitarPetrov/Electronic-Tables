//
// Created by Dimitar on 24.6.2017 г..
//
#include "Recognition.h"
#include <cstring>
#include <ctype.h>

void ClearWhitespaces(char* a){
    for(int i = strlen(a)-1; a[i]== ' '; --i){
        a[i] = 0;
    }
    for(int i = 0; i < strlen(a) && a[i] == ' ';){
        for(int j = i; j < strlen(a)-1; ++j){
            a[j] = a[j+1];
        }
        a[strlen(a)-1] = 0;
    }
}

bool isInt(char* a){
    if(a[0] == '\0'){
        return 0;
    }
    ClearWhitespaces(a);
    for(int i = 1; i<strlen(a); ++i){
        if(!isdigit(a[i]) || !(isdigit(a[0]) || a[0] == '+' || a[0] == '-')){
            return 0;
        }
    }
    return true;
}

bool isString(char* a){
    ClearWhitespaces(a);
    if(a[0] == '\"' && a[strlen(a)-1] == '\"'){
        return 1;
    }
    return 0;
}

bool isFormula(char* a){
    ClearWhitespaces(a);
    if(a[0] == '='){
        return 1;
    }
    return 0;
}

bool isDouble(char* a){
    int countpts = 0;
    if(a[0] == '\0') return 0;
    ClearWhitespaces(a);
    if(isdigit(a[0]) || a[0] == '+' || a[0] == '-') {
        for(int i = 1; i < strlen(a); ++i) {
            if(a[i] == '.'){
                ++countpts;
            }
        }
        if(countpts > 1 || countpts == 0){
            return 0;
        }
        for(int i = 1; i<strlen(a); ++i){
            if(!isdigit(a[i]) && a[i] != '.'){
                return 0;
            }
        }
    } else{
        return 0;
    }
    return 1;
}

bool isCellPath(char *a) {
    int ccount = 0;
    if(a[0] != 'R'){
        return 0;
    }
    for(int i = 1; i<strlen(a); ++i){
        if(a[i] != 'C' && !isdigit(a[i])){
            return 0;
        }
        if(a[i] == 'R'){
            return 0;
        }
        if(a[i] == 'C'){
            ccount++;
        }
    }
    if(ccount == 0 || ccount > 1){
        return 0;
    }
    return 1;
}