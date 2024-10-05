/*
Authors: Brett Ballew And Ben Byerly
File Name: Text.h
Purpose of File: Contains the text class definition.
Most Recent Edit: 2-10-2023
File Status: DONE
*/

#ifndef TEXT_H
#define TEXT_H

#include <iostream>

using namespace std;

class Text{
    public:
		Text(const char*);				//gets called when a text object is created and dynamically allocates char array. 
		~Text();						//releases memory for c-string pointed to by textArray.
		void displayText() const;	    //print the c-string to the screen.
		const char* getText() const;	//accessor function that returns a pointer 
		int getLength() const;			//accessor function that returns length of the string.

	private:
		const char* textArr;
		int textLength;
}; 

#endif