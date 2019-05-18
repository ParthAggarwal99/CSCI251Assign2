//
// Created by Anthony Suker on 2019-05-10.
//
#include <iostream>
#include "Sector.h"


using namespace std;

/**
 * RETURN OPTIONS
 *
 *  00: do nothing
 *
 *  10: attempt trade
 *  11: purchase fuel
 *  12: purchase food
 *  13: sell ore
 *  14: buy dmg upgrade
 *  15: buy armor upgrade
 *  16: buy max health
 *
 *  20: intiate combat
 *
 */

//region Base Sector

std::string sectorNamePt1[] = {"Giga", "Fido", "Mono", "Litho", "Pragma", "Gigo", "Lipzo", "Korna"};
std::string sectorNamePt2[] = {"tron", "lon", "lantis", "prong", "prime", "shak", "boon", "quon"};

Sector::~Sector() {

}

Sector::Sector(Ship *ship, int counter) {
    Sector::counter=counter;
    Sector::ship = ship;
    srand(time(0));
    name = sectorNamePt1[rand() % 8] + sectorNamePt2[rand() % 8];
}

/**
 * Escape chance is skill Level of pilot divide by 5
 * @param skillLevel
 * @return
 */
bool Sector::escape(int skillLevel) {
    srand(time(0));
    if (rand() % 101 > (skillLevel / 5)) {
        return false;
    } else {
        return true;
    }
}

const Alien &Sector::getRace() const {
    return race;
}

void Sector::arrive() {
    cout << "you shouldn't see this" << endl;
}

int Sector::options() {
    cout << "you shouldn't see this" << endl;
}

std::string Sector::interact() {
    return "you shouldn't see this";
}

void Sector::trade() {
    ship->printCoreStats();

    cout << "1::REFUEL - $75 " << endl
         << "2::RESUPPLY FOOD - $75 " << endl
         << "3::SELL ORE -  $200ea" << endl
         << "4::BUY DMG UP - +75 @ $300" << endl
         << "5::BUY ARMOR UP - +100 @ $ 500" << endl
         << "6::BUY MAX HP UP (INCLUDES FULL REPAIR) - +500HP @ $750" << endl
         << "0::LEAVE" << endl;


    int option;
    bool goodOption = true;
    do {
        goodOption = true;
        try {
            cin >> option;
        } catch (exception &e) {
            goodOption = false;
            cerr << "I DONT THINK THAT'S A NUMBER" << endl << e.what() << endl;
        }
    } while (!goodOption);

    srand(time(0));
    bool critBuy = false;
    int multiplier = 1;
    srand(time(0));
    if ((rand() % 1000) < ship->getCrew()->getCaptain()->getSkillset().getNegotiation()) {
        if (option == 3) {
            cout << "TRADING CRIT!!! ORE SOLD FOR DOUBLE VALUE" << endl;
        } else {
            cout << "TRADING CRIT!!! ITEM BOUGHT FOR FREE" << endl;
        }
        critBuy = true;
        multiplier = 0;
    }

    do {
        switch (option) {

            case 1:
                if (ship->minusMoney(75 * multiplier)) {
                    ship->refuel();
                }
                break;

            case 2:
                if (ship->minusMoney(75 * multiplier)) {
                    ship->refillFood();
                }
                break;

            case 3:
                if (critBuy) {
                    ship->addMoney(400 * ship->getOre());

                } else {
                    ship->addMoney(200 * ship->getOre());
                }
                break;

            case 4:
                if (ship->minusMoney(300)) {
                    ship->getHardpoint()->increaseDamage(75);
                }
                break;

            case 5:
                if (ship->minusMoney(500)) {
                    ship->getHull()->increaseArmor(100);
                }
                break;

            case 6:
                if (ship->minusMoney(750)) {
                    ship->addMaxHp(500);
                }

            case 0:
                cout << "YOU PURCHASE NOTHING AND MOVE ON TO THE NEXT SECTOR" << endl;

            default:
                cout << "THAT IS NOT A VALID OPTION" << endl << endl;

        }
    } while (option != 0);
}

bool Sector::rollTrade() {
    int chance = ship->getCrew()->getCaptain()->getSkillset().getNegotiation();
    srand(time(0));
    if(race.isTrade()){
        if(race.isHostile()){
            chance = chance/2;
        }
        if(rand()%101<chance){
            return  true;
        }
    }
    return false;
}

void Sector::mine() {
    cout<<"YOU BEGIN TO MINE"<<endl;
    int yield = ship->getHardpoint()->getMiningEff();
    srand(time(0));
    for(int x = 0; x<ship->getCrew()->getCrewSize();x++){
        if(rand()%151<ship->getCrew()->getMiner()->getSkillset().getMining()){
            yield++;
            cout<<"SUCCESS, YOU FOUND SOME ORE"<<endl;
        } else{
            cout<<"FAIL, YOU DID NOT FOUND ORE"<<endl;
        }
    }
    ship->addOre(yield);
}
//endregion


//region ShipSector

ShipSector::ShipSector(Ship *ship, int counter) : Sector(ship, counter) {
    enemy.enhance(race.getCombatAbility());
}

void ShipSector::arrive() {

    cout<< "You have a Arrived at a new Sector, There is another spaceship In front of you. You dont know if they are hostile or not"
            << endl;
}

int ShipSector::options() {
    cout << "1::ATTACK" << endl <<
         "2::REPAIR" << endl <<
         "3::ATTEMPT TRADE" << endl <<
         "4::IDENTIFY" <<endl<<
         "0::LEAVE" << endl;

    int option;
    bool goodOption = true;
    do {
        goodOption = true;
        try {
            cin >> option;
        } catch (exception &e) {
            goodOption = false;
            cerr << "I DONT THINK THAT'S A NUMBER" << endl << e.what() << endl;
        }

        switch (option) {
            case 1: {
                CombatManager cm = CombatManager(ship, &enemy);
                cm.beginInstance();
                break;
            }
            case 2:{
                ship->repair(false);
                goodOption = false;
            }

            case 3: {
                if (rollTrade()) {
                    trade();
                } else if (race.isHostile()) {
                    cout << "THEY DECLINE YOUR TRADE AND OPEN FIRE ON YOU" << endl;
                    CombatManager cm = CombatManager(ship, &enemy);
                    cm.beginInstance();
                }
                break;
            }

            case 4:{
                race.printStats();
            }
            case 0: {
                escape(10);
                break;
            }

            default:
                goodOption = false;
                cout << "THAT IS NOT A VALID OPTION" << endl;

        }
    } while (!goodOption);
}

Enemy *ShipSector::getEnemy() {
    return &enemy;
}




//endregion


//region PlanetSector

PlanetSector::PlanetSector(Ship *ship, int counter) : Sector(ship, counter) {
    enemy.randomizeStats(counter);
    enemy.enhance(race.getCombatAbility());
}

void PlanetSector::arrive() {
    cout << "You arrive at a planet inhabited by the " << race.getName() << endl;
}

int PlanetSector::options() {
    cout << "1::ATTEMPT TRADE" << endl
         << "2::INTIATE COMBAT" << endl
         << "3::MINE" << endl
         << "4::LEAVE" << endl;

    int option;
    bool goodOption = true;
    do {
        goodOption = true;
        try {
            cin >> option;
        } catch (exception &e) {
            goodOption = false;
            cerr << "I DONT THINK THAT'S A NUMBER" << endl << e.what() << endl;
        }

        switch (option) {
            case 1: {
                if (rollTrade()) {
                    trade();
                } else if (race.isHostile()) {
                    cout << "THEY DECLINE YOUR TRADE AND OPEN FIRE ON YOU" << endl;
                    CombatManager cm = CombatManager(ship, &enemy);
                    cm.beginInstance();
                }
                break;
            }

            case 2: {
                CombatManager cm = CombatManager(ship, &enemy);
                cm.beginInstance();
                break;
            }

            case 3: {
                cout<<"YOU BEGIN TO MINE"<<endl;
                mine();
                break;
            }

            case 4:{

            }

            default:
                goodOption = false;
                cout << "THAT IS NOT A VALID OPTION" << endl;

        }
    } while (!goodOption);
}

Enemy *PlanetSector::getEnemy() {
    return &enemy;
}

//endregion


//region TradingSector

void TradingSector::arrive() {
    cout << "You arrive at a trading sector owned by the " << race.getName() << endl;
}

int TradingSector::options() {
    cout << "1::TRADE" << endl
         << "2::LEAVE" << endl;

    int option;
    bool goodOption = true;
    do {
        goodOption = true;
        try {
            cin >> option;
        } catch (exception &e) {
            goodOption = false;
            cerr << "I DONT THINK THAT'S A NUMBER" << endl << e.what() << endl;
        }

        switch (option) {
            case 1:
                trade();
                break;
            case 2:
                cout << "YOU HAVE LEFT THIS SECTOR" << endl << endl;
                return 00;
            default:
                goodOption = false;
                cout << "THAT IS NOT A VALID OPTION" << endl;
        }

    } while (!goodOption);
}

//endregion


//region Empty Sector

void EmptySector::arrive() {
    cout << "You arrive at an empty sector. There is nothing to do here." << endl;
}

int EmptySector::options() {
    cout << "Theres nothing to do here" << endl;
    system("pause");
    return 00;
}
//endregion


//region Astroid Sector

void AstroidSector::arrive() {
    ship->minusHealth(50);
    cout << "You arrive in an Astroid belt. You're ship is pummeled with debris\n-50 hp" << endl;
}

int AstroidSector::options() {
    cout << "Theres nothing to do here" << endl;
    system("pause");
    return 00;
}
//endregion




