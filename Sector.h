//
// Created by Anthony Suker on 2019-04-21.
//

#ifndef CSCI251ASSIGN2_SECTOR_H
#define CSCI251ASSIGN2_SECTOR_H

#include <random>
#include <time.h>
#include "string"


/**
 *  Arrive() is called when a player enters a new sector
 *      returns a brief introduction and tells player their options
 */
static std::default_random_engine random_engine(time(0));
class Sector{
public:
    Sector(const std::string &name, int escapeChance) : name(name), escapeChance(escapeChance) {}

    virtual std::string arrive();
    virtual std::string interactOptions();
    bool escape();
protected:
    std::string name;
    int escapeChance;
};



#endif //CSCI251ASSIGN2_SECTOR_H
