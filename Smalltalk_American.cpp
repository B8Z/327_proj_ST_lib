/*
 * Smalltalk_American.cpp
 *
 *  Created on: Nov 23, 2019
 *      Author: Adam Bates
 */
#include "./includes/constants.h"
#include "./includes/Smalltalk_American.h"

/**
 * Constructor that initializes Smalltalk_American and calls both populatePhrases & the Smalltalk constructor.
 * @param iPerson - int value that is a counter used to distinguish between objects of the same type.
 */
Smalltalk_American::Smalltalk_American(int iPerson) :
		Smalltalk(AMERICAN, iPerson) {
	populatePhrases();
}

/**
 * Constructor that initializes Smalltalk_American and calls both populatePhrases & the Smalltalk constructor.
 * @param iPerson - int value that is a counter used to distinguish between objects of the same type.
 * @param myNationality - string value that represents the person's nationality
 */
Smalltalk_American::Smalltalk_American(std::string myNationality, int iPerson) :
		Smalltalk(myNationality, iPerson) {
	populatePhrases();
}

Smalltalk_American::~Smalltalk_American(void) {
}

/**
 * Populates mySmallTalk vector with American phrases
 */
void Smalltalk_American::populatePhrases() {
	mySmallTalk.push_back(AMERICAN_PHRASE_1);
	mySmallTalk.push_back(AMERICAN_PHRASE_2);
	mySmallTalk.push_back(AMERICAN_PHRASE_3);
	mySmallTalk.push_back(AMERICAN_PHRASE_4);
	mySmallTalk.push_back(AMERICAN_PHRASE_5);
}

