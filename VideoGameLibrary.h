/*
Authors: Brett Ballew And Ben Byerly
File Name: VideoGameLibrary.h
Purpose of File: Contains the VideoGameLibrary class definition.
Most Recent Edit: 2-10-2023
File Status: DONE
*/

#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include "VideoGame.h"
#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

class VideoGameLibrary{
	public:
		VideoGameLibrary(int);	//Function dynamically allocates array of ptrs to VideoGame objects the constructor only requires an integer to determine size of array.
		~VideoGameLibrary();		//frees memory allocated by VideoGameLib constructor
		void addVideoGameToArray();		//called to add single video game to library, calls VideoGame contstructor and can call resizeVideoGameArray
		void displayVideoGames();		//all video games displayed to terminal
		void displayVideoGameTitles();		//prints only movie game titles to chose which one to remove
		void loadVideoGamesFromFile(char* filename);		//checks to see if file exists and extracts data if oriented in proper order
															//(title,developer,publisher,year)
		void removeVideoGameFromArray();		//Removes single video game. obvi, canlls displayVideoGameTitle to print all video game tites to end user.
		void saveToFile(char *filename);		//saves data into file named by user in this order
												//(title,developer,publisher,year)
		
	private:
		VideoGame **VideoGamesArray; 			//array of pointers pointing to individuals VideoGame objects
		int maxGames; 						
		int numGames; 
		void resizeVideoGameArray();			//if video game is added and array is not big enough
};												//creates new array 2x the size and copies over elements

#endif


