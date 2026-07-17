#include "player.h" 
#include <iostream>
using namespace std;

Player::Player(string playerName) : MainCharacter(playerName, 150) {

attackPower = 10; 
lightningSpells= 0;
fireSpells= 0;
iceSpells= 0;
dragonartifacts= 0;
crownartifacts=0;
energy= 100;
potions = 0;
energypotions = 0;
day = 1;
darkMagic = 0;
}

int Player::getAttackPower() {
    return attackPower;
}

int Player::attack() {
    return attackPower;
}
void Player::displaystats()
{
    cout << endl;
    cout << "Player: " << getName() << endl;
    cout << "Health: " << gethealth() << endl;
    cout << "Attack: " << attackPower << endl;
}
int Player::getIceSpells()
{
    return iceSpells;
}

int Player::getFireSpells()
{
    return fireSpells;
}

int Player::getLightningSpells()
{
    return lightningSpells;
}

int Player::getTotalSpells()
{
    return iceSpells + fireSpells + lightningSpells;
}

int Player::getdragonArtifact()
{
    return dragonartifacts;
}
void Player::collectIceSpell()
{
    iceSpells++;
}
void Player::collectFireSpell()
{
    fireSpells++;

}
void Player::collectLightningSpell()
{
    lightningSpells++;
}
void Player::collectcrownArtifact()
{
    crownartifacts++;
}

int Player::getcrownArtifact()
{
    return crownartifacts;
}
void Player::collectdragonArtifact()
{
    dragonartifacts++; 

}
void Player::addItem(Item item)
{
    inventory.push_back(item);
}

void Player::displayInventory()
{
    cout << "Inventory:" << endl;
    if(inventory.size() == 0)
    {
        cout << "Your inventory is empty." << endl;

        return;
    }


    for(int i = 0; i < inventory.size(); i++)
    {
        cout << i + 1 << ". " << inventory[i].getName() << " ("  << inventory[i].getType() << ")" << endl;

  //Tracks inventory

    }
}

int Player::getEnergy()
{
    return energy;
}

void Player::setEnergy(int amount)
{
    energy = amount;
}

void Player::loseEnergy(int amount)
{
    energy -= amount;

    if(energy < 0)
    {
        energy = 0;
    }
}

int Player::getDay()
{
    return day;
}

void Player::nextDay()
{
    day++;
}

int Player::getPotions()
{
    return potions;
}

void Player::addPotion()
{
    potions++;
}

void Player::usePotion()
{

    if (potions>0)
    {
    potions--;
    }
}

void Player::setHealth(int newHealth)
{
    health=newHealth;
}

int Player::getdarkmagic()
{
    return darkMagic;
}

void Player::usedarkmagic()
{
    darkMagic++;
}

int Player::getenergyPotions()
{
    return energypotions;
}

void Player::addenergyPotion()
{
    energypotions++;
}

void Player::useenergyPotion()
{
    if(energypotions > 0)
    {
        energypotions--;
    }
}
int Player::getTotalArtifacts()
{
    return dragonartifacts + crownartifacts;
}