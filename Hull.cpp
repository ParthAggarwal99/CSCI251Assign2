//
// Created by Anthony Suker on 2019-05-01.
//

#include "Hull.h"




//generate different Hulls and fill static list so they can be accessed by pointer from Ship
void Hull::generateHulls() {
    Hull h1("Heavy Hull",100,100,50,30);
    Hull h2("Combat Hull",30,20,30,15);
    Hull h3("Cargo Hull",50,50,100,40);
    hullList[0] = h1;
    hullList[1] = h2;
    hullList[2] = h3;
}




