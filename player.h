#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "maincharacter.h"
using namespace std;

class Player: public MainCharacter {
private:
    string name;
    int health;
    int attackPower;

public:
    Player(string playerName);

    string getName();
    int gethealth();
    int getAttackPower();
int attack(); 
    void takeDamage(int damage);
    void displaystats();
};

#endif