//
// Created by Anthony Suker on 2019-04-17.
//

#include "Crew.h"
/**
 * generate crew
 * create casualty related functions
 *
 */

    //Generate first set Of officers for crew;
    Crew::Crew() :  captain(names[firstNameDist(randEng)],ageDist(randEng),SkillSet(60,100)) ,
                    pilot(names[firstNameDist(randEng)],ageDist(randEng),SkillSet(60,100)),
                    engineer(names[firstNameDist(randEng)],ageDist(randEng),SkillSet(60,100)),
                    miner (names[firstNameDist(randEng)],ageDist(randEng),SkillSet(60,100)),
                    weaponSmith(names[firstNameDist(randEng)],ageDist(randEng),SkillSet(60,100)){

    }




string casualty(void (*functocall)(string)){
    cout<< (*functocall)<<endl;
}

void generateOfficer(int lower,int upper, Officer* officer){
    *officer = Officer("tony",32,SkillSet(lower,upper));
}
