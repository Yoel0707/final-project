#include "Enemy.h"
#include <iostream>

using namespace std; 

Enemy::Enemy(string enemyName) 
: Character(enemyName) {
    health = 80; 
    attackPower = 20; 
}

int Enemy::getAttackPower() {
    return attackPower; 
}

void Enemy::attack() {
    cout << getName() << " attacks with majestical power " << attackPower << endl; 
}