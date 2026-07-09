#include <iostream>
#include "player.h"
#include "enemy.h"

using namespace std;


int main() {

Player player("Shrek");
Enemy sorcerer("Odin");


int choice = 0;


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

