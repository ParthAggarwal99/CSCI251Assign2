/**
 * NAME: ANTHONY SUKER
 * STUDENT ID: 6137210
 * LAB: FRIDAY 10:30
 */

using namespace std;
#include <iostream>
#include "Ship.h"
#include "Enemy.h"

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

    printOfficer(ship1.getCrew()->getCaptain());

    Enemy enemy1;
    enemy1.printStats();

    enemy1.randomizeStats(2);
    enemy1.printStats();

    enemy1.randomizeStats(50);
    enemy1.printStats();

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