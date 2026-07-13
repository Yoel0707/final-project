#include "enemy.h"
#include <iostream>

using namespace std; 

Enemy::Enemy(string enemyName) 
: MainCharacter(enemyName, 80) {
    attackPower = 20; 
}

int Enemy::getAttackPower() {
    return attackPower; 
}

int Enemy::attack() {
    cout << name << " attacks with majestical power " << attackPower << endl;
    return attackPower;
}