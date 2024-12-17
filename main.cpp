#include<iostream>
#include<string>//needed for getline
#include<Windows.h>//needed for color change
#pragma comment(lib, "winmm.lib")// sounds!
using namespace std;
//global variables: makes the variable be seen and used by ALL functions
string items[10];
//function declerations:
void FinalBattle();
void Password();
void findPart();
void combineParts();

//global variables:
int points = 0;
int HP = 150;
int input;
int room = 1;
bool hasAcessToMachine;
int main() {


	string input = "potato";
	//stuff here runs every turn!
	cout << endl << "---------------------------------------" << endl;
	cout << "your inventory:";
	for (int i = 0; i < 10; i++)
		cout << items[i] << " | ";
	cout << endl;

	while (input != "quit") {//game loop
		switch (room) {
		case 1:
			cout << "You wake up in the middle of a destroyed city, fire, smoke, everywhere. You see a dragon fly around terrorizing the old city. You see a building that is still standing north from here and south but there is rubble." << endl;
			cout << "        |   _   _" << endl;
			cout << "  .|  . x .|.|-|.|  _" << endl;
			cout << "   |/ ./.\\-/.\\-|.|.|.| |" << endl;
			cout << "~~~|.|_|.|_|.|.|.|_|.|~~~" << endl;
			getline(cin, input);
			findPart();
			if (input == "north" || input == "go north")
				room = 2;
			if (input == "Rubble" || input == "Move Rubble")
				if (items[9] == "key stone") {
					cout << "you move the rubble with the key stone" << endl;
					items[9] = ""; //erases key from inventory
					room = 11;
				}
				else {
					cout << "the Rubble blocks the way" << endl;
				}
			else
				cout << "thats not an option" << endl;
			break;
		case 2:
			cout << "You get into a old wooden building that is on the verge of collapsing, In the corner you see a old workbench could be useful idrk you could go back,south, then you see two archways one leading northeast and one leading northwest" << endl;
			getline(cin, input);
			findPart();
			combineParts();
			if (input == "northeast" || input == "go northeast")
				room = 3;
			else if (input == "northwest" || input == "go northwest")
				room = 4;
			else if (input == "south" || input == "go south")
				room = 1;
			else
				cout << "thats not an option" << endl;
			break;
		case 3:
			cout << "the archway is old made by stone bricks and spider webs everywhere as you go further there is a skeleton that was a knight you see four openings north east west and south" << endl;
			getline(cin, input);
			findPart();
			if (input == "north" || input == "go north")
				room = 6;
			else if (input == "east" || input == "go east")
				room = 7;
			else if (input == "west" || input == "go west")
				room = 4;
			else if (input == "south" || input == "go south")
				room = 2;
			else
				cout << "thats not an option" << endl;
			break;
		case 4:
			cout << "the archway is old made by stone bricks and spider webs everywhere as you go further a rat runs by and it scared you hahaha scaredy cat! you then see four openings north east west and south" << endl;
			getline(cin, input);
			findPart();
			if (input == "north" || input == "go north")
				room = 6;
			else if (input == "east" || input == "go east")
				room = 3;
			else if (input == "west" || input == "go west")
				room = 5;
			else if (input == "south" || input == "go south")
				room = 2;
			else
				cout << "thats not an option" << endl;
			break;
		case 5:
			cout << "Your at ruins of apartments rubble and dust everywhere there is a photo of a lovely baby dog with pibble engraved at the bottom there is two ways leading here northeast and east" << endl;
			getline(cin, input);
			findPart();
			if (input == "northeast" || input == "go northeast")
				room = 6;
			else if (input == "east" || input == "go east")
				room = 4;
			else
				cout << "thats not an option" << endl;
			break;
		case 6:
			cout << "you see a lonely house that seems to be untouched compared to everything else you see a computer and a strange machine with two archways one is southwest and the other is southeast. There are two ruined apartments one is east and the other is west, Then a dragon roars whith a seat on his back" << endl;
			getline(cin, input);
			findPart();
			if (input == "west" || input == "go west")
				room = 5;
			else if (input == "east" || input == "go east")
				room = 7;
			else if (input == "southwest" || input == "go southwest")
				room = 4;
			else if (input == "southeast" || input.compare("go southeast") == 0)
				room = 3;
			else if (input == "dragon" || input == "take dragon") {
				room = 9;
			}
			else if (input == "Machine" || input == "GoToMachine") {
				if (items[9] == "Key Stone") {
					cout << "you destroyed the machine revealing a grate" << endl;
					items[9] = ""; //erases key stone from inventory
					room = 11;
				}
			}
			else if (input == "computer" || input == "go to computer")
				room = 13;



			break;
		case 7:
			cout << "Youre arrive at what seemed to be apartments but now they are ruins and you look around to see everything outside has been destroyed there are two ways one is northwest and one is west" << endl;
			getline(cin, input);
			findPart();
			if (input == "west" || input == "go west")
				room = 5;
			else if (input == "northwest" || input == "go northwest")
				room = 7;
			else
				cout << "thats not an option" << endl;
			break;
		case 8:
			cout << "your at the basement there are many cardboard boxes full of random items, you haer water rushing and at then end of the basement there is a grate go down to reach room 1" << endl;
			getline(cin, input);
			findPart();
			if (input == "up" || input == "go up")
				room = 9;
			else if (input == "down" || input == "go down")
				room = 1;
			else
				cout << "thats not an option" << endl;
			break;
		case 9:
			cout << "the dragon drops you off at a house before leaving. You knock but no one answers the door is unlocked you enter everything is eerie then, you see stairs elading down and ladders leading up." << endl;
			getline(cin, input);
			findPart();
			if (input == "up" || input == "go up")
				room = 10;
			else if (input == "down" || input == "go down")
				room = 8;
			else
				cout << "thats not an option" << endl;
			break;
		case 10:
			cout << "Your in the attic of the house its super dusty and the shadows seem to move around you, you look around and see a not that says Password:ILOVEPIBBLE The laddder goes down" << endl;
			getline(cin, input);
			findPart();
			if (input == "down" || input == "go down")
				room = 9;
			else
				cout << "thats not an option" << endl;
			break;
		case 13:
			cout << "your at the Computer" << endl;
			getline(cin, input);
			if (hasAcessToMachine != true)
				Password();
			items[9] == "Key stone";
			if (input == "back" || input == "go back")
				room = 6;
			break;
		case 11:
			FinalBattle();
			cout << "your in room 11, You have to slay the dragon" << endl;
			if (items[1] == "sword") {
				cout << "you slay the dragon with your sword and escape the castle" << endl;
				input = "quit";

				return 0; // kills the program
			}
			else {
				cout << "you ded." << endl;
				input = "quit";
			}
		}
	}//end of game loop
	cout << "thanks for playing" << endl;
}//end of main

//Function definitions
void FinalBattle() {
	system("color 04");
	int Dragon = 500;
	int DragonDMG = 0;
	int PlayerDMG = 0;
	char dummy;
	while (Dragon > 0 && HP > 0) {
		if (items[3] == "Shield") {
			DragonDMG = rand() % 40 + 30;
			cout << "The dragon swiped at you, but youre shield blocked most of it. You took" << DragonDMG << " damage!" << endl;
			HP -= DragonDMG;
		}
		else {
			DragonDMG = rand() % 70 + 35;
			cout << "The dragon breathed at you. It did a whopping" << DragonDMG << " damage" << endl;
			HP -= DragonDMG;
			PlayerDMG = rand() % 46 + 20;
		}
		if (items[4] == "Raygun") {
			PlayerDMG = rand() % 100 + 50;
		}
		else {
			PlayerDMG = rand() % 20;
		}
		system("pause");
		if (HP > 0)
			cout << "your health is now: " << HP << endl;
		else
			cout << "you have died" << endl;
		if (Dragon > 0)
			cout << "the mosters health is now " << Dragon << endl;
		else
			cout << "You have slain the monster" << endl;
		cout << "press any key to continue..." << endl;
		cin >> dummy;
		system("pause");
	}
	if (HP > 0)
		cout << "you have won and found PIBBLE" << endl;
	PlaySound(TEXT("cheering.wav"), NULL, SND_FILENAME);
}
void Password() {
	string correctPassword = "ILOVEPIBBLE";
	string inputPassword;

	while (inputPassword != correctPassword) {
		cout << "You have arrived at the computer. To use it, you need to enter the correct password.." << endl;

		// Prompt for password input
		cout << "Enter password: ";
		getline(cin, inputPassword);

		// Check if the password is correct
		if (inputPassword == correctPassword) {
			hasAcessToMachine = true;
			cout << "Access granted. You can now use the machine, Because of the keystone" << endl;
			items[9] = "Key stone";
		}
		else {
			cout << "Incorrect password. Access denied." << endl;
		}
	}
}
void findPart() {
	// Check the current room and allow the user to choose a part to find
	if (room == 2) {
		if (items[0] == "") {
			cout << "You are in the old wooden building. You can search for parts here." << endl;
			cout << "Would you like to search for a nozzle? (yes/no)" << endl;
			string response;
			getline(cin, response);
			if (response == "yes") {
				cout << "You found a nozzle!" << endl;
				items[0] = "nozzle";  // Add nozzle to inventory
			}
			else {
				cout << "You decided not to search for the nozzle." << endl;
			}
		}
	}
	else if (room == 3) {
		if (items[1] == "") {
			cout << "You are in the room with a knight skeleton. You can search for parts here." << endl;
			cout << "Would you like to search for a handle? (yes/no)" << endl;
			string response;
			getline(cin, response);
			if (response == "yes") {
				cout << "You found a handle!" << endl;
				items[1] = "Handle";  // Add handle to inventory
			}
			else {
				cout << "You decided not to search for the handle." << endl;
			}
		}
	}
	else if (room == 9) {
		if (items[2] == "") {
			cout << "You are in a mysterious room. You can search for parts here." << endl;
			cout << "Would you like to search for a chamber? (yes/no)" << endl;
			string response;
			getline(cin, response);
			if (response == "yes") {
				cout << "You found a chamber!" << endl;
				items[2] = "chamber";  // Add chamber to inventory
			}
			else {
				cout << "You decided not to search for the chamber." << endl;
			}
		}
	}
	else if (room == 5) {
		if (items[3] == "") {
			cout << "You are in the ruins of apartments. You can search for parts here." << endl;
			cout << "Would you like to search for a visor? (yes/no)" << endl;
			string response;
			getline(cin, response);
			if (response == "yes") {
				cout << "You found a visor!" << endl;
				items[3] = "visor";  // Add visor to inventory
			}
			else {
				cout << "You decided not to search for the visor." << endl;
			}
		}
	}
	else if (room == 8) {
		if (items[4] == "") {
			cout << "You are in the house with a machine. You can search for parts here." << endl;
			cout << "Would you like to search for metal? (yes/no)" << endl;
			string response;
			getline(cin, response);
			if (response == "yes") {
				cout << "You found metal!" << endl;
				items[4] = "Metal";  // Add metal to inventory
			}
			else {
				cout << "You decided not to search for metal." << endl;
			}
		}
	}
	else if (room == 7) {
		if (items[5] == "") {
			cout << "You are in the ruined apartments. You can search for parts here." << endl;
			cout << "Would you like to search for an eagle statue? (yes/no)" << endl;
			string response;
			getline(cin, response);
			if (response == "yes") {
				cout << "You found an eagle statue!" << endl;
				items[5] = "eagle statue";  // Add eagle statue to inventory
			}
			else {
				cout << "You decided not to search for the eagle statue." << endl;
			}
		}
	}
}

void combineParts() {
	string command;
	cout << "What would you like to combine? (type 'combine Raygun' or 'combine shield')" << endl;
	getline(cin, command);

	// Combine parts to create a Sword
	if (command == "combine Raygun") {
		if (items[0] == "nozzle" && items[1] == "Handle" && items[2] == "chamber") {
			cout << "You have all the parts! Combining them into a Sword..." << endl;
			// Remove parts from inventory after combining
			items[0] = "";  // Nozzle
			items[1] = "";  // Handle
			items[2] = "";  // Chamber
			items[6] = "Raygun";  // Add Sword to inventory
			cout << "You now have a Raygun!" << endl;
		}
		else {
			cout << "You don't have all the parts to make a Raygun yet!" << endl;
		}
	}
	// Combine parts to create a Shield
	else if (command == "combine shield") {
		if (items[3] == "visor" && items[4] == "Metal" && items[5] == "eagle statue") {
			cout << "You have all the parts! Combining them into a Shield..." << endl;
			// Remove parts from inventory after combining
			items[3] = "";  // Visor
			items[4] = "";  // Metal
			items[5] = "";  // Eagle statue
			items[7] = "Shield";  // Add Shield to inventory
			cout << "You now have a Shield!" << endl;
		}
		else {
			cout << "You don't have all the parts to make a shield yet!" << endl;
		}
	}
	else {
		cout << "Invalid command or you don't have the necessary parts!" << endl;
	}
}
