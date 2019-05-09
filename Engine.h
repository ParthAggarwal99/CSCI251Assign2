//
// Created by Anthony Suker on 2019-04-22.
//

#ifndef CSCI251ASSIGN2_ENGINE_H
#define CSCI251ASSIGN2_ENGINE_H

#include <string>

/**
 * Crit chance is 0-100 chance of a trip costing no fuel
 */

class Engine{
public:

    Engine(const std::string &name, int critChance, int evasion) : name(name), critChance(critChance), evasion(evasion) {}

    const std::string &getName() const {
        return name;
    }

    int getCritChance() const {
        return critChance;
    }

    int getEvasion() const {
        return evasion;
    }

private:
    std::string name;
    int critChance;
    int evasion;


};

class Swift: public Engine{
private:
    const std::string name = "Swift lite 23";
    int critChance = 5;
    int evasion = 15;
};

class Traveller : public Engine{
private:
    const std::string name = "Mk 4 InterSector Jumper";
    int critChance = 20;
    int evasion = 5;
};

class Balanced : public Engine{
public:
    Balanced():Engine(name,critChance,evasion){}

private:
    const std::string name = "Lawnmower Engine";
    int critChance = 10;
    int evasion = 10;
};

#endif //CSCI251ASSIGN2_ENGINE_H
