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

while(choice !=1 && choice !=2) {
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

while(choice != 7) {
cout << "Current Day: " << day << endl;
cout << endl; 
cout << "=== The Quest of The Ages ===" << endl;
cout << "1. View Player" << endl; 
cout << "2. Travel" << endl;
cout << "3. View Inventory" << endl;
cout << "4. Talk to An NPC" << endl; 
cout << "5. View Location" << endl;
cout << "6. Challenge Farquad" << endl;
cout << "7. Quit Game" << endl;

cout << "Choose: ";
cin >> choice;


    if(choice == 1) {

            cout << "Player: " << player.getName() << endl;

            cout << "Health: " << player.gethealth() << endl;

        }

else if(choice == 2) {

int travelChoice;
if(currentLocation == 0)
{
    cout << "You are at the Wizard's Hut." << endl;
    cout << "1. Travel to Village" << endl;
    cout << "2. Travel to Cave" << endl;
    cout << "3. Travel to Magic Shop" << endl;
    cin >> travelChoice;

    if(travelChoice == 1)
    {
        cout << "You travel to the Village." << endl;
        currentLocation=1; 
        day++; 
    }
    else if(travelChoice == 2)
    {
        cout << "You travel to the Cave." << endl;
        currentLocation=2; 
        day++; 
    }
    else if(travelChoice == 3)
    {
        cout << "You travel to the Magic Shop." << endl;
        currentLocation=3; 
        day++; 
    }
    else
    {
        cout << "Invalid choice, you stay at the Wizard's Hut." << endl;
        currentLocation=0; 
    }
} 

else if(currentLocation == 1)
{
    cout << "You arrive at the Village." << endl;
    cout << "1. Wizard's Hut" << endl;
    cout << "2. Cave" << endl;
    cout << "3. Magic Shop" << endl;
    cin>> travelChoice;
    
    if(travelChoice == 1)
    {
        cout << "You enter the Wizard's Hut." << endl;
        currentLocation=0; 
        day++; 
}

else if(travelChoice == 2)
    {
        cout << "You enter the Cave." << endl;
    cout << "A Cave Troll appears!" << endl;
    battle(player, caveEnemy);
        currentLocation=2; 
        day++; 
    }
    else if(travelChoice == 3)
    {
        cout << "You enter the Magic Shop." << endl;
        currentLocation=3; 
        day++; 
    }
    else
    {
        cout << "Invalid choice, you stay in the Village." << endl;
        currentLocation=1; 
    }
}

else if(currentLocation==2)
{

cout << "You arrive at the Cave." << endl; 

}

else if(currentLocation == 3)
{
    cout << "You arrive at the Magic Shop." << endl;
}

else if(currentLocation == 4)
{
    cout << "You arrive at the Castle." << endl;
    cout << "A Dark Knight appears!" << endl;
    battle(player, castleEnemy);
}
if(day>10) {
        cout << "You ran out of time. Game Over." << endl;
        return 0; 
    }

else
{
    cout << "You cannot travel forward any further." << endl;
}

}

else if(choice == 3)
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


else if (choice==4){

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
else if(choice == 5)
{

cout << "+---------- The Quest of The Ages ----------+" << endl;
cout << endl; 
cout << "               [Farquad's Lair]" << endl;
cout << "                       |" << endl;
cout << "                   [Castle]" << endl;
cout << "                       |" << endl;
cout << "                    [Cave]" << endl; 
cout << "                       |" << endl;
cout << " [Wizard's Hut]--- [Village]---[Magic Shop]" << endl;
cout << endl; 
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
else if (choice == 6)
{
    if(currentLocation != 4)
    {
        cout << "You must reach the Castle to challenge Farquad." << endl;
    
    }
    else if (player.getSpells() < 3) 
    {
        cout << "You must collect 3 spells first." << endl;
    }

    else if(player.getArtifacts() < 2) 
    {
        cout << "You must collect 2 artifacts first." << endl;
    }
    else
    {
        cout << "You challenge Farquad!" << endl;
        battle(player, finalBoss);
        if (player.isalivedead())
        {
            cout << "Congratulations! You have defeated Farquad and saved the kingdom!" << endl;
            break; 
        }
        else
        {
            cout << "You were defeated by Farquad. Game Over." << endl;
            break; 
        }
    }
}
else if(choice == 7)
{
    cout << "Thanks for playing!" << endl;
}
else {

            cout << "Invalid choice, choose again.";

        }

}
return 0; 
}
