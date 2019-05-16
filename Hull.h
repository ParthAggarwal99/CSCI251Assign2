//
// Created by Anthony Suker on 2019-04-21.
//

#ifndef CSCI251ASSIGN2_HULL_H
#define CSCI251ASSIGN2_HULL_H

#include <string>

/**
 * HIT POINTS:
 *      Standardized across all ships for easier recognition for how much of
 *      an impact weight and armor are having.
 *      TO CONSIDER:
 *          each part having their own amount of hitpoints so individual pieces can be repaired
 *
 * ARMOR:
 *      Armor provides a flat % damage resist based on an exponential curve
 *      Curve formula f(x) = 100 / (100+.4x)
 *
 * WEIGHT:
 *      Weight determines manuvourability and fuel cost for jumps
 *      is in Tonnes
 *
 * Cargo:
 *      dictates amount of cargo available to be held
 *      each point of cargo held adds 1 tonne to weight
 *
 *
 * People:
 *      dictates crew limit, not including officers
 *
 * FUEL & FOOD:
 *      takes cargo capacity and dwindles as the space journey continues
 *      Fuel shall diminish at different amount per sector traveled to indicated varied distances between sectors
 *      Food shall diminish at at 1 tonne per amount of sectors traveled determined by amount of crew.
 */

class Hull{
public:
    Hull(const std::string &name, double armor, int weight, int cargoCapacity, int peopleCapacity) : name(name),
                                                                                                     armor(armor),
                                                                                                     weight(weight),
                                                                                                     cargoCapacity(
                                                                                                             cargoCapacity),
                                                                                                     peopleCapacity(
                                                                                                             peopleCapacity) {}

    int getArmor() const {
        return armor;
    }

    int getWeight() const {
        return weight;
    }

    int getCargoCapacity() const {
        return cargoCapacity;
    }

    int getPeopleCapacity() const {
        return peopleCapacity;
    }

    const std::string &getName() const {
        return name;
    }

    static Hull* pickHull(int i);

private:
    std::string name;
    int armor;
    int weight;
    int cargoCapacity;
    int peopleCapacity;
    static Hull hullList [3];
};







#endif //CSCI251ASSIGN2_HULL_H
