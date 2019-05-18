//
// Created by Anthony on 10/05/2019.
//

#include "CombatManager.h"

CombatManager::CombatManager(Ship *ship, Enemy *enemy) : ship(ship), enemy(enemy) {}


void CombatManager::beginInstance() {
    cout<<"YOU HAVE ENTERED COMBAT"<<endl;
    ship->printCombatStats();
    enemy->printStats();
    cout<<"YOUR OPTIONS ARE"<<endl;

    bool engaged = true;
    while (engaged) {
        cout<<"1::ATTACK"<<endl<<
            "2::EMERGENCY REPAIR"<<endl<<
            "3::ATTEMPT ESCAPE"<<endl;

        int option=0;
        try{
            cin>>option;
        }catch(exception& e){
            cerr<<"I DONT THINK THATS A NUMBER"<<endl<<e.what()<<endl;
        }

        switch(option){
            case 1:
                attack();
                break;
            case 2:
                emergencyRepair();
                break;
            case 3:
                engaged = escape();
                break;
            default:
                cout<<"THAT IS NOT A VALID TURN"<<endl;
        }
        if(enemy->getHp()<=0){
            getRewards();
            engaged = false;
        }

        if(engaged){
            enemyAttack();
            cout<<"HP: "<<ship->getHealth()<<endl;
            cout<<"Enemy HP: "<<enemy->getHp()<<endl;
        }

    }

    bool escapetry = false;


}

void CombatManager::attack() {
    Hardpoint * wep = ship->getHardpoint();
    int damage = wep->getDamage();
    bool crit = false;
    srand(time(0));



    if(rand()%101 < wep->getCritChance()){
        damage = damage*2;
        crit = true;
    }


    if(rand()%101 > wep->getAccuracy()) {
        cout << "YOUR ATTACK MISSED" << endl;
    }else{
        if(crit){
            cout<< "YOUR ATTACK CRITICALLY HIT FOR "<<damage<<endl<<endl;
        }else{
            cout<< "YOUR ATTACK HIT FOR "<<damage<<endl<<endl;
        }
        enemy->minusHp(damage);
    }
}

void CombatManager::getRewards() {

}

void CombatManager::emergencyRepair() {
    ship->repair(true);
}

/**
 * 25% chance to escape
 * @return
 */
bool CombatManager::escape() {
    srand(time(0));
    if(rand()%5>1){
        return false;
    }
    return true;
}

void CombatManager::enemyAttack() {


    int damage = enemy->getDamage();
    bool crit = false;
    srand(time(0));



    if(rand()%101 <enemy->getCrit()){
        damage = damage*2;
        crit = true;
    }


    if(rand()%101 > ship->getEngine()->getEvasion()) {
        cout << "YOU AVOIDED THE ENEMY'S ATTACK" << endl<<endl;
    }else{
        if(crit){
            cout<< "THE ENEMY'S ATTACK CRITICALLY HIT FOR "<<damage<<endl<<endl;
        }else{
            cout<< "THE ENEMY'S ATTACK HIT FOR "<<damage<<endl<<endl;
        }
        ship->minusHealth(damage);
    }
}


