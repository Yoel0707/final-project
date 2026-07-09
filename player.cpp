#include "player.h" 
#include <iostream>
using namespace std;

Player::Player(string playerName) {
    name = playerName;
    health = 150; 
    attackPower = 10; 
}

string Player::getName() {
    return name;
}

int Player::gethealth() {
    return health;
}

int Player::getAttackPower() {
    return attackPower;
}

void Player::attack() {
    cout << name << " uses all his power and attacks!!!! " << attackPower << endl; 
}

void Player::takeDamage(int damage) {
    health -= damage;


if (health < 0) {
    health = 0; 

}
}
