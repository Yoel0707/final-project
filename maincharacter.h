#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include <string>

using namespace std;

class MainCharacter {

protected: 
    string name; 
    int health;

public: 
MainCharacter(string characterName, int characterhealth);  
MainCharacter(); 

int gethealth();


void takeDamage(int damage); 
string getName(); 

bool isalivedead(); 
};

#endif
