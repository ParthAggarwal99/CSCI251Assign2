//
// Created by Anthony on 10/05/2019.
//

#ifndef CSCI251ASSIGN2_COMBATMANAGER_H
#define CSCI251ASSIGN2_COMBATMANAGER_H

#include "Ship.h"
#include "Enemy.h"

class CombatManager {
public:
    CombatManager(Ship *ship, Enemy *enemy);
    void beginInstance();

private:

    struct DamageContainer{
    int damage;
    bool hit;
    bool crit;
    };

    typedef DamageContainer dCont;
    Ship * ship;
    Enemy * enemy;

    dCont attack();



};




#endif //CSCI251ASSIGN2_COMBATMANAGER_H
