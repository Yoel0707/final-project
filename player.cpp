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

int Player::attack() {
    return attackPower;
}

void Player::takeDamage(int damage) {
    health -= damage;


if (health < 0) {
    health = 0; 

}
}
void Player::displaystats()
{
    cout << endl;
    cout << "Player: " << getName() << endl;
    cout << "Health: " << gethealth() << endl;
    cout << "Attack: " << attackPower << endl;
}

