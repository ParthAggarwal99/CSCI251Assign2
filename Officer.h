//
// Created by Anthony Suker on 2019-04-19.
//

#ifndef CSCI251ASSIGN2_OFFICER_H
#define CSCI251ASSIGN2_OFFICER_H

#include "iostream"
#include "random"
#include <time.h>

static std::default_random_engine randEng(time(0));


using namespace std;

class SkillSet {
public:
    SkillSet();
    void reroll(int upper,int lower);

    int getNegotiation() const;
    int getPiloting() const;
    int getEngineering() const;
    int getMining() const;
    int getWeapons() const;

private:
    int negotiation;
    int piloting;
    int engineering;
    int mining;
    int weapons;

};

class Officer {
public:
    Officer();

    Officer(const SkillSet &skillSet);

    Officer(int upper,int lower);
    const SkillSet &getSkillset() const;
    const string &getName() const;
    int getAge() const;
    void print();
    void reroll(int count);
private:
    string name;
    int age;
    SkillSet skillSet;
};



#endif //CSCI251ASSIGN2_OFFICER_H
