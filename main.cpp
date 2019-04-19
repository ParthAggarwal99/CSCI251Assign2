/**
 * NAME: ANTHONY SUKER
 * STUDENT ID: 6137210
 * LAB: FRIDAY 10:30
 */
#include <iostream>
#include "Officer.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Officer officer = Officer("Tony",32,SkillSet(50,100));
    cout <<officer.getName()<<" "<<officer.getAge()<<endl;
    cout <<officer.getSkillset().getEngineering()<<endl;
    return 0;
}