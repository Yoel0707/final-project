#ifndef ENEMY_H
#define ENEMY_H



class Enemy : public Character {

private: 
int attackPower; 

public: 
Enemy(string enemyName); 

int getAttackPower();

void attack(); 

void takeDamage(int damage); 

};

#endif