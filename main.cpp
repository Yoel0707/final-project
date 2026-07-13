#include <iostream>
#include "player.h"
#include "enemy.h"

using namespace std;


void displayMenu() {
    cout << "=== The Quest of The Ages ===" << endl;
cout << "1. Play" << endl;
cout << "2. Quit" << endl;
cout << "Choose: " << endl; 
}

void story() {
    cout << "In a world where darkness reigns, a hero emerges from the gutter to challenge the great forces of evil." << endl;
    cout << "You are Shrek, a brave warrior on a quest to defeat the sorcerer Odin and restore peace in the precious land." << endl;
    cout << "Prepare for battle and make your choices wisely for the kingdom!" << endl;
}





void battle(Player player, Enemy enemy)
{
    while (player.isalivedead() && enemy.isalivedead())
    {
cout << player.getName() << " attacks gracefully!" << endl;

    enemy.takeDamage(player.attack());

        cout << enemy.getName() << " health: "
             << enemy.gethealth() << endl;


if (enemy.isalivedead())
    {
            cout << endl;

            cout << enemy.getName() << " attacks!" << endl;

            player.takeDamage(enemy.attack());

            cout << player.getName() << " health: "
                 << player.gethealth() << endl;
        }
    }


    if (player.isalivedead())
    {
        cout << endl;
        cout << "You defeated the enemy!" << endl;
    }
    else
    {
        cout << endl;
        cout << "You were defeated." << endl;
    }
}



int main() {
int choice; 
displayMenu();

if(choice ==2) {
    cout << "Leaving game...";
    return 0; 
}

else if(choice == 1) {
    story();
}

else {
    cout << "Invalid choice, choose again.";
}

Player player("Shrek");
Enemy sorcerer("Odin");

cout << "Your journey begins!" << endl;

while(choice != 3) {

cout << "=== The Quest of The Ages ===" << endl;
cout << "1. View Player" << endl; 
cout << "2. Attack Enemy" << endl; 
cout << "3. Quit" << endl; 

cout << "Choose: ";
cin >> choice;


    if(choice == 1) {

            cout << "Player: " << player.getName() << endl;

            cout << "Health: " << player.gethealth() << endl;

        }

else if(choice == 2) {

    player.attack();
    sorcerer.takeDamage(10);

    cout << "Enemy Health: " << sorcerer.gethealth() << endl;

        }

else if(choice == 3) {

            cout << "Leaving game...";

        }

        else {

            cout << "Invalid choice, choose again.";

        }

    }


    return 0;
}

