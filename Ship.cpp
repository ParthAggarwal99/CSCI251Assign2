//
// Created by Anthony Suker on 2019-04-21.
//

#include "Ship.h"


Ship::Ship() {
    try {
        hull = makeHull();
        engine = makeEngine();
        hardpoint = makeHardPoint();
    }catch(exception exception1){
        cout<<"exception1 "<<endl;
    }

    maxFuel = 20;
    health = 1000;
    maxHealth = 1000;
    money = 1000;
    fuel = 50;
    food = 25;

    crew.setCrewSize(hull->getPeopleCapacity());
    std::cout<<"SHIP CREATED"<<endl;
    std::cout<<"ENGINE      : "<<engine->getName()<<endl;
    std::cout<<"HULL        : "<<hull->getName()<<endl;
    std::cout<<"HARDPOINT   : "<<hardpoint->getName()<<endl<<endl;
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

bool Ship::minusMoney(int i) {
    if(money-i>0){
        money-=i;
        return true;
    }
    return false;
}

void Ship::minusFuel(int i) {
    fuel-=i;
}

void Ship::refuel() {
    cout<<"SHIP REFUELED"<<endl;
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
    if(health>maxHealth){
        int difference = health -maxHealth;
        repairAmount -= difference;
        cout<<"THE SHIP HAS BEEN REPAIRED FOR "<<repairAmount<<endl;
    }else{
        cout<<"THE SHIP HAS BEEN REPAIRED FOR "<<repairAmount<<endl;
    }
    //checks if health is over max Health, if so sets back to max Health
    health = health>maxHealth? maxHealth:health;
    cout<<"YOU NOW HAVE "<<health<<" HEALTH"<<endl<<endl;
}

void Ship::minusFood() {
    food--;
}

void Ship::refillFood() {
    food = 25;
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

void Ship::printCombatStats() {
    cout<<"YOUR COMBAT STATS"<<endl;
    cout<<"hp: "<<health<<endl;
    cout<<"damage: "<<hardpoint->getDamage()<<endl;
    cout<<"crit: "<<hardpoint->getCritChance()<<endl;
    cout<<"accuracy: "<<hardpoint->getAccuracy()<<endl;
    cout<<"armor: "<<hull->getArmor()<<endl<<endl;

}

void Ship::printCoreStats() {
    cout<<"YOUR CORE STATS"<<endl;\
    cout<<money<<"$"<<endl;
    cout<<"hp: "<<health<<endl;
    cout<<"food: "<<food<<endl;
    cout<<"fuel: "<<fuel<<endl;
    cout<<"armor: "<<hull->getArmor()<<endl;
}

int Ship::getOre() const {
    return ore;
}

bool Ship::addOre(int i) {
    ore += i;

    if(ore > hull->getCargoCapacity()){
        ore = hull->getCargoCapacity();
        cout<<"CARGO AT CAPACITY"<<endl;
    }
    cout<<"YOU NOW HAVE "<<ore<<" ORE"<<endl;
}

void Ship::addMoney(int i) {
    money+=money;
}

void Ship::addMaxHp(int i) {
    maxHealth+=i;
    health=maxHealth;
}


