// Hero's Inventory 3.0 By Micheal Dawson
// source = book 
//Title: "Beginning C++ Through Game Programming" 4th Ed.
// Demonstrates iterators

/* Program Modified by Deron B Kosloski
*   July 2, 2016
*   IT620       
*   Hero's Inventory 3 modified to 2016 */

/* This program was originally Hero's Inventory 3 and it is still in the beginning of the program.
   A transformation takes place and whisks the Hero, 500 years into the future to 2016, seen at the end of the program.
   Any changes to the original program will be dually documented with comments. */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Setup the function prototypes to be used

string textPrompt(string display);													    // Displays interactive questions to the player
string* ptrInventory(vector<string>* const iVector, int a);							   // uses a pointer to return the address of a string in a position of the inventory vector
void newInventory(const vector<string>& inventory);                                   // Passes a constant vector with a Reference
void leadinStory(string name);														  // Tells the starting story


// Hero object for 2016

class Hero
{
public:
	int h_Health = 100;					                                                 // Hero's Health
	
};

// Hero's Inventory 3 by Micheal Dawson

int main()
{
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	vector<string>::iterator myIterator;
	vector<string>::const_iterator iter;

	for (int x = 1; x <= 250000; --x) {}			                                    // 1.5s delay loop to simulate activity 

	cout << "Your items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << "\nYou trade your sword for a battle axe.";
	myIterator = inventory.begin();
	*myIterator = "battle axe";
	cout << "\nYour items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << "\nThe item name '" << *myIterator << "' has ";
	cout << (*myIterator).size() << " letters in it.\n";

	cout << "\nThe item name '" << *myIterator << "' has ";
	cout << myIterator->size() << " letters in it.\n";

	cout << "\nYou recover a crossbow from a slain enemy.";
	inventory.insert(inventory.begin(), "crossbow");
	cout << "\nYour items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << "\nYour armor is destroyed in a fierce battle.";
	inventory.erase((inventory.begin() + 2));
	cout << "\nYour items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout << *iter << endl;
	}
	cout << "\n\n";

					// ****************2016 by Deron Kosloski******************//

	// a lead in narrative to 2016
	
	cout << "An enemy starts an attack to finish the hero, then,The Hero shouts, 'It's not my time!' \n" << endl;

	for (int x = 1; x <= 500000; --x) {}			                                    // 3s delay loop to simulate activity

	cout << "A bright colorful stream of light, emits from the battle axe! \n" << endl;
	
	for (int x = 1; x <= 500000; --x) {}			                                    // 3s delay loop to simulate activity

	cout << "The Hero is gone, as the attacking enemy stood in amazement and a puddle of fear! \n\n" << endl;

	for (int x = 1; x <= 500000; --x) {}			                                    // 3s delay loop to simulate activity

	string name = textPrompt("What is the name of your Hero?: ");                       // Using a function call to have the user select a name of the Hero

	leadinStory(name);                                                                  // Tells the beginning story of 2016

	for (int x = 1; x <= 2000000; --x) {}			                                    // 12s delay loop for reading

	 inventory.clear();								                                    // The hero has a new inventory so the old must be cleared out

	 // New Inventory

	inventory.push_back("Micro Mini Gun");
        inventory.push_back("Force Field Suit");
	inventory.push_back("Laser Rifle");
	inventory.push_back("Battle Axe of Time");
	inventory.push_back("Empty Slot");													 // an open space for use with the pointers
	
	newInventory(inventory);                                                             // Display the New Inventory with a function
	
	Hero hero1;						                                                     // Instantiating the first instance of the Hero Object
	 
	cout << "\n" << name << " has a Health of " << hero1.h_Health << "%\n\n" << endl;    // Represents the Health in terms of percent

	// Using pointers to display and alter the inventory showing the use of pointers

	string* newItem = ptrInventory(&inventory, 4);										// places a new item in inventory using pointers

	cout << name << " looks at the " << *(ptrInventory(&inventory, 3));
	cout << " and finds that it opens on the end, which \n" << name << " finds a small scroll for the " << *(ptrInventory(&inventory, 3))<< ".\n\n";

	*newItem = "Small scroll";								    // added a new item using a pointer

	newInventory(inventory);

	return 0;
}

//**************************************************Functions to be called from 2016 portion of the main()***********************************************************

// Ask Text Function asking for user input 

string textPrompt(string display)
{
	string user;
	cout << display;
	cin >> user;
	return user;
}


// Story Function. Tells the lead in story and displays the user input

void leadinStory(string name)
{
	cout << "\n\n\t\t THE ADVENTURE OF 2016 \n\n";
	cout << "After " << name <<"'s";
	cout << " armor was destroyed, an enemy had run up to him to give a killing blow. \n";
	cout << "In an attempt to block with his trusted battle axe, ";
	cout << name << ", shouted; 'Not My Time!'.\n";
	cout << "Just before the first blow struck the battle axe, a bright colorful light consumed the battle axe and \n";
	cout << name << " had seemed to be swept up into the colorful streams of light, away from Battleville. \n";
	cout << name << "	awakes and he assumes he had just perished and is in the after life, ";
	cout << "as he is adorned with a new streamline set of clothes and weapons he has never seen before, ";
	cout << "standing in a place which is totally unlike anything he has seen.\n";
	cout << "A gentleman walks by and ";
	cout << name << " says,'Excuse me, kind sir, but I think I have lost my way, can you tell me where I am ?'\n"; 
	cout << "The gentleman replied, 'Yes, you are on Light Street.'\n"; 
	cout << "Feeling a bit confused " << name << " says, 'I meant the place what city am I in?\n";
	cout << "The gentleman replies with a smile, 'Battleville, and if you must know, the year is 2016.'\n\n ";
	cout << "And the Adventure Begins! \n\n";
}

// Inventory Function, displays the new inventory using a reference to inventory through a constant vector

void newInventory(const vector<string>& newInven)

{
	cout << "\nYour New Inventory is:\n\n";
	for (vector<string>::const_iterator iter = newInven.begin(); iter != newInven.end(); ++iter)
	{
		cout << *iter << endl;
	} 
	
}

// A function that accesses the inventory using pointers

string* ptrInventory(vector<string>* const iVector, int a)
{
	return &((*iVector)[a]);                                                             // returns the address of the string in position a of the vector in Inventory
}
