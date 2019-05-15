//
// Created by Anthony Suker on 2019-05-10.
//
/**
 * TODO:
 * CREATE COMBAT SYSTEM TO START COMBAT
 */

#include "ShipSector.h"

ShipSector::ShipSector(const std::string &name, int escapeChance) : Sector(name, escapeChance) {}

std::string ShipSector::arrive() {
    return "You have a Arrived at a new Sector, There is another spaceship infront of you. You dont know if they are hostile or not";
}


