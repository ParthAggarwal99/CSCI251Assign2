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
    scale =  pow(1.055,counter);
    srand(time(0));

    hp = (rand()%301+200)*scale;
    damage = (rand()%76+25)*scale;
    crit = (rand()%21);
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


void Enemy::printStats() {
    cout<<"ENEMY STATS"<<endl;
    cout<<"hp: "<<hp<<endl;
    cout<<"damage: "<<damage<<endl;
    cout<<"crit: "<<crit<<endl;
}

void Enemy::enhance(int combat) {
    damage+= combat*scale;
}

void Enemy::minusHp(int i) {
    hp-= i;

}


