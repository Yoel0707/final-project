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

while(choice !=1&& choice !=2) {
cout << "Invalid choice, choose again." << endl;
choice = displayMenu();
}

if (choice == 2) {
cout << "Thanks for playing!" << endl;
return 0;
}
if (choice == 1) {
displayStory();
}
int day=1; 
int currentLocation = 0;
Player player("Shrek");
Location village("Village", "A small village with friendly villagers.");
Enemy caveEnemy("Cave Troll");
Location cave ("Cave", "A dark and damp cave, home to a fearsome troll.");
Enemy castleEnemy("Dark Knight");
Location castle ("Castle", "A grand castle, home to a powerful dark knight.");
Enemy finalBoss("Farquad");
Location finalBossLocation ("Farquad's Lair", "A fiery lair where Farquad resides.");
Location shop("Magic Shop", "A mystical shop where you can buy useful items.");
cout << "Your journey begins!" << endl;

while(choice != 8) {

cout << "=== The Quest of The Ages ===" << endl;
cout << "1. View Player" << endl; 
cout << "2. Travel Forward" << endl;
cout << "3. Travel Backward" << endl;
cout << "4. View Inventory" << endl;
cout << "5. Talk to An NPC" << endl; 
cout << "6. View Location" << endl;
cout << "7. Challenge Farquad" << endl;
cout << "8. Quit Game" << endl;

cout << "Choose: ";
cin >> choice;


    if(choice == 1) {

            cout << "Player: " << player.getName() << endl;

            cout << "Health: " << player.gethealth() << endl;

        }

else if(choice == 2) {

   day++;

if(currentLocation < 4)
{
    currentLocation++;
}

cout << endl;

if(currentLocation == 1)
{
    cout << "You arrive at the Village." << endl;
}

else if(currentLocation == 2)
{
    cout << "You arrive at a Cave." << endl;
}

else if(currentLocation == 3)
{
    cout << "You arrive at the Magic Shop." << endl;
}

else if(currentLocation == 4)
{
    cout << "You arrive at the Castle." << endl;
}

}

else if(choice == 3) {
day++; 

if (currentLocation > 0)
{
    currentLocation--;

    cout << "You travel backward to the previous area." << endl;

}

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


else if (choice==5){

if (currentLocation==0){

cout << "The Wizard says: I wish you the best of luck, save the kingdom!" << endl;


}

else if (currentLocation==1){
cout << "The villagers say: Thank you for helping us againist evil please rest!" << endl;

}
else if (currentLocation==2){
cout << "The Cave Troll says: You will not defeat me!" << endl;

}
else if (currentLocation==3){
cout << "The shopkeeper says: Powerful artificats and spells await!" << endl;

}
else if (currentLocation==4){

cout << "The King says: Save Us!!" << endl;

}
}
else if(choice == 6)
{
    if(currentLocation == 0)
    {
        cout << "You are at the starting point of your journey." << endl;
    }
    else if(currentLocation == 1)
    {
        cout << village.getdescription() << endl;
    }
    else if(currentLocation == 2)
    {
        cout << cave.getdescription() << endl;
    }
    else if(currentLocation == 3)
    {
        cout << shop.getdescription() << endl;
    }
    else if(currentLocation == 4)
    {
        cout << castle.getdescription() << endl;
    }
}
else if (choice == 7)
{
    if(currentLocation == 4)
    {
        cout << "You challenge Farquad!" << endl;
        battle(player, finalBoss);
    }
    else
    {
        cout << "You must be at the Castle to challenge Farquad." << endl;
    }
}
else if(choice == 8)
{
    cout << "Thanks for playing!" << endl;
}
else {

            cout << "Invalid choice, choose again.";

        }

}
return 0; 
}
