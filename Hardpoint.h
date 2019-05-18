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
 * Mining will have a bass drop of 1, mining efficiency is a multiplier to the base drop chance
 */

class Hardpoint{
public:
    Hardpoint(const std::string &name, int damage, int critChance, int accuracy, int miningEff) : name(name),
                                                                                                  damage(damage),
                                                                                                  critChance(
                                                                                                          critChance),
                                                                                                  accuracy(accuracy),
                                                                                                  miningEff(
                                                                                                          miningEff) {}

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

    int getMiningEff() const {
        return miningEff;
    }

    void increaseDamage(int i) {
        damage+=100;
    }

private:
    std::string name;
    int damage;
    int critChance;
    int accuracy;
    int miningEff;
};


#endif //CSCI251ASSIGN2_WEAPONS_H
