#include "player.h" 
#include <iostream>
using namespace std;

Player::Player(string playerName) : MainCharacter(playerName, 150) {

attackPower = 10; 
spells= 0;
artifacts= 0;
energy= 100;
void setEnergy(int amount);
void nextDay();
void loseEnergy(int amount);
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

void Player::collectSpell()
{
    spells++;
}

void Player::collectArtifact()
{
    artifacts++;
}

int Player::getSpells()
{
    return spells;
}

int Player::getArtifacts()
{
    return artifacts;
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