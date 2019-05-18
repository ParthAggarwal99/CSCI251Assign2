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
#include "Sector.h"


void printOfficer(Officer * o);
bool shipIsGood(Ship * ship);
int main() {
    int counter = 0;
    fillLists();
    Ship ship;
    Sector * sector;

    ship.getCrew()->printCrew();
    ship.printCoreStats();
    system("pause");
    do{
        srand(time(0));
        if(rand()%100<ship.getEngine()->getCritChance()){
            cout<<"ENGINES CRITICALLY FIRED. TRANSPORT IS FREE";
        }else{
            ship.minusFood();
            ship.minusFuel(1);
        }

        ship.printTransportStats();

        counter++;

        srand(time(0));
        int sectorRoll = rand()%101;

        if(sectorRoll<=35){
            sector = new ShipSector(&ship,counter);
        }else if(sectorRoll<=60){
            sector = new PlanetSector(&ship,counter);
        }else if(sectorRoll<=75){
            sector = new TradingSector(&ship,counter);
        } else if(sectorRoll<=90){
            sector = new EmptySector(&ship,counter);
        }else{
            sector = new AstroidSector(&ship,counter);
        }

        sector->arrive();
        sector->options();

        delete sector;

    }while(shipIsGood(&ship));

    return 0;
}

bool shipIsGood(Ship * ship){
    if(ship->getHealth()<=0){
        cout<<"YOU HAVE NO MORE HEALTH"<<endl;
        return false;
    }
    if(ship->getFood()<=0){
        cout<<"YOU HAVE NO MORE FOOD"<<endl;
        return false;
    }
    if(ship->getFuel()<=0){
        cout<<"YOU HAVE NO MORE FUEL"<<endl;
        return false;
    }
    if(ship->getCrew()->getCrewSize()<0){
        cout<<"YOU HAVE NO MORE CREW"<<endl;
        return false;
    }

    return true;
}