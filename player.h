#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include "maincharacter.h"
#include "item.h"
using namespace std;

class Player: public MainCharacter {
private:
    int attackPower;
int spells; 
int artifacts;
int energy; 
int day; 
int potions; 
vector<Item> inventory;
public:
    Player(string playerName);
    int getAttackPower();
int attack(); 
    void displaystats();

    int getEnergy();
    void setEnergy(int amount);
int getSpells(); 
int getArtifacts();
void collectSpell();
void collectArtifact();
void addItem(Item item);
void displayInventory();
void loseEnergy(int amount);
int getDay();
void nextDay();
int getPotions();
void addPotion();
void usePotion();
void setHealth(int health);
};

#endif