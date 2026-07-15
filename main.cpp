#include <iostream>
#include <string>
#include <fstream>
#include "player.h"
#include "enemy.h"
#include "location.h"
using namespace std;


int displayMenu() {
    int choice; 
    cout << "=== The Quest of The Ages ===" << endl;
cout << "1. Play" << endl;
cout << "2. Quit" << endl;
cout << "Choose: " << endl; 
cin >> choice;
return choice; 
}


void displayStory()
{
    ifstream file("dialogue.txt");
    string line;
    while(getline(file,line))
    {
        cout << line << endl;
    }
    cout << endl;
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
choice = displayMenu();

if(choice ==2) {
    cout << "Leaving game...";
    return 0; 
}

else if(choice == 1) {
    displayStory();
}

else {
    cout << "Invalid choice, choose again.";
    return 0;
}
void story();
Player player("Shrek");
Enemy forestEnemy("Evil Wolf");
Location forest ("Dark Forest", "A dark and eerie forest filled with dangerous creatures.");
cout << "Your journey begins!" << endl;

while(choice != 5) {

cout << "=== The Quest of The Ages ===" << endl;
cout << "1. View Player" << endl; 
cout << "2. Travel Forward" << endl;
cout << "3. Travel Backward" << endl;
cout << "4. View Inventory" << endl;
cout << "5. Quit" << endl; 

cout << "Choose: ";
cin >> choice;


    if(choice == 1) {

            cout << "Player: " << player.getName() << endl;

            cout << "Health: " << player.gethealth() << endl;

        }

else if(choice == 2) {

    cout << "You travel through the Dark Forest..." << endl;
    cout << "An Evil Wolf appears!" << endl;

    battle(player, forestEnemy);

}

else if(choice == 3) {

    cout << "You travel backward to the previous area." << endl;

}


else if(choice == 4)
{
    cout << endl;
    cout << "===== INVENTORY =====" << endl;

    cout << "Spells: "
         << player.getSpells()
         << endl;

    cout << "Artifacts: "
         << player.getArtifacts()
         << endl;

    player.displayInventory();

    cout << endl;
}




else if(choice == 5)
{
    cout << "Thanks for playing!" << endl;
}
else {

            cout << "Invalid choice, choose again.";

        }

}

return 0; 


}