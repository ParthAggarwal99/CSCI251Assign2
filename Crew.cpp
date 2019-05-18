//
// Created by Anthony Suker on 2019-04-17.
//

#include "Crew.h"
/**
 * generate crew
 * create casualty related functions
 *
 */


Crew::Crew() {
    cout<<"CREATING CREW"<<endl;
    captain = new Officer;
    pilot = new Officer;
    engineer = new  Officer;
    miner = new Officer;
    weaponSmith = new Officer;
}

Crew::~Crew() {
    delete captain;
    delete pilot;
    delete engineer;
    delete miner;
    delete weaponSmith;
}

//Officer now works off a default constructor meaning there is no longer a need for this.
//Generate first set Of officers for crew;
//    Crew::Crew() :  captain(namesList[firstNameDist(randEng)],ageDist(randEng),SkillSet(60,100)) ,
//                    pilot(namesList[firstNameDist(randEng)],ageDist(randEng),SkillSet(60,100)),
//                    engineer(namesList[firstNameDist(randEng)],ageDist(randEng),SkillSet(60,100)),
//                    miner (namesList[firstNameDist(randEng)],ageDist(randEng),SkillSet(60,100)),
//                    weaponSmith(namesList[firstNameDist(randEng)],ageDist(randEng),SkillSet(60,100)){
//
//    }



int Crew::getCrewSize() const {
    return crewSize;
}

Officer *Crew::getCaptain() {
    return captain;
}

Officer *Crew::getPilot() {
    return pilot;
}

Officer *Crew::getEngineer() {
    return engineer;
}

Officer *Crew::getMiner() {
    return miner;
}

Officer *Crew::getWeaponSmith() {
    return weaponSmith;
}

void Crew::setCrewSize(int crewSize) {
    Crew::crewSize = crewSize;
}

void Crew::printCrew() {
    cout<<"CREWSIZE = "<<crewSize;
    cout<<" ROLE  :  NAME  : NEGOTIATION:PILOTING:ENGINEERING:MINING:WEAPONS"<<endl;
    cout<<"CAPTAIN : ";
    captain->print();
    cout<<"PILOT : ";
    pilot->print();
    cout<<"ENGINEEER : ";
    engineer->print();
    cout<<"WEAPONSMITH : ";
    weaponSmith->print();
    cout<<"MINER : ";
    miner->print();
    cout<<endl;
}

void Crew::casualty(string killer,int turn) {
    string s ="";
    srand(time(0));
    switch (rand()%6){
        case 0:{
            s +="Captain "+captain->getName();
            captain->reroll(log.size());
            break;
        }
        case 1:{
            s +="Pilot "+pilot->getName();
            pilot->reroll(log.size());
            break;
        }
        case 2:{
            s +="Engineer "+engineer->getName();
            engineer->reroll(log.size());
            break;
        }
        case 3:{
            s +="Miner "+miner->getName();
            miner->reroll(log.size());
            break;
        }
        case 4:{
            s +="Weapon Smith "+weaponSmith->getName();
            weaponSmith->reroll(log.size());
            break;
        }
        case 5:{
            s +="A Crew Member";
            break;
        }

    }
    s += " died on turn "+turn;
    s += " in a sector inhabited by "+killer;
    log.push_back(s);
}




