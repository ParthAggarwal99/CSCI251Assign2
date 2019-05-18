//
// Created by Anthony Suker on 2019-04-19.
//

#include "Officer.h"


string names [19] = {"Aaren", "Aarez","Alum", "Alvern", "Jorge", "Joris", "Jorry", "Keeton", "Kehinde", "Keiga","Leo",
                     "Leon", "Leona","Milosz", "Mir", "Mirza", "Mitch","Zac","Zubair"};




Officer::Officer() {

    std::uniform_int_distribution<unsigned> nameDist(0,18);
   //
    try {
        name = names[nameDist(randEng)];
    }catch(std::out_of_range){
        cerr<<"OUT OF RANGE @ OFFICER CONSTRUCTOR"<<endl;
    }
    age = rand()%52 + 18;
}


SkillSet::SkillSet() {
    std::uniform_int_distribution<unsigned> OfficerDistribution(70,100);
    negotiation = OfficerDistribution(randEng);
    piloting = OfficerDistribution(randEng);
    engineering = OfficerDistribution(randEng);
    mining = OfficerDistribution(randEng);
    weapons = OfficerDistribution(randEng);
}


void SkillSet::reroll(int upper, int lower) {
    std::uniform_int_distribution<unsigned> OfficerDistribution(upper,lower);
    negotiation = OfficerDistribution(randEng);
    piloting = OfficerDistribution(randEng);
    engineering = OfficerDistribution(randEng);
    mining = OfficerDistribution(randEng);
    weapons = OfficerDistribution(randEng);
}



//region Getters


const string &Officer::getName() const {
    return name;
}

int Officer::getAge() const {
    return age;
}

int SkillSet::getNegotiation() const {
    return negotiation;
}

int SkillSet::getPiloting() const {
    return piloting;
}

int SkillSet::getEngineering() const {
    return engineering;
}

int SkillSet::getMining() const {
    return mining;
}

int SkillSet::getWeapons() const {
    return weapons;
}

const SkillSet &Officer::getSkillset() const {
    return skillSet;
}

void Officer::print() {
    cout<<"NAME: "<<name<<"  SKILLS: N"<<
    skillSet.getNegotiation()<<" : P"<<skillSet.getPiloting()
    <<" : M"<<skillSet.getMining()<<" : E"<<skillSet.getEngineering()
    <<" : W"<<skillSet.getWeapons()<<endl;
}

void Officer::reroll(int count) {
    int upper = 100-(5*count);
    int lower = 70 -(5*count);
    skillSet.reroll(upper,lower);
    std::uniform_int_distribution<unsigned> nameDist(0,18);
    name = names[nameDist(randEng)];
}



//endregion
