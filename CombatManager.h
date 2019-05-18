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
    bool beginInstance();

private:
    Ship * ship;
    Enemy * enemy;
    bool casualty = false;

    void attack();
    void emergencyRepair();
    bool escape();
    void enemyAttack();
    void getRewards();
};




#endif //CSCI251ASSIGN2_COMBATMANAGER_H
