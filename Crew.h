//
// Created by Anthony Suker on 2019-04-17.
//

#ifndef CSCI251ASSIGN2_CREW_H
#define CSCI251ASSIGN2_CREW_H

#include "Officer.h"
#include "random"

/**
 * TODO:
 * implement last names
 */

static uniform_int_distribution<unsigned> firstNameDist (0,19);
static uniform_int_distribution<unsigned> ageDist (18,70);

class Crew {
public:
    Crew();

    virtual ~Crew();

    void printCrew();
    void setCrewSize(int crewSize);
    int getCrewSize() const;
    void casualty(string killer,int turn);

    Officer * getCaptain();
    Officer * getPilot();
    Officer * getEngineer();
    Officer * getMiner();
    Officer * getWeaponSmith();

private:
    Officer * captain;
    Officer * pilot;
    Officer * engineer;
    Officer *  miner;
    Officer * weaponSmith;
    int crewSize;


    vector <string> log;

};





#endif //CSCI251ASSIGN2_CREW_H
