//
// Created by Anthony Suker on 2019-04-19.
//

#ifndef CSCI251ASSIGN2_SKILLSET_H
#define CSCI251ASSIGN2_SKILLSET_H

class SkillSet {
public:
    SkillSet(int lower,int upper);

    double getNegotiation() const;
    double getPiloting() const;
    double getEngineering() const;
    double getMining() const;
    double getWeapons() const;

private:
    double negotiation;
    double piloting;
    double engineering;
    double mining;
    double weapons;

};
#endif //CSCI251ASSIGN2_SKILLSET_H
