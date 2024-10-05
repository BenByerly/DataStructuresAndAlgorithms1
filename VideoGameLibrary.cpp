/*
Authors: Brett Ballew And Ben Byerly
File Name: VideoGameLibrary.cpp
Purpose of File: Contains the function definitions of the VideoGameLibrary class.
Most Recent Edit: 2-10-2023
File Status: DONE
*/

#include "VideoGameLibrary.h"

VideoGameLibrary::VideoGameLibrary(int max){		//DONE
	maxGames = max;
	numGames = 0;					//constructor that dynamically creates an empty array the size of the input
	VideoGamesArray = new VideoGame*[max];
}

VideoGameLibrary::~VideoGameLibrary(){			//DONE
	for(int x = 0; x < numGames; x++){
		delete VideoGamesArray[x];    //goes through array and deletes individual videogames
	}
	delete [] VideoGamesArray;
}

void VideoGameLibrary::addVideoGameToArray(){		//DONE
	char temp[99];
	Text* title;
	Text* developer;
	Text* publisher;
    int year;
	
	cin.ignore();  
	cout << "\nVideo Game TITLE: ";
	cin.getline(temp, 99);		//Takes in user input for title and assigns to a dynamically allocated
	title = new Text(temp);		//text object

	cout << "\nVideo Game DEVELOPER: ";
	cin.getline(temp,99);			//does the same thing as before but for publisher
	developer = new Text(temp);

	cout << "\nVideo Game PUBLISHER: ";
	cin.getline(temp, 99);
	publisher = new Text(temp);

	cout << "\nVideo Game YEAR: ";
	cin >> year;
	cin.ignore();
    
	VideoGame* game = new VideoGame(title, developer, publisher, year); //dynamically allocates new video game object
	
	if(numGames == maxGames){
		resizeVideoGameArray();	//in the event the array is already at the max. We call to resize array
	}

	VideoGamesArray[numGames] = game; //adds the new game to the next open spot in the array
	numGames = numGames + 1; //increments the current amount of games in array
}

void VideoGameLibrary::displayVideoGames(){		//DONE
	if(numGames > 0){							
		for(int x = 0; x < numGames; x++){
			cout << endl << right << setw(50) << "----------Video Game " << (x+1) << "----------\n";		//Called to print all video games to terminal
			VideoGamesArray[x]->printVideoGameDetails(); 
		}
		cout << endl;
	}else{	
		cout << "\nThere are no video games in your library.";
	}
}

void VideoGameLibrary::displayVideoGameTitles(){		//DONE

	Text* VideoGameTitle;
	
	for(int x=0; x<numGames; x++){
		cout << "\nVideo Game " << (x +1 ) << ": ";
		VideoGameTitle = VideoGamesArray[x]->getVideoGameTitle();		//self explanatory
		VideoGameTitle->displayText();
	}
}

void VideoGameLibrary::loadVideoGamesFromFile(char *filename){ //DONE
	ifstream inFile;
	
	int gamesAdded = 0;
	char temp[99];

	Text* title;
	Text* developer;		//just defining all the variables or pointers
	Text* publisher;
	int year;
	VideoGame* game;
	
	inFile.open(filename);
	if(inFile.is_open()){

		inFile.getline(temp, 99);		//gets first line to make sure it's not an empty file

		while(!inFile.eof()){	
			title = new Text(temp);		//if not empty starts assigning values 	

			inFile.getline(temp,99);
			developer = new Text(temp);

			inFile.getline(temp,99);
			publisher = new Text(temp);
			
			inFile >> year;
			inFile.ignore();
			
			game = new VideoGame(title, developer, publisher, year);		//creating videogame bj
		
			if(numGames == maxGames){
				resizeVideoGameArray();		//move array to new array double the size
            }

			VideoGamesArray[numGames] = game;		//assign next increment to newly created nugget

			(numGames)++;		//increment the nugget      
			
			cout << endl;
			title->displayText();		//Display the title as added using display text func

			cout << " was added successfully!";	

			inFile.getline(temp, 99);
			gamesAdded = gamesAdded + 1;
		}

		cout << "\n" << gamesAdded << " video games were read from the file and added to your video game library.\n";

	}else{
		cout << "Sorry, I was unable to open the file.\n";
	}
}

void VideoGameLibrary::removeVideoGameFromArray(){		//DONE
	int videoGameChoice;
	
	if(numGames <= 1){
	   cout << endl << "Cannot remove a video game from the library as it is empty or only has one game.\n";		//incase the user is an opp
	}else{
		cout << "\n\nChoose from the following video games to remove:\n";
		displayVideoGameTitles();
		cout << "\nChoose a video game to remove between " << 1 << " & " << numGames << ":  ";
		cin >> videoGameChoice;
		cin.ignore();		
		
		while(videoGameChoice < 1 || videoGameChoice > numGames){
			cout << endl << videoGameChoice << " is not an option. Enter a number between " << 1 << " & " << numGames << ":  ";
			cin >> videoGameChoice;
		}

		Text* VideoGameTitle;
		VideoGameTitle = VideoGamesArray[videoGameChoice-1]->getVideoGameTitle();
		
		cout << "\n\nThe video game \"";
		VideoGameTitle->displayText();					//Lets em know exactly what game they are removing
		cout << "\" has been successfully deleted.\n\n";	
		
		delete VideoGamesArray[videoGameChoice-1];		//freeing memory taken up by the videogame
		
		
		for(int x = videoGameChoice-1; x < numGames - 1; x++){
			VideoGamesArray[x] = VideoGamesArray[x+1];		//Moves over all values
		}
		
		VideoGamesArray[numGames - 1] = NULL;		//sets the last space to /0
		
		numGames = numGames - 1;	
	}
}

void VideoGameLibrary::saveToFile(char *filename){		//DONE

	ofstream outFile;

	outFile.open(filename);		//creates or overrides text file

	for(int x = 0; x < numGames; x++){
		VideoGamesArray[x]->printVideoGameDetailsToFile(outFile);
	}

	outFile.close();
	cout << "\nAll video games in your library have been printed to " << filename << endl;
}

void VideoGameLibrary::resizeVideoGameArray(){		//DONE

	cout << "\nResizing VideoGameArray from " << maxGames << " to " << maxGames * 2 << ".";

	VideoGame** newVideoGamesArray = new VideoGame*[maxGames * 2];

	for(int x = 0; x < numGames; x++){
		newVideoGamesArray[x] = VideoGamesArray[x];
	}

	delete [] VideoGamesArray;

	VideoGamesArray = newVideoGamesArray;
	maxGames = maxGames * 2;
}

