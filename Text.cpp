/*
Authors: Brett Ballew And Ben Byerly
File Name: Text.cpp
Purpose of File: Contains function definitions of Text class.
Most Recent Edit: 2-10-2023
File Status: DONE
*/

#include "Text.h"
#include <iostream>
#include <cstring>

using namespace std;

Text::Text(const char* text){	
	textLength = strlen(text);
	char* tempArr = new char[(textLength)+1];   //creates an character array that can be pointed to
	strcpy(tempArr, text); 						//by the text array pointer in class object Text.
	this->textArr = tempArr;
}

Text::~Text(){
	delete [] textArr;  //simply frees memeory used by textArr
	cout << "Text destructor: Released memory for textArray.\n";
}

void Text::displayText() const{
	cout << textArr;			//just displays the save input
}

const char* Text::getText() const{      //returns the text
	return textArr;
}

int Text::getLength() const{
	return textLength;			//returns lemf of text
}

