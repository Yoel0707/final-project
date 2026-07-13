#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include <string>

using namespace std;

class MainCharacter {


public: 
MainCharacter(string characterName, int characterhealth);  
MainCharacter(); 

int gethealth();


void takeDamage(int damage); 
string getName(); 

string name; 
int health;
bool isalivedead(); 
};

#endif