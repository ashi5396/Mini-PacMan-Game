#include "Menu.h"
#include "AppleSub.h"
#include "pacSub.h"

#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::string;

void Menu::runMenu() {
	
//	5 Test Cases;
	Test t;
	t.instructions();
	t.testPacMan();
	t.testEnemy();

	int option = 0;
	
	//show the menu and let the player use any game to play
	do {
		do {
			cout << "*************Welcome to the Mini Game Booth**************" << endl;
			cout << "Choose an option" << endl;
			cout << "1.PacMan" << endl;
			cout << "2.Apple Shooter" << endl;
			cout << "3.Exit the program" << endl;
			option = get_option();
		} while ((option != 1) && (option != 2) && (option != 3));

		//once a game is chosen, the player can chose to read directions or to play the game
		switch (option) {
		case 1: {
			int secondOption = 0;
				do {
					cout << "Please chose an option below" << endl;
					cout << "1.Read instructions on how to play PacMan" << endl;
					cout << "2.Play Game" << endl;
					secondOption = get_option();
				} while ((secondOption != 1) && (secondOption != 2));
				if (secondOption == 1) {
					pacSub pac;
					pac.instructions();
				}
				else {
					Game gam;
					gam.playGame();
				}
				break;
		}

		case 2: {

			/*int thirdOption = 0;
			do {
				cout << "Please chose an option below" << endl;
				cout << "1.Read instructions on how to play Apple Shooter" << endl;
				cout << "2.Play Game" << endl;
				thirdOption = get_option();
			} while ((thirdOption != 1) && (thirdOption != 2));
			if (thirdOption == 1) {
				AppleSub app;
				app.instructions();
			}
			else {
				Apple apple;
				apple.playApple();
				break;
			}*/
			break;	
		}

		default:
			cout <<"Existing the program" << endl;
		}
	} while (option != 3);
}


int Menu::get_option(void) {
		int op = 0;
		std::cin >> op;
		return op;
}