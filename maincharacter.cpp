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

bool MainCharacter::isalivedead() {
    return health > 0; 
}
MainCharacter::MainCharacter()
{
    health = 100;
}