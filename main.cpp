/**
 * NAME: ANTHONY SUKER
 * STUDENT ID: 6137210
 * LAB: FRIDAY 10:30
 */

using namespace std;
#include <iostream>
#include "Ship.h"
#include "Enemy.h"
#include "CombatManager.h"
/**
 * TODO:
 *  find out how to do getters for inherited classes
 */

/**     BUG CHECK TIME :)
 * SHIP WORKS
 *   subclasses of Ship:
 *      Skillset Works
 *      Officer Works
 *      Crew Works
 *
 *
 */
void printOfficer(Officer * o);
int main() {

    fillLists();

    Ship ship1;
    Enemy enemy1;
    bool active = true;

    cout<<"WELCOME TO SPACE COMMANDER"<<endl;
    system("pause");


    CombatManager cm = CombatManager(&ship1,&enemy1);

    cm.beginInstance();

    enemy1.randomizeStats(25);

    cm=CombatManager(&ship1,&enemy1);

    cm.beginInstance();



//    Officer o;
//    cout<<o.getName()<<" "<<o.getAge()<<endl;
//    cout<<o.getSkillset().getEngineering()<<endl;
//    cout<<o.getSkillset().getMining()<<endl;
//    cout<<o.getSkillset().getNegotiation()<<endl;

//    try{
//        Ship ship1;
//    }catch(std::bad_alloc){
//        cout<<"bad alloc"<<endl;
//    }

    return 0;
}

void printOfficer(Officer * o){
    cout<<o->getName()<<" "<<o->getAge()<<endl;
    cout<<o->getSkillset().getEngineering()<<endl;
    cout<<o->getSkillset().getMining()<<endl;
    cout<<o->getSkillset().getNegotiation()<<endl<<endl;
}

void createAliens(){

}