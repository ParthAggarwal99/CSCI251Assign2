//
// Created by Anthony on 17/05/2019.
//

#include <time.h>
#include <iostream>
#include "Alien.h"
using namespace std;

std::string alienNames [5] = {"Aurra","Azan","Bialar","Makkan","Zeno"};
Alien::Alien() {
    srand(time(0));
    switch (rand()%5){
        case 0:
            name = alienNames[0];
            hostile = false;
            trade = true;
            combatAbility = 0;
            desc = "A quiet race\nThe Aurra try avoid conflict at all costs";
            break;
        case 1:
            name = alienNames[1];
            hostile = true;
            trade = false;
            combatAbility = 40;
            desc ="An aggresive race\nThe Azan will intiate combat without warning";
            break;
        case 2:
            name = alienNames[2];
            hostile = false;
            trade = true;
            combatAbility = 30;
            desc = "The traders of the galaxy\nalthough peaceful don't be decieved, The Bialar pack a fierce punch";
            break;
        case 3:
            name = alienNames[3];
            hostile=false;
            trade = false;
            combatAbility = 20;
            desc ="The nomads\nThe Makkan often dont carry wares to trade and try to avoid combat";
        case 4:
            name = alienNames[4];
            hostile= true;
            trade = true;
            combatAbility =15;
            desc = "A cautious group\nThe Zeno are hostile and will often attack others but can be negotiated with.";
        default:
            std::cerr<<"Something broken in Alien race constructor";
    }
}

const std::string &Alien::getName() const {
    return name;
}

bool Alien::isHostile() const {
    return hostile;
}

bool Alien::isTrade() const {
    return trade;
}

int Alien::getCombatAbility() const {
    return combatAbility;
}

void Alien::printStats() {
cout<<"NAME: "<<name<<endl
<<"DESC: "<<desc<<endl
<<"HOSTILE: "<<std::boolalpha<<hostile<<endl
<<"CAN TRADE?: "<<std::boolalpha<<trade<<endl
<<"COMBAT ABILITY: "<<combatAbility<<endl<<endl;
}


