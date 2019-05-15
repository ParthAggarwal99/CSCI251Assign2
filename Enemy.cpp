//
// Created by Anthony on 10/05/2019.
//


#include <iostream>
#include "Enemy.h"

using namespace std;

Enemy::Enemy() {
    randomizeStats(1);
}

void Enemy::randomizeStats(int counter) {
    std::cout<<"GENERATING NEW ENEMY"<<endl;
    double scale =  pow(1.055,counter);
    srand(time(0));
    int upper = 200*scale;
    std::uniform_int_distribution<unsigned> hp_d(200,400);
    std::uniform_int_distribution<unsigned> dmg_d(25*scale,100*scale);
    std::uniform_int_distribution<unsigned> crit_d(0,35);
    std::uniform_int_distribution<unsigned> armor_d(10*scale,100*scale);
//    hp = hp_d(enemyRand());
//    damage = dmg_d(enemyRand());
//    crit = crit_d(enemyRand());
//    armor = armor_d(enemyRand());

    hp = (rand()%201+200)*scale;
    damage = (rand()%76+25)*scale;
    crit = (rand()%36);
    armor = (rand()%91+10)*scale;
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

void Enemy::printStats() {
    cout<<"ENEMY STATS"<<endl;
    cout<<"hp: "<<hp<<endl;
    cout<<"crit: "<<crit<<endl;
    cout<<"armor: "<<armor<<endl<<endl;
}


