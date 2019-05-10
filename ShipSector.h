//
// Created by Anthony Suker on 2019-05-10.
//

#ifndef CSCI251ASSIGN2_SHIPSECTOR_H
#define CSCI251ASSIGN2_SHIPSECTOR_H

#include "Sector.h"

/**
 * TODO:
 * Add ship enemies to this class
 */

class ShipSector: public Sector {
public:
    ShipSector(const std::string &name, int escapeChance);
    std::string arrive();
    std::string interact();
private:

};


#endif //CSCI251ASSIGN2_SHIPSECTOR_H
