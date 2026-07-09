#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
private:
    string name;
    int health;
    int attackPower;

public:
    Player(string playerName);

    string getName();
    int gethealth();
    int getAttackPower();

    void takeDamage(int damage);
};

#endif