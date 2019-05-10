//
// Created by Anthony on 10/05/2019.
//

#include "Enemy.h"

void Enemy::randomizeStats(int counter) {
    double scale =  pow(1.055,counter);
    std::uniform_int_distribution<unsigned> hp_d(200*scale,400*scale);
    std::uniform_int_distribution<unsigned> dmg_d(25*scale,100*scale);
    std::uniform_int_distribution<unsigned> crit_d(0,35);
    std::uniform_int_distribution<unsigned> armor_d(10*scale,100*scale);
    hp = hp_d(enemyRand());
    damage = dmg_d(enemyRand());
    crit = crit_d(enemyRand());
    armor = armor_d(enemyRand());
}

int Enemy::getHp() const {
    return hp;
}

int Enemy::getDamage() const {
    return damage;
}

int Enemy::getCrit() const {
    return crit;
}

int Enemy::getArmor() const {
    return armor;
}
