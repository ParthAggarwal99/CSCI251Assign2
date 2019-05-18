//
// Created by Anthony on 17/05/2019.
//

#include <time.h>
#include "Alien.h"


std::string alienNames [5] = {"Aurra","Azan","Bialar","Makkan","Zeno"};
Alien::Alien() {
    srand(time(0));
    switch (rand()%5){
        case 0:
            name = alienNames[0];
            hostile = false;
            trade = true;
            combatAbility = 0;
            break;
        case 1:
            name = alienNames[1];
            hostile = true;
            trade = false;
            combatAbility = 10;
            break;
        case 2:
            name = alienNames[2];
            hostile = false;
            trade = true;
            combatAbility = 30;
            break;
        case 3:
            name = alienNames[3];
            hostile=false;
            trade = false;
            combatAbility = 20;
        case 4:
            name = alienNames[4];
            hostile= false;
            trade = true;
            combatAbility =15;
        case 5:
            name = alienNames[5];
            hostile = true;
            trade = false;
            combatAbility =40;
    }
}

const std::string &Alien::getName() const {
    return name;
}

bool Alien::isHostile() const {
    return hostile;
}

bool Alien::isTrade() const {
    return trade;
}

int Alien::getCombatAbility() const {
    return combatAbility;
}

