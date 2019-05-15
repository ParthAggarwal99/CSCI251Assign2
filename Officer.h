//
// Created by Anthony Suker on 2019-04-19.
//

#ifndef CSCI251ASSIGN2_OFFICER_H
#define CSCI251ASSIGN2_OFFICER_H

#include "iostream"
#include "SkillSet.h"
#include "random"
#include <time.h>

static std::default_random_engine randEng(time(0));


using namespace std;

class Officer {
public:
    Officer();

    Officer(const string &name, int age, const SkillSet skillset);
    const SkillSet &getSkillset() const;
    const string &getName() const;
    int getAge() const;
private:
    string name;
    int age;
    SkillSet skillSet;
};

#endif //CSCI251ASSIGN2_OFFICER_H
