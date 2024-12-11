#include<iostream>
#include<string>//needed for getline
#include<Windows.h>//needed for color change
using namespace std;
//global variables: makes the variable be seen and used by ALL functions
string items[10];
//function declerations:
void battleSys();
void NPC();
void FinalBattle();
void ItemDropper();
void Password();
//glov=bal variables:
int points = 0;
int HP = 150;
int input;
int main() {
	//local variables
	int room = 1;
	string input = "potato";
	//stuff here runs every turn!
	cout << endl << "---------------------------------------" << endl;

	while (input != "quit") {//game loop
		switch (room) {
		case 1:
			cout << "youre in room 1, you can go north" << endl;
			getline(cin, input);
			if (input == "north" || input == "go north")
				room = 2;
			else
				cout << "thats not an option" << endl;
			break;
		case 2:
			cout << "your in room 2, you can go northeast, northwest, and south" << endl;
			getline(cin, input);
			battleSys;
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
			cout << "your in room 3, you can go north, east, west, and south" << endl;
			getline(cin, input);
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
			cout << "your in room 4, you can go north, east, west, and south" << endl;
			getline(cin, input);
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
			cout << "your in room 5, you can go northeast and east" << endl;
			getline(cin, input);
			if (input == "northeast" || input == "go northeast")
				room = 6;
			else if (input == "east" || input == "go east")
				room = 4;
			else
				cout << "thats not an option" << endl;
			break;
		case 6:
			cout << "your in room 6, go west, southeast, southwest, and east or you can take the dragon to the hatchery, go to the machine, go to computer" << endl;
			getline(cin, input);
			if (input == "west" || input == "go west")
				room = 5;
			else if (input == "east" || input == "go east")
				room = 7;
			else if (input == "southwest" || input == "go southwest")
				room = 4;
			else if (input == "southeast" || input == "go southeast")
				room = 3;
			else if (input == "dragon" || input == "take dragon");

			else if (items[2] == "DG") {
				cout << "The dragon has arrived to take you" << endl;
				items[2] = ""; //erases DG from inventory
				room = 8;
			}
			else {
				cout << "the dragon is not there" << endl;
			}
			else if (input == "Machine" || input == "go to machine")
			room = 12;
			else if (items[9] == "Key Stone") {
			cout << "you destroyed the machine revealing a grate" << endl;
			items[9] = ""; //erases key stone from inventory
			room = 11;
			}
			else {
			cout << "Theres a machine blocking the grate" << endl;
			}
			cout << "thats not an option" << endl;
			else if (input == "Machine" || input == "go to machine")
			room = 13;
			break;
		case 7:
			cout << "your in room 7, you can go west and southwest" << endl;
			getline(cin, input);
			if (input == "west" || input == "go west")
				room = 5;
			else if (input == "east" || input == "go east")
				room = 7;
			else
				cout << "thats not an option" << endl;
			break;
		case 8:
			cout << "your in room 8, you can go up or down" << endl;
			getline(cin, input);
			if (input == "up" || input == "go up")
				room = 9;
			else if (input == "down" || input == "go down")
				room = 1;
			else
				cout << "thats not an option" << endl;
			break;
		case 9:
			cout << "your in room 9, you can go up and down" << endl;
			getline(cin, input);
			if (input == "up" || input == "go up")
				room = 10;
			else if (input == "down" || input == "go down")
				room = 8;
			else
				cout << "thats not an option" << endl;
			break;
		case 10:
			cout << "your in room 10, you can go down" << endl;
			getline(cin, input);
			if (input == "down" || input == "go down")
				room = 9;
			else
				cout << "thats not an option" << endl;
			break;
		case 12:
			cout << "your at the machine" << endl;
			getline(cin, input);
			Password();
			if (input == "ILOVEPIBBLE")
				items[9] = "Key stone";
			else
				cout << "wrong password!" << endl;
			break;
		case 13:
			cout << "your at the computer, What is the password" << endl;
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

void NPC() {
	int num = rand() % 100 + 1; //gives num 1-100
	if (num < 20)
		cout << "the gnome says: was an adventurer until i took an arrow to the knee" << endl;
	else if (num < 30)
		cout << "the gnome says:The evil king used to be nice but then he lost his favorite frog" << endl;
	else if (num < 35)
		cout << "the gnome says:the first number in the secret code is 2" << endl;
	else if (num < 50) {
		cout << "the gnome smiles and gives you 5 gold" << endl;
		points += 5;
	}
	else if (num < 60)
		cout << " the gnome gives you a health potion" << endl;
	items[4] = "health potion";
}
void ItemDropper() {
	int num = rand() % 100 + 1;
	if (num < 15) {
		cout << " you obtained a dragon control" << endl;
		items[2] = "DG";
	}
	else {
		cout << "" << endl;
	}

}



void battleSys() {
	int monsterhealth = 15;
	int num;
	cout << endl << endl << "------------------------Battle time!!---------------" << endl;
	while (HP > 0 && monsterhealth > 0) {
		//Monster attack
		if (items[1] == "shield") {
			num = rand() % 2;
			cout << "your shield absorbs the blow and you get hit for " << num << " damage" << endl;
			HP -= num;
		}
		else {
			num = rand() % 5;
			cout << "the moster bites you for" << num << " dmg" << endl;
			HP -= num;
		}
		HP -= num;
		cout << "press 1 to attack" << endl;
		cin >> input;
		switch (input) {
		case 1:
			//player attack
			if (items[0] == "sword") {
				num = rand() % 10 + 10;
				cout << "you slash the monster with your sword for" << num << " damage" << endl;
				monsterhealth -= num;
			}
			else {
				num = rand() % 5 + 2;//range from 2-7
				cout << "you punch the moster for" << num << " dmg" << endl;
				monsterhealth -= num;
			}
			break;
		default:
			cout << "sorry thats not an option" << endl;
		}
		cout << "your health:" << HP << endl;
		cout << "Monsters health:" << monsterhealth << endl;

	}
	cout << "end of battle-------------------------------" << endl;
}
void FinalBattle() {
	system("color 04");
	int Dragon = 500;
	int DragonDMG = 0;
	int PlayerDMG = 0;

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
		if (items[4] == "Raygun MK3") {
			PlayerDMG = rand() % 100 + 50;
		}
		else {
			PlayerDMG = rand() % 20;
		}
		system("pause");
		cout << "Your health is now: " << HP << endl;
		cout << "The monsters health is now: " << Dragon << endl;
		system("pause");
	}
}
void Password() {
	string choice = "gio";
	while (choice != "q") {
		cout << "BOO" << endl;
		cout << "Press q to leave" << endl;
		cin >> choice;
		if (choice != "ILOVEPIBBLE")
			cout << "press q to leave!" << endl;
	}
}
