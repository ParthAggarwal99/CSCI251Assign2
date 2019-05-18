//
// Created by Anthony on 2/05/2019.
//

#include "ShipBuilder.h"
#include <cstdlib>
#include <time.h>
#include "iostream"
using namespace std;
/**
 * Generate objects and populate lists of ship parts to be pulled from later when generating ships
 */
std::vector<Hull> hullList;
std::vector<Hardpoint> hpList;
std::vector<Engine> engineList;


void fillLists(){
    hullList.push_back(Hull("Heavy Hull",100,100,50,15));
    hullList.push_back(Hull("Combat Hull",30,20,30,10));
    hullList.push_back(Hull("Cargo Hull",50,50,100,25));

    hpList.push_back(Hardpoint("Mining Lasers",150,20,85,3));
    hpList.push_back(Hardpoint("Crit Cannons",125,95,90,1));
    hpList.push_back(Hardpoint("Twin Darter Lasers",225,40,95,2));
    hpList.push_back(Hardpoint("B5 Missile Launcher",300,20,65,1));

    engineList.push_back(Engine("Swift Lite",5,15));
    engineList.push_back(Engine("MK4 InterSector Jumper",20,5));
    engineList.push_back(Engine("Lawnmower Engine",10,10));

    srand(time(0));

}


Hull * makeHull(){
    return & hullList[rand()%3];
}

Hardpoint *makeHardPoint() {
    return & hpList[rand()%4];
}

Engine *makeEngine() {
    return & engineList[rand()%3];
}
