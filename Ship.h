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

    bool addOre(int i);
    void addMoney(int i);
    void addMaxHp(int i);

    int getHealth() const;
    int getMoney() const;
    int getFuel() const;
    int getFood() const;

    void minusHealth(int i);
    bool minusMoney(int i);
    void minusFuel(int i);
    void minusFood();

    void refuel();
    void repair(bool inCombat);
    void refillFood();



    Hull *getHull() const;
    Hardpoint *getHardpoint() const;
    Engine *getEngine() const;

    void printCombatStats();
    void printCoreStats();

private:
    Crew crew;
    Hull * hull;
    Hardpoint * hardpoint;
    Engine * engine;

    int health;
    int maxHealth;
    int money;
    int fuel;
    int food;
    int maxFuel;
    int ore;
public:
    int getOre() const;


};


#endif //CSCI251ASSIGN2_SHIP_H
