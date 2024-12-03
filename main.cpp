#include<iostream>
using namespace std;
//global variables: makes the variable be seen and used by ALL functions
string inventory[10];
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
			cout << "your in room 1, you can go east" << endl;
			cout << "you found a pineapple" << endl;
			inventory[0] = "pineapple";
			cout << "Theres a dusty rug in the floor" << endl;
			cin >> input;
			if (input == "east" || input == "go east")
				room = 2;
			if (input == "rug" || input == "look" || input == "look under rug") {
				if (inventory[2] != "key")
					cout << "you found a shiny key!" << endl;
				inventory[2] = "key";
			}
			break;
		case 2:
			cout << "your in room 2, you can go north and west" << endl;
			if (inventory[1] != "sword")
				cout << "you see a sword on the ground." << endl;
			cin >> input;
			if (input == "north" || input == "go north")
				if (inventory[2] == "key") {
					cout << "you unlock the door with the key" << endl;
					inventory[2] = ""; //erases key from inventory
					room = 3;
				}
				else {
					cout << "the door is locked" << endl;
				}
			if (input == "west" || input == "go west")
				room = 1;
			if (input == "sword" || input == "pick up sword" || input == "get sword") {
				inventory[1] = "sword";
				cout << "you picked up sword." << endl;
			}
			break;
		case 3:
			cout << "your in room 3,OMG THERES A DRAGON" << endl;
			if (inventory[1] == "sword") {
				cout << "you slay the dragon with your sword and escape the castle" << endl;
				input = "quit";
				return 0; // kills the program
			}
			else {
				cout << "you ded." << endl;
				input = "quit";
			}
			break;
		}
	}//end of game loop
	cout << "thanks for playing" << endl;
}//end of main
