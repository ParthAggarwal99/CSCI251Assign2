//
// Created by Anthony Suker on 2019-04-21.
//

#include "Ship.h"
int maxFuel = 20;
int health = 1000;
int money = 1000;
int fuel = 50;

Ship::Ship() {
    std::cout<<"BEGINING CREATION"<<endl;
    try {
        hull = makeHull();
        engine = makeEngine();
        hardpoint = makeHardPoint();
    }catch(exception exception1){
        cout<<"exception1 "<<endl;
    }



    std::cout<<"SHIP CREATED"<<endl;
    std::cout<<"ENGINE      : "<<engine->getName()<<endl;
    std::cout<<"HULL        : "<<hull->getName()<<endl;
    std::cout<<"HARDPOINT   : "<<hardpoint->getName()<<endl;
}

int Ship::getHealth() const {
    return health;
}

int Ship::getMoney() const {
    return money;
}

int Ship::getFuel() const {
    return fuel;
}

void Ship::minusHealth(int i) {
    health -=i;
}

void Ship::minusMoney(int i) {
    money-=i;
}

void Ship::minusFuel(int i) {
    fuel-=i;
}

void Ship::refuel() {
    fuel = maxFuel;
}

/**
 * base repair is 150
 * repair amount is increased by engineers skill level * 2
 * if in combat repair is half effective
 * @param inCombat
 */
void Ship::repair(bool inCombat) {
    int repairAmount = 150;
    repairAmount += (crew.getEngineer()->getSkillset().getEngineering())*2;
    repairAmount = inCombat? repairAmount/2 : repairAmount;
    health+=repairAmount;
    if(health>1000){
        int difference = health -1000;
        repairAmount -= difference;
        cout<<"THE SHIP HAS BEEN REPAIRED FOR "<<repairAmount<<endl;
    }else{
        cout<<"THE SHIP HAS BEEN REPAIRED FOR "<<repairAmount<<endl;
    }
    //checks if health is over 1000, if so sets back at 1000
    health = health>1000? 1000:health;
}

void Ship::minusFood() {

}

void Ship::refillFood() {

}

int Ship::getFood() const {
    return food;
}

Hull *Ship::getHull() const {
    return hull;
}

Hardpoint *Ship::getHardpoint() const {
    return hardpoint;
}

Engine *Ship::getEngine() const {
    return engine;
}

Crew *Ship::getCrew() {
    return &crew;
}


