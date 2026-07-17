#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include <string>

using namespace std;

class MainCharacter {

protected: 
    string name; 
    int health;

public: 
MainCharacter(string characterName, int characterhealth);  //Declaring Constructor 
MainCharacter(); 

int gethealth();


void takeDamage(int damage); 
string getName(); 

bool isalivedead(); //Checks if player/enemy is alive or dead 
};

#endif
