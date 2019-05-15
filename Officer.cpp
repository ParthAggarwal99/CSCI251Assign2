//
// Created by Anthony Suker on 2019-04-19.
//

#include "Officer.h"


string names [19] = {"Aaren", "Aarez","Alum", "Alvern", "Jorge", "Joris", "Jorry", "Keeton", "Kehinde", "Keiga","Leo",
                     "Leon", "Leona","Milosz", "Mir", "Mirza", "Mitch","Zac","Zubair"};


Officer::Officer(const string &name, int age, const SkillSet skillset) : name(name), age(age), skillSet(skillset) {}


Officer::Officer() {
    srand(time(0));
    try {
        name = names[rand() % 20];
    }catch(std::out_of_range){
        cerr<<"OUT OF RANGE @ OFFICER CONSTRUCTOR"<<endl;
    }
    age = rand()%52 + 18;
}


SkillSet::SkillSet(int upper,int lower) {
    std::uniform_int_distribution<unsigned> OfficerDistribution(upper,lower);
    negotiation = OfficerDistribution(randEng);
    piloting = OfficerDistribution(randEng);
    engineering = OfficerDistribution(randEng);
    mining = OfficerDistribution(randEng);
    weapons = OfficerDistribution(randEng);
}

SkillSet::SkillSet() {
    std::uniform_int_distribution<unsigned> OfficerDistribution(70,100);
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

//endregion
