//
// Created by Anthony on 10/05/2019.
//

#ifndef CSCI251ASSIGN2_ENEMY_H
#define CSCI251ASSIGN2_ENEMY_H
#include "random"
#include <time.h>
#include <cmath>

class Enemy {
public:
    Enemy();

    void randomizeStats(int counter);

    int getHp() const;

    int getDamage() const;

    int getCrit() const;

    int getArmor() const;

    void printStats();

    void enhance(int combat);

    void minusHp(int i);

private:
    std::default_random_engine enemyRand;
    int hp;
    int damage;
    int crit;
    int armor;
    double scale;
};


#endif //CSCI251ASSIGN2_ENEMY_H
