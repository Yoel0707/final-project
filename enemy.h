#ifndef ENEMY_H
#define ENEMY_H

#include "maincharacter.h"

class Enemy : public MainCharacter {

private: 
int attackPower; 

public: 
Enemy(string enemyName); 

int getAttackPower();

int attack(); 

};

#endif