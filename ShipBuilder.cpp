//
// Created by Anthony on 2/05/2019.
//

#include "ShipBuilder.h"

/**
 * Generate objects and populate lists of ship parts to be pulled from later when generating ships
 */
std::vector<Hull> hullList;
std::vector<Hardpoint> hpList;
std::vector<Engine> engineList;

void fillLists(){
    hullList.push_back(Hull("Heavy Hull",100,100,50,30));
    hullList.push_back(Hull("Combat Hull",30,20,30,15));
    hullList.push_back(Hull("Cargo Hull",50,50,100,40));

    hpList.push_back(Hardpoint("Mining Lasers",100,20,85,3));
    hpList.push_back(Hardpoint("Crit Cannons",200,85,90,1));
    hpList.push_back(Hardpoint("Twin Darter Lasers",350,40,95,2));
    hpList.push_back(Hardpoint("B5 Missile Launcher",500,20,70,1));

    engineList.push_back(Engine("Swift Lite",5,15));
    engineList.push_back(Engine("MK4 InterSector Jumper",20,5));
    engineList.push_back(Engine("Lawnmower Engine",10,10));

}

Hull * getHull(){
    return & hullList[1];
}
