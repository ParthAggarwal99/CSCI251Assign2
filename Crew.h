//
// Created by Anthony Suker on 2019-04-17.
//

#ifndef CSCI251ASSIGN2_CREW_H
#define CSCI251ASSIGN2_CREW_H

#include "Officer.h"

class Crew {
public:
    Crew();
    string casualty(void (*functocall)(string));
private:
    Officer captain;
    Officer pilot;
    Officer engineer;
    Officer miner;
    Officer weaponSmith;
    int crewSize;

    void killCaptain();
    void killPilot();
    void killEngineer();
    void killMiner();
    void killWeapon();
    void killCrew();

    Officer generateOfficer(int lower,int upper);
};




#endif //CSCI251ASSIGN2_CREW_H
