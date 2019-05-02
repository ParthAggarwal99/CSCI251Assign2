//
// Created by Anthony Suker on 2019-04-22.
//

#ifndef CSCI251ASSIGN2_WEAPONS_H
#define CSCI251ASSIGN2_WEAPONS_H

#include <string>

/**
 * Damage & accuracy to be tuned based off avg enemy health / fight time
 *
 *
 * Mining will have a bass drop of 3, mining efficiency is a multiplier to the base drop chance
 */

class Hardpoint{
public:

    const std::string &getName() const {
        return name;
    }

    int getDamage() const {
        return damage;
    }

    int getCritChance() const {
        return critChance;
    }

    int getAccuracy() const {
        return accuracy;
    }
    int getMiningEfficiency() const {
        return miningEfficiency;
    }

private:
    std::string name;
    int damage;
    int critChance;
    int accuracy;
    int miningEfficiency;
};

class MiningLasers: public Hardpoint{
private:
    const std::string name = "Mining Lasers";
    const int damage = 100;
    const int critChance = 20;
    const int accuracy = 85;
    const double miningEfficiency = 1;

};

class CritCannons: public Hardpoint{
private:
    const std::string name = "Crit Cannons";
    const int damage = 200;
    const int critChance = 85;
    const int accuracy = 90;
    const double miningEfficiency = 1.00/3;
};

class darters: public Hardpoint{
private:
    const std::string name = "22 Twin Darter Lasers";
    const int damage = 350;
    const int critChance = 40;
    const int accuracy = 95;
    const double miningEfficiency = 2.00/3;
};

class Missiles: public Hardpoint{
private:
    const std::string name = "B5 Missile Launcher";
    const int damage = 500;
    const int critChance = 20;
    const int accuracy = 70;
    const double miningEfficiency = 1.00/3;
};

#endif //CSCI251ASSIGN2_WEAPONS_H
