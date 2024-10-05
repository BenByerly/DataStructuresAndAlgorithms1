/*
Course: CSC 1310, Section 002
Due Date: 2/15/2023
Authors: Brett Ballew And Ben Byerly
File Name: Program1.cpp
Purpose of File: Driver file that uses the VideoGameLibrary class to create an object for the user to alter.
Most Recent Edit: 2-10-2023
File Status: DONE
*/

#include "Text.h"
#include "VideoGame.h"
#include "VideoGameLibrary.h"

#include <iostream>

using namespace std;

int main(){

	int input;
	int maxGames;		//Variables to store user intitial input
	char filename[99];  
	ifstream infile;
	
	cout << "\n\nHow many video games can your library hold?\n";
	cin >> maxGames;
	cin.ignore();												//Determines the initial size of the video game library
	
	while(maxGames < 1){
		cout << "You must enter a number greater than or equal to one for the library size.\n";
		cout << "\nHow many video games can your library hold?\n";					//In the event the user inters an integer lower than 1
		cin >> maxGames;
		cin.ignore();
	}

	VideoGameLibrary* videoGameLibrary = new VideoGameLibrary(maxGames);  //dynamically allocating a VideaGameLibrary the size of the user input
	
	do{
		cout << "What would you like to do?\n";
		cout << "1.  Load video games from file.\n";
		cout << "2.  Save video games to a file.\n";
		cout << "3.  Add a video game.\n";		//runs through the menu at least once
		cout << "4.  Remove a video game.\n";	//written as shown by the sample output
		cout << "5.  Display all video games.\n";
		cout << "6.  Remove ALL video games from this Library and end program.\n";
		cout << "CHOOSE 1-6:  ";
		cin >> input;

		while(input < 1 || input > 6){
			cout << "That is not a valid choice.\n";
			cout << "CHOOSE 1-6:  ";				//in the event the user can't follow instructions
			cin >> input;
		}
		
		switch(input){
			case 1:
				cout << "\nWhat is the name of the file? (example.txt):  ";
				cin >> filename;
				videoGameLibrary->loadVideoGamesFromFile(filename); //filname is sent to fucntion where the file is attempted to be opened.
				cout << endl;												//and data extracted if so.
				break;
					
			case 2:
				cout << "\n\nWhat do you want to name the file? (example.txt):  ";
				cin >> filename;
				videoGameLibrary->saveToFile(filename);  //calls saveToFile function to save video games to file
				cout << endl << endl;
				break;
					
			case 3:
				videoGameLibrary->addVideoGameToArray(); //adds single video game to array
				cout << endl << endl;
				break;
					
			case 4:
				videoGameLibrary->removeVideoGameFromArray(); //removes on video game from array
				cout << endl;
				break;
					
			case 5:
				videoGameLibrary->displayVideoGames(); //displays all video games on the terminal
				cout << endl << endl;
				break;
					
			case 6:
				cout << endl;
				delete videoGameLibrary; //frees all memory allocated by video game library array
				break;
		}	
	} while(input != 6);
	
	cout << "\nGOODBYE!";
	
	return 0;
}
