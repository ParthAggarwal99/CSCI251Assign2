//
// Created by Anthony on 17/05/2019.
//

#ifndef CSCI251ASSIGN2_ALIEN_H
#define CSCI251ASSIGN2_ALIEN_H

#include "string"

class Alien {
public:
    Alien();

    const std::string &getName() const;

    bool isHostile() const;

    bool isTrade() const;

    int getCombatAbility() const;


    void printStats();

private:
    std::string name;
    bool hostile;
    bool trade;
    int combatAbility;
    std::string desc;
};


#endif //CSCI251ASSIGN2_ALIEN_H
