#include <iostream>
#include <string>
#include <fstream>
#include "player.h"
#include "enemy.h"
#include "location.h"
using namespace std;

// Displays the starting menu allowing the player to play or quit.
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
// Creates the player, enemies, and all game locations.
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

// Main game loop that continues until the player quits or wins/loses.
while(choice != 9) {
cout << "Current Day: " << day << endl;
cout << endl; 
cout << "=== The Quest of The Ages ===" << endl;
cout << "1. View Player" << endl; 
cout << "2. Travel" << endl;
cout << "3. View Inventory" << endl;
cout << "4. Use Potion" << endl; 
cout << "5. Use Energy Potion" << endl; 
cout << "6. Talk to An NPC" << endl; 
cout << "7. View Location" << endl;
cout << "8. Challenge Farquad" << endl;
cout << "9. Quit Game" << endl;

cout << "Choose: ";
cin >> choice;

if (player.getEnergy() <= 0) {
    cout << "You collapsed from exhaustion. Game Over." << endl;
    return 0;
}

    if(choice == 1) {

            cout << "Player: " << player.getName() << endl;

            cout << "Health: " << player.gethealth() << endl;

        }
// Main game loop that continues until the player quits or wins/loses.
else if(choice == 2) {

int travelChoice;
// Wizard's Hut travel options.
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
        player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
    }
    else if(travelChoice == 2)
    {
        cout << "You enter the Cave." << endl;
        currentLocation=2; 
        day++; 
        player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
    }
    else if(travelChoice == 3)
    {
        cout << "You travel to the Magic Shop." << endl;
        currentLocation=3; 
        day++; 
        player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
    }
    else
    {
        cout << "Invalid choice, you stay at the Wizard's Hut." << endl;
        currentLocation=0; 
    }
} 
// Village travel options 
else if(currentLocation == 1)
{
    cout << "You arrive at the Village." << endl;
    cout << "1. Wizard's Hut" << endl;
    cout << "2. Cave" << endl;
    cout << "3. Magic Shop" << endl;
    cout << "4. Castle" << endl; 
    cin>> travelChoice;
    
    if(travelChoice == 1)
    {
        cout << "You enter the Wizard's Hut." << endl;
        currentLocation=0; 
        day++; 
        player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
}

else if(travelChoice == 2)
    {
    cout << "You enter the Cave." << endl;
    cout << "A Cave Troll appears!" << endl;
    player.loseEnergy(10); 
while(player.isalivedead() && caveEnemy.isalivedead())
    {
        cout << player.getName() << " attacks gracefully!" << endl;

        caveEnemy.takeDamage(player.attack());

        cout << caveEnemy.getName() << " health: " << caveEnemy.gethealth() << endl;

        if(caveEnemy.isalivedead())
        {
            cout << endl;

            cout << caveEnemy.getName() << " attacks!" << endl;

            player.takeDamage(caveEnemy.attack());

            cout << player.getName() << " health: " << player.gethealth() << endl;
        }
    }

    if(player.isalivedead())
    {
        cout<<"You defeated the Cave Troll!"<<endl;

        cout<<"You found an Ancient Crown!"<<endl;

        player.collectcrownArtifact();

        currentLocation=2;

        day++;
    }

    else
    {
        cout<<"Game Over."<<endl;
        return 0;
    }

    }
    else if(travelChoice == 3)
    {
        cout << "You enter the Magic Shop." << endl;
        currentLocation=3; 
        day++; 
        player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
    }

    else if(travelChoice == 4){
    cout << "You arrive at the Castle." << endl;
    cout << "A Dark Knight appears!" << endl;
    player.loseEnergy(10); 
    while(player.isalivedead() && castleEnemy.isalivedead())
    {
        cout << player.getName() << " attacks gracefully!" << endl;

        castleEnemy.takeDamage(player.attack());

        cout << castleEnemy.getName() << " health: " << castleEnemy.gethealth() << endl;

        if(castleEnemy.isalivedead())
        {
            cout << endl;

            cout << castleEnemy.getName() << " attacks!" << endl;

            player.takeDamage(castleEnemy.attack());

            cout << player.getName() << " health: " << player.gethealth() << endl;
        }
    }

    if(player.isalivedead())
    {
        cout<<"You defeated the Dark Knight!"<<endl;

        cout<<"You found the Dragon Crystal!"<<endl;

        player.collectdragonArtifact();

        cout << "1. Wizard's Hut" << endl;
        cout << "2. Village" << endl;
        cout << "3. Cave" << endl;
        cout << "4. Magic Shop" << endl;
        cout << "5. Farquad's Lair" << endl;
        cin >> travelChoice;
        
        if(travelChoice == 1) { 
            currentLocation = 0; day++; 
            player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
        }
        else if(travelChoice == 2) { 
            currentLocation = 1; day++; 
            player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
        }
        else if(travelChoice == 3) { 
            currentLocation = 2; day++;
            player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl;  
        }
        else if(travelChoice == 4) { 
            currentLocation = 3; day++; 
            player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
        }
        else if(travelChoice == 5) { 
            currentLocation = 5; day++; 
            player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
        }
    }
    else
    {
        cout << "Game Over." << endl;
        return 0;
    }
}
    else
    {
        cout << "Invalid choice, you stay in the Village." << endl;
        currentLocation=1; 
    }
}
// Cave travel options.
else if(currentLocation==2)
{

cout << "You arrive at the Cave." << endl; 
cout << "1. Wizard's Hut" << endl;
cout << "2. Village" << endl;
cout << "3. Magic Shop" << endl;
cout << "4. Castle" << endl;
cin >> travelChoice;
    
    if(travelChoice == 1)
    {
        cout << "You travel to the Wizard's Hut." << endl;
        currentLocation = 0;
        day++;
        player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
    }
    else if(travelChoice == 2)
    {
        cout << "You travel to the Village." << endl;
        currentLocation = 1;
        day++;
        player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
    }
    else if(travelChoice == 3)
    {
        cout << "You travel to the Magic Shop." << endl;
        currentLocation = 3;
        day++;
        player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
    }
    else if(travelChoice == 4)
    {
        cout << "You travel to the Castle." << endl;
        currentLocation = 4;
        day++;
        player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
    }
    else
    {
        cout << "Invalid choice, you stay in the Cave." << endl;
        currentLocation = 2;
    }
}


// Magic Shop travel options.
else if(currentLocation == 3)
{
    cout << "You arrive at the Magic Shop." << endl;
    cout << "1. Wizard's Hut" << endl;
    cout << "2. Village" << endl;
    cout << "3. Cave" << endl;
    cout << "4. Castle" << endl;
    cin >> travelChoice;
    
    if(travelChoice == 1)
    {
        cout << "You travel to the Wizard's Hut." << endl;
        currentLocation = 0;
        day++;
        player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
    }
    else if(travelChoice == 2)
    {
        cout << "You travel to the Village." << endl;
        currentLocation = 1;
        day++;
        player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
    }
    else if(travelChoice == 3)
    {
        cout << "You travel to the Cave." << endl;
        currentLocation = 2;
        day++;
        player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
    }
    else if(travelChoice == 4)
    {
        cout << "You travel to the Castle." << endl;
        currentLocation = 4;
        day++;
        player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
    }
    else
    {
        cout << "Invalid choice, you stay in the Magic Shop." << endl;
        currentLocation = 3;
    }
}

//Castle battle that will eventually lead to fight
else if(currentLocation == 4)
{
    cout << "You arrive at the Castle." << endl;
    cout << "A Dark Knight appears!" << endl;
    player.loseEnergy(10); 
    while(player.isalivedead() && castleEnemy.isalivedead())
    {
        cout << player.getName() << " attacks gracefully!" << endl;

        castleEnemy.takeDamage(player.attack());

        cout << castleEnemy.getName() << " health: " << castleEnemy.gethealth() << endl;

        if(castleEnemy.isalivedead())
        {
            cout << endl;

            cout << castleEnemy.getName() << " attacks!" << endl;

            player.takeDamage(castleEnemy.attack());

            cout << player.getName() << " health: " << player.gethealth() << endl;
        }
    }

    if(player.isalivedead())
    {
        cout<<"You defeated the Dark Knight!"<<endl;

        cout<<"You found the Dragon Crystal!"<<endl;

        player.collectdragonArtifact();

        cout << "1. Wizard's Hut" << endl;
        cout << "2. Village" << endl;
        cout << "3. Cave" << endl;
        cout << "4. Magic Shop" << endl;
        cout << "5. Farquad's Lair" << endl;
        cin >> travelChoice;
        
        if(travelChoice == 1) { 
            currentLocation = 0; day++; 
            player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
        }
        else if(travelChoice == 2) { 
            currentLocation = 1; day++;
            player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl;  
        }
        else if(travelChoice == 3) { 
            currentLocation = 2; day++; 
            player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
        }
        else if(travelChoice == 4) { 
            currentLocation = 3; day++; 
            player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
        }
        else if(travelChoice == 5) { 
            currentLocation = 5; day++; 
            player.loseEnergy(5); 
        cout <<"You lost 5 energy while traveling" << endl; 
        }
    }
    else
    {
        cout << "Game Over." << endl;
        return 0;
    }
}
//Final Battle!
else if(currentLocation == 5)
{
    cout << "You arrive at Farquad's Lair!" << endl;
    cout << "A Fiery Lair appears before you!" << endl;
    cout << "The Dark Lord Farquad appears!" << endl;
    player.loseEnergy(10); 
    while(player.isalivedead() && finalBoss.isalivedead())
    {
        cout << player.getName() << " attacks!" << endl;
        finalBoss.takeDamage(player.attack());
        cout << finalBoss.getName() << " health: " << finalBoss.gethealth() << endl;

        if(finalBoss.isalivedead())
        {
            cout << endl;
            cout << finalBoss.getName() << " attacks!" << endl;
            player.takeDamage(finalBoss.attack());
            cout << player.getName() << " health: " << player.gethealth() << endl;
        }
    }

    if(player.isalivedead())
    {
        cout << "You defeated Farquad!" << endl;
        cout << "You saved the kingdom! You are a true hero!" << endl;
        cout << "Game Complete!" << endl;
        return 0;
    }
    else
    { cout << "Game Over." << endl;
        return 0;
    }
}
if(day>10) {
        cout << "You ran out of time. Game Over." << endl;
        return 0; 
    }

}
//Using functions for inventory display
else if(choice == 3)
{
    cout << endl;
    cout << "===== INVENTORY =====" << endl;

cout<< "Health: " <<player.gethealth() <<endl;

cout<< "Energy: " << player.getEnergy() << endl; 

cout<< "Healing Potions: " <<player.getPotions() <<endl;

cout<< "Energy Potions: " << player.getenergyPotions() << endl; 

cout << "Ice Spells: " << player.getIceSpells() << endl;

cout << "Fire Spells: " << player.getFireSpells() << endl;

cout << "Lightning Spells: " << player.getLightningSpells() << endl;

cout << "Total Spells: " << player.getTotalSpells() << endl;

cout << "Crown Artifacts: " << player.getcrownArtifact() << endl;

cout << "Dragon Artifacts: " << player.getdragonArtifact() << endl;

cout << "Total Artifacts: " << player.getcrownArtifact() + player.getdragonArtifact() << endl;

player.displayInventory();

cout << endl;
}

else if(choice==4)
{
    if(player.getPotions()>0)
    {
    player.usePotion();

    player.setHealth(player.gethealth()+100);

    cout<<"You restored 100 health!"<<endl;
    }

    else
    {
        cout<<"You have no potions remaining."<<endl;
    }
}
else if(choice==5)
{
    if(player.getenergyPotions()>0)
    {
    player.useenergyPotion();

    player.setEnergy(player.getEnergy()+50);

    cout<<"You restored 50 energy!"<<endl;
    }

    else
    {
        cout<<"You have no potions remaining."<<endl;
    }
}
else if (choice==6){

if (currentLocation==0){

cout << "The Wizard says: Do not be influenced by darkness, here's my lightning gift" << endl;
player.collectLightningSpell();

}

else if (currentLocation==1){
cout << "The villager leader say: Thank you for helping us againist evil please rest and take" << endl;
cout << "this fire spell handed down from generations, you will most certainly need it." << endl; 
player.collectFireSpell();
}
else if (currentLocation==2){
cout << "The Cave Troll says: We have our crowned possesion, leave before I KILL YOU!!!" << endl;

}
else if (currentLocation==3){
cout << "The shopkeeper says: Powerful artificats and spells await what would you like!" << endl;
int shopChoice;

cout<< "1. Ice Spell"<<endl;
cout<< "2. Healing Potion"<<endl;
cout<< "3. Energy Potion" << endl; 
cout<< "4. Dark Magic Shortcut" << endl; 
cout<< "5. Leave"<<endl;

cin>>shopChoice;
if(shopChoice==1)
{
    player.collectIceSpell();
}

else if(shopChoice==2)
{
    player.addPotion();
cout << "You bought a healing potion" << endl; 
}

else if(shopChoice==3)
{
    player.addenergyPotion(); 
cout << "You bought an energy potion" << endl; 
}
else if(shopChoice==4)
{
cout << "The Dark Mage whispers..." << endl; 
cout << "There is always a cost:)???" << endl; 

cout << "You Gain: " << endl; 
cout << "+50 Health" << endl; 
cout << "+50 Energy" << endl; 

player.setHealth(player.gethealth()+50);

player.setEnergy(100);

player.usedarkmagic();

cout<<"Dark Magic Influence has been added!"<<endl;
}

}

else if (currentLocation==4){
cout << "A butterfly whispers: Things are not as they seem" << endl;

}

}
else if(choice == 7)
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
else if (choice == 8)
{
    if(currentLocation != 4)
    {
        cout << "You must reach the Castle to challenge Farquad." << endl;
    
    }
    else if (player.getTotalSpells() < 3) 
    {
        cout << "You must collect 3 spells first." << endl;
    }

    else if(player.getTotalArtifacts() < 2) 
    {
        cout << "You must collect 2 artifacts first." << endl;
    }
    else
    {
        cout << "You challenge Farquad!" << endl;

    while(player.isalivedead() && finalBoss.isalivedead())
    {
        cout << player.getName() << " attacks gracefully!" << endl;

        finalBoss.takeDamage(player.attack());

        cout << finalBoss.getName() << " health: " << finalBoss.gethealth() << endl;

        if(finalBoss.isalivedead())
        {
            cout << endl;

            cout << finalBoss.getName() << " attacks!" << endl;

            player.takeDamage(finalBoss.attack());

            cout << player.getName() << " health: " << player.gethealth() << endl;
        }
    }
//Different endings 
    if (player.isalivedead())
    {
    cout << "Congratulations! You have defeated Farquad and saved the kingdom!" << endl;
    
    if(player.getdarkmagic() == 0)
    {
        cout << "You saved the kingdom honorably and restored peace to the land!" << endl;
    }

    else
    {
        cout << "You defeated Farquad, but at a terrible cost." << endl;
        cout << "Dark Magic now spreads throughout the kingdom, and its future remains uncertain." << endl;
    }

    return 0;
        }
        else
        {
            cout << "You were defeated by Farquad. Game Over." << endl;
            return 0; 
        }
    
    }
}
else if(choice == 9)
{
    cout << "Thanks for playing!" << endl;
}
else {

cout << "Invalid choice, choose again.";

        }

}
return 0; 
}