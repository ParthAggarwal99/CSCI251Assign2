//
// Created by Anthony Suker on 2019-04-21.
//

#ifndef CSCI251ASSIGN2_SHIP_H
#define CSCI251ASSIGN2_SHIP_H

#include "ShipBuilder.h"
#include "Crew.h"


class Ship {
public:
    Ship();

    Crew * getCrew();
    int getHealth() const;

    int getMoney() const;

    int getFuel() const;

    void minusHealth(int i);
    void minusMoney(int i);
    void minusFuel(int i);
    void minusFood();

    void refuel();
    void repair(bool inCombat);
    void refillFood();

    int getFood() const;

    Hull *getHull() const;

    Hardpoint *getHardpoint() const;

    Engine *getEngine() const;

private:
    Crew crew;
    Hull * hull;
    Hardpoint * hardpoint;
    Engine * engine;

    int health;
    int money;
    int fuel;
    int food;



};


#endif //CSCI251ASSIGN2_SHIP_H
