/*
Authors: Brett Ballew And Ben Byerly
File Name: VideoGame.cpp
Purpose of File: Contains the function definitions of the VideoGame class.
Most Recent Edit: 2-10-2023
File Status: DONE
*/

#include "VideoGame.h"
#include "Text.h"

VideoGame::VideoGame(Text* title, Text* developer, Text* publisher, int year){		//DONE
	vgTitle = title;
	vgDeveloper = developer;
	vgPublisher = publisher;			//Constructor with set parameters needed as input
    vgYear = year;
}

VideoGame::~VideoGame(){		//DONE
	delete vgTitle;
	delete vgDeveloper;		//free's up space allocated by VideoGame constructor
	delete vgPublisher;
	cout << "VideoGame destuctor: Released memory for VideoGame object.\n\n";
}

void VideoGame::printVideoGameDetails(){			//DONE
	cout << right << setw(30) << "Game Title:  " << left;
	vgTitle->displayText();
	cout << endl;

	cout << right << setw(30) << "Developer:  " << left;
	vgDeveloper->displayText(); 
	cout << endl;

	cout << right << setw(30) << "Publisher:  " << left;
	vgPublisher->displayText();
	cout << endl;
	
	cout << right << setw(30) << "Year Released:  " << left; 
	cout << vgYear;
	cout << endl;
}

void VideoGame::printVideoGameDetailsToFile(ofstream &outFile){
	char temp[99];
	strncpy(temp, vgTitle->getText(), 99);			
	outFile << temp << endl;

	strncpy(temp, vgDeveloper->getText(), 99);		//copies cstring to temp char arr and outputs to file
	outFile << temp << endl;

	strncpy(temp, vgPublisher->getText(), 99);		
	outFile << temp << endl;

	outFile << vgYear << endl;
}

Text* VideoGame::getVideoGameTitle() const{
	return vgTitle;
}


