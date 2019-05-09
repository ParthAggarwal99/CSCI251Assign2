//
// Created by Anthony Suker on 2019-04-19.
//

#include "Officer.h"
#include "SkillSet.h"
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
    return skillset;
}
//endregion
