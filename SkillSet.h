//
// Created by Anthony Suker on 2019-04-19.
//

#ifndef CSCI251ASSIGN2_SKILLSET_H
#define CSCI251ASSIGN2_SKILLSET_H

class SkillSet {
public:
    SkillSet(int lower,int upper);

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
#endif //CSCI251ASSIGN2_SKILLSET_H
