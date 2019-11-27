/*
 * Smalltalk_Brit.cpp
 *
 *  Created on: Nov 23, 2019
 *      Author: Adam Bates
 */
#include "./includes/constants.h"
#include "./includes/Smalltalk_Brit.h"

/**
 * Constructor that initializes Smalltalk_Brit and calls both populatePhrases & the Smalltalk constructor.
 * @param iPerson - int value that is a counter used to distinguish between objects of the same type.
 */
Smalltalk_Brit::Smalltalk_Brit(int iPerson) :
		Smalltalk(BRIT, iPerson) {
	populatePhrases();
}

Smalltalk_Brit::~Smalltalk_Brit(void) {
}

/**
 * Populates mySmallTalk vector with Brit phrases
 */
void Smalltalk_Brit::populatePhrases() {
	mySmallTalk.push_back(BRIT_1);
	mySmallTalk.push_back(BRIT_2);
	mySmallTalk.push_back(BRIT_3);
	mySmallTalk.push_back(BRIT_4);
	mySmallTalk.push_back(BRIT_5);
	mySmallTalk.push_back(BRIT_6);
	mySmallTalk.push_back(BRIT_7);
}

