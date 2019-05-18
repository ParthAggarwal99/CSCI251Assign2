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

private:
    std::string name;
    bool hostile;
    bool trade;
    int combatAbility;
};


#endif //CSCI251ASSIGN2_ALIEN_H
