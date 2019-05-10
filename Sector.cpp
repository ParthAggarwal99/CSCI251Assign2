//
// Created by Anthony Suker on 2019-05-10.
//
#include "Sector.h"

bool Sector::escape() {
    std::uniform_int_distribution<unsigned> escapeRange(0,100);
    if(escapeRange(random_engine)>escapeChance){
        return false;
    }else{
        return true;
    }
}
