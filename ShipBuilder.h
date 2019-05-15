//
// Created by Anthony on 2/05/2019.
//

#ifndef CSCI251ASSIGN2_SHIPBUILDER_H
#define CSCI251ASSIGN2_SHIPBUILDER_H

#include <vector>
#include "Hull.h"
#include "Hardpoint.h"
#include "Engine.h"

extern std::vector<Hull> hullList;
extern std::vector<Hardpoint> hpList;
extern std::vector<Engine> engineList;

void fillLists();
Hull * makeHull();
Hardpoint * makeHardPoint();
Engine * makeEngine();





#endif //CSCI251ASSIGN2_SHIPBUILDER_H
