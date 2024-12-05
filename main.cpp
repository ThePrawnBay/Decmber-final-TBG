#include<iostream>
#include<string>//needed for getline
using namespace std;
//global variables: makes the variable be seen and used by ALL functions
string inventory[10];

void FirstZombieEncounter();

int playerHealth = 150;

int points = 0;

int main() {
	//local variables
	int room = 1;
	string input = "potato";
	//stuff here runs every turn!
	cout << endl << "---------------------------------------" << endl;
	cout << "your inventory:";
	for (int i = 0; i < 10; i++)
		cout << inventory[i] << " | ";
	cout << endl;
	while (input != "quit") {//game loop
		switch (room) {
		case 1:
			cout << "youre in room 1, you can go north" << endl;
			getline(cin, input);
			if (input == "north" || input == "go north")
				room = 2;
			break;
		case 2:
			cout << "your in room 2, you can go northeast, northwest, and south" << endl;
			getline(cin, input);
			if (input == "northeast" || input == "go northeast")
				room = 3;
			if (input == "northwest" || input == "go northwest")
				room = 4;
			if (input == "south" || input == "go south")
				room = 2;
			break;
		case 3:
			cout << "your in room 3, you can go north, east, west, and south" << endl;
			getline(cin, input);
			if (input == "north" || input == "go north")
				room = 6;
			if (input == "east" || input == "go east")
				room = 7;
			if (input == "west" || input == "go west")
				room = 4;
			if (input == "south" || input == "go south")
				room = 2;
			break;
		case 4:
			cout << "your in room 4, you can go north, east, west, and south" << endl;
			getline(cin, input);
			if (input == "north" || input == "go north")
				room = 6;
			if (input == "east" || input == "go east")
				room = 3;
			if (input == "west" || input == "go west")
				room = 5;
			if (input == "south" || input == "go south")
				room = 2;
			break;
		case 5:
			cout << "your in room 5, you can go northeast and east" << endl;
			getline(cin, input);
			if (input == "northeast" || input == "go northeast")
				room = 6;
			if (input == "east" || input == "go east")
				room = 4;
			break;
		case 6:
			cout << "your in room 6, go west, southeast, southwest, and east or you can take the dragon to the hatchery, go to the BOSS" << endl;
			getline(cin, input);
			if (input == "west" || input == "go west")
				room = 5;
			if (input == "east" || input == "go east")
				room = 7;
			if (input == "southwest" || input == "go southwest")
				room = 4;
			if (input == "southeast" || input == "go southeast")
				room = 3;
			if (input == "dragon" || input == "take dragon")
				room = 8;
			if (input == "boss" || input == "go to boss")
				room = 11;
			break;
		case 7:
			cout << "your in room 7, you can go west and southwest" << endl;
			getline(cin, input);
			if (input == "west" || input == "go west")
				room = 5;
			if (input == "east" || input == "go east")
				room = 7;
			break;
		case 8:
			cout << "your in room 8, you can go up or down" << endl;
			getline(cin, input);
			if (input == "up" || input == "go up")
				room = 9;
			if (input == "down" || input == "go down")
				room = 1;
			break;
		case 9:
			cout << "your in room 9, you can go up and down" << endl;
			getline(cin, input);
			if (input == "up" || input == "go up")
				room = 10;
			if (input == "down" || input == "go down")
				room = 8;
			break;
		case 10:
			cout << "your in room 10, you can go down" << endl;
			getline(cin, input);
			if (input == "down" || input == "go down")
				room = 9;
			break;
		case 11:
			cout << "your in room 11, You have to slay the dragon" << endl;
			if (inventory[1] == "sword") {
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


void FirstZombieEncounter() {

}
