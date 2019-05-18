//
// Created by Anthony Suker on 2019-04-21.
//

#ifndef CSCI251ASSIGN2_SECTOR_H
#define CSCI251ASSIGN2_SECTOR_H

#include <random>
#include <time.h>
#include "string"
#include "Enemy.h"
#include "string"
#include "Alien.h"
#include "Ship.h"
#include "CombatManager.h"

class Sector{
public:
    Sector(Ship * ship,int counter);
    virtual ~Sector();
    bool escape(int skillLevel);
    virtual void arrive();
    virtual int options();
    virtual std::string interact();
    const Alien &getRace() const;

protected:
    std::string name;
    Alien race;
    Ship * ship;
    int counter;

    void trade();
    bool rollTrade();
    void mine();
};


class ShipSector: public Sector {
public:
    ShipSector(Ship *ship, int counter);

    void arrive();
    int options();
    Enemy * getEnemy();
private:
    Enemy enemy;
};

class PlanetSector: public Sector{
public:
    PlanetSector(Ship *ship, int counter);

    void arrive();
    int options();
    Enemy * getEnemy();
private:
    Enemy enemy;
};

class TradingSector: public Sector{
public:
    void arrive();
    int options();
private:
};

class EmptySector: public Sector{
    void arrive();
    int options();
};
class AstroidSector: public Sector{
    void arrive();
    int options();
};

#endif //CSCI251ASSIGN2_SECTOR_H
