//
// Created by Anthony Suker on 2019-04-17.
//

#include "Crew.h"
/**
 * generate crew
 * create casualty related functions
 *
 */
string namesList [19] = {"Aaren", "Aarez","Alum", "Alvern", "Jorge", "Joris", "Jorry", "Keeton", "Kehinde", "Keiga","Leo",
                     "Leon", "Leona","Milosz", "Mir", "Mirza", "Mitch","Zac","Zubair"};


Crew::Crew() {
    cout<<"CREATING CREW"<<endl;
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
    return &captain;
}

Officer *Crew::getPilot() {
    return &pilot;
}

Officer *Crew::getEngineer() {
    return &engineer;
}

Officer *Crew::getMiner() {
    return &miner;
}

Officer *Crew::getWeaponSmith() {
    return &weaponSmith;
}


string casualty(void (*functocall)(string)){
    cout<< (*functocall)<<endl;
}

void generateOfficer(int lower,int upper, Officer* officer){
    *officer = Officer("tony",32,SkillSet(lower,upper));
}
