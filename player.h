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
int iceSpells;
int fireSpells;
int lightningSpells;
int energy; 
int day; 
int potions; 
int energypotions; 
int darkMagic; 
int dragonartifacts; 
int crownartifacts; 
vector<Item> inventory;
public:
    Player(string playerName);
    int getAttackPower();
int attack(); 
    void displaystats();

    int getEnergy();
    void setEnergy(int amount);
void collectIceSpell();
void collectFireSpell();
void collectLightningSpell();
int getIceSpells();
int getFireSpells();
int getLightningSpells();
int getTotalSpells();
void addItem(Item item);
void displayInventory();
void loseEnergy(int amount);
int getDay();
void nextDay();
int getPotions();
void addPotion();
void usePotion();
int getenergyPotions();
void addenergyPotion();
void useenergyPotion();
void setHealth(int health);
int getdarkmagic(); 
void usedarkmagic();
void collectdragonArtifact(); 
void collectcrownArtifact(); 
int getcrownArtifact(); 
int getdragonArtifact(); 
int getTotalArtifacts();
};

#endif