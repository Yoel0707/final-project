#include "maincharacter.h"

MainCharacter::MainCharacter(string characterName, int characterhealth) {
    name = characterName;
    health = characterhealth;
}

int MainCharacter::gethealth() {
    return health;
}

string MainCharacter::getName() {
    return name;
} 

void MainCharacter::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0; 
    }
}