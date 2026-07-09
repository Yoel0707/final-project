#include <iostream>
#include "player.h"
#include "enemy.h"

using namespace std;


int main() {

    Player player("Shrek", 100, 50);
    Enemy sorcerer("Odin", 150, 20);


    int choice = 0;


    while(choice != 3) {

        cout << "=== Fantasy Adventure ===";
        cout << "1. View Player";
        cout << "2. Attack Enemy";
        cout << "3. Quit";

        cout << "Choose: ";
        cin >> choice;


        if(choice == 1) {

            cout << "Player: " << player.getName() << endl;

            cout << "Health: " << player.gethealth() << endl;

        }

else if(choice == 2) {

    player.attack();
    sorcerer.takeDamage(10);

    cout << "Enemy Health: " << sorcerer.getHealth() << endl;

        }

else if(choice == 3) {

            cout << "Leaving game...";

        }

        else {

            cout << "Invalid choice.";

        }

    }


    return 0;
}