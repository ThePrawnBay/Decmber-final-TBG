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
int room = 6;
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
			cout << "You wake up in the middle of a destroyed city, fire, smoke, everywhere. You see a dragon fly around terrorizing the old city. You see a building that is still standing north from here." << endl;
			cout << "        |   _   _" << endl;
			cout << "  .|  . x .|.|-|.|  _" << endl;
			cout << "   |/ ./.\\-/.\\-|.|.|.| |" << endl;
			cout << "~~~|.|_|.|_|.|.|.|_|.|~~~" << endl;
			getline(cin, input);
			findPart();
			if (input == "north" || input == "go north")
				room = 2;
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
				room = 2;
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
			cout << "the archway is old made by stone bricks and spider webs everywhere as you go further there is a skeleton that was a knight you see four openings north east west and south" << endl;
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
			cout << "you see a lonely house that seems to be untouched compared to everything else you see a computer and a strange machine with two archways one is southwest and the other is southeast. There are two ruined apartments one is east and the other is west" << endl;
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
			cout << "your at a very old machine that has a type writer awaiting you input as it blinks green." << endl;
			getline(cin, input);
			Password();
			if (input == "ILOVEPIBBLE")
				items[9] = "Key stone";
			else
				cout << "wrong password!" << endl;
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
	int Dragon = 0;
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
		cout << "you have won" << endl;
	PlaySound(TEXT("cheering.wav"), NULL, SND_FILENAME);
}
void Password() {
	string choice = "gio";
	while (choice != "q") {
		cout << "type back to leave" << endl;
		cin >> choice;
		if (choice != "ILOVEPIBBLE")
			cout << "press q to leave!" << endl;
	}
}
void findPart() {
	// Check if any part can be found in the current room
	if (room == 2 && items[0] == "") {
		cout << "You found a nozzle!" << endl;
		items[0] = "nozzle";  // Add Blade to inventory
	}
	else if (room == 3 && items[1] == "") {
		cout << "You found a Handle!" << endl;
		items[1] = "Handle";  // Add Handle to inventory
	}
	else if (room == 9 && items[2] == "") {
		cout << "You found a chamber!" << endl;
		items[2] = "chamber";  // Add Guard to inventory
	}
	// For Shield parts:
	else if (room == 5 && items[3] == "") {
		cout << "You found the visor!" << endl;
		items[3] = "visor";  // Add Wood to inventory
	}
	else if (room == 6 && items[4] == "") {
		cout << "You found Metal!" << endl;
		items[4] = "Metal";  // Add Metal to inventory
	}
	else if (room == 7 && items[5] == "") {
		cout << "You found a eagle statue!" << endl;
		items[5] = "eagle statue";  // Add Leather to inventory
	}
	else {
		cout << "No parts found here." << endl;
	}
}
void combineParts() {
	// Combine parts to create a Sword (Blade, Handle, Guard)
	if (items[0] == "nozzl3" && items[1] == "Handle" && items[2] == "chamber") {
		cout << "You have all the parts! Combining them into a Sword..." << endl;
		items[0] = "";  // Remove individual parts after combining
		items[1] = "";
		items[2] = "";
		items[6] = "Sword";  // Final combined item
		cout << "You now have a Raygun!" << endl;
	}
	// Combine parts to create a Shield (Wood, Metal, Leather)
	else if (items[3] == "Wood" && items[4] == "Metal" && items[5] == "Leather") {
		cout << "You have all the parts! Combining them into a Shield..." << endl;
		items[3] = "";  // Remove individual parts after combining
		items[4] = "";
		items[5] = "";
		items[7] = "Shield";  // Final combined item
		cout << "You now have a Shield!" << endl;
	}
	else {
		cout << "You don't have all the parts yet. Keep searching!" << endl;
	}
}
