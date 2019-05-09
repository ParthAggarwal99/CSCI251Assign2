/**
 * NAME: ANTHONY SUKER
 * STUDENT ID: 6137210
 * LAB: FRIDAY 10:30
 */

using namespace std;
#include <iostream>
#include "ShipBuilder.h"

/**
 * TODO:
 *  find out how to do getters for inherited classes
 */

int main() {

    fillLists();

    Hull * hull;

    hull = getHull();

    cout<<hull->getName()<<endl;

    return 0;
}