/*
Authors: Brett Ballew And Ben Byerly
File Name: VideoGame.h
Purpose of File: Contains the VideoGame Class definition.
Most Recent Edit: 2-10-2023
File Status: Done
*/

#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "Text.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

class VideoGame{

	public:
		VideoGame(Text*, Text*, Text*, int); 				 //gets called when all videogame information is knows and creats new video game with this info.
		~VideoGame();										 //Automatically called when a VideoGame object is destroyed and prints to screen.
		void printVideoGameDetails();						 //gets called when the user wants to print all the video game information to the screen.
		void printVideoGameDetailsToFile(ofstream &outFile); //gets called when the user wants to print all game information to a file.
		Text* getVideoGameTitle() const;					 //accessor function containing videoGame title.
    private: 
		Text* vgTitle;   
		Text* vgDeveloper; //vg stands for videogame. If one couldn't tell :D
		Text* vgPublisher; 
		int vgYear;
};


#endif