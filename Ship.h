//
// Created by Anthony Suker on 2019-04-21.
//

#ifndef CSCI251ASSIGN2_SHIP_H
#define CSCI251ASSIGN2_SHIP_H

#include "Hull.h"
#include "Hardpoint.h"
#include "Engine.h"
#include "Crew.h"


class Ship {
public:
    Ship();

private:
    Crew crew;
    Hull * hull;
    Hardpoint * hardpoint;
    Engine * engine;



};


#endif //CSCI251ASSIGN2_SHIP_H
