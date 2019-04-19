//
// Created by Anthony Suker on 2019-04-19.
//

#include "Officer.h"
#include "random"



Officer::Officer(const string &name, int age, const SkillSet skillset) : name(name), age(age), skillset(skillset) {}



SkillSet::SkillSet(int upper,int lower) {
    std::uniform_int_distribution<unsigned> OfficerDistribution(upper,lower);
    negotiation = OfficerDistribution(randEng);
    piloting = OfficerDistribution(randEng);
    engineering = OfficerDistribution(randEng);
    mining = OfficerDistribution(randEng);
    weapons = OfficerDistribution(randEng);
}


//region Getters

double SkillSet::getNegotiation() const {
    return negotiation;
}

double SkillSet::getPiloting() const {
    return piloting;
}

double SkillSet::getEngineering() const {
    return engineering;
}

double SkillSet::getMining() const {
    return mining;
}

double SkillSet::getWeapons() const {
    return weapons;
}


const string &Officer::getName() const {
    return name;
}

int Officer::getAge() const {
    return age;
}

const SkillSet &Officer::getSkillset() const {
    return skillset;
}
//endregion
