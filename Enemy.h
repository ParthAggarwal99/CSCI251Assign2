//
// Created by Anthony on 10/05/2019.
//

#ifndef CSCI251ASSIGN2_ENEMY_H
#define CSCI251ASSIGN2_ENEMY_H
#include "Enemy.h"
#include "random"
#include <cmath>

class Enemy {
public:
    void randomizeStats(int counter);

    int getHp() const;

    int getDamage() const;

    int getCrit() const;

    int getEvasion() const;

    int getArmor() const;

private:
    std::default_random_engine enemyRand(time(0));
    int hp;
    int damage;
    int crit;
    int evasion;
    int armor;
};


#endif //CSCI251ASSIGN2_ENEMY_H
