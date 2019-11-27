/*
 * ST_American_DonutEnthusiest.cpp
 *
 *  Created on: Nov 23, 2019
 *      Author: Adam Bates
 */
#include "./includes/constants.h"
#include "./includes/Smalltalk.h"
#include "./includes/ST_American_DonutEnthusiest.h"

using namespace std;

/**
 * Constructor that initializes ST_American_DonutEnthusiest and calls both populatePhrases & the Smalltalk_American constructor.
 * @param iPerson - int value that is a counter used to distinguish between objects of the same type.
 */
ST_American_DonutEnthusiest::ST_American_DonutEnthusiest(int iPerson) :
		Smalltalk_American(AMERICAN_DE, iPerson) {
	populatePhrases();
}

Smalltalk::Smalltalk(std::string myNationality, int iPerson) :
		nationality(myNationality), iPerson(iPerson), current_phrase(-1) {
}

Smalltalk::~Smalltalk(void) {
}

/**
 * Cycles through phrases added in populatePhrases. Returns them 1 by 1 starting with the first and ending
 * with the last and then it starts over,
 * takes the form Nationality iPerson: phrase.
 * @return - string value that contains the formatted phrase.
 */
std::string Smalltalk::saySomething() {
	std::string phrase(nationality + " " + std::to_string(iPerson++) + ": ");
	current_phrase = (current_phrase + 1) % mySmallTalk.size();
	phrase += mySmallTalk[current_phrase];
	return phrase;
}

/**
 * Method that gets the time.
 * @return - string that returns the time (if pWatch contains a watch ) in the form of
 * THE_CURRENT_TIME_IS: (from the actual watch object itself) and then the time
 * or I_DO_NOT_HAVE_A_WATCH string (if pWatch does not contain a watch).
 */
std::string Smalltalk::getTime() {
	std::string phrase(THE_CURRENT_TIME_IS + ": ");
	if (this->pWatch == 0 || this->pWatch == nullptr) {
		return I_DO_NOT_HAVE_A_WATCH;
	}
	phrase += this->pWatch->getTime();
	return phrase;
}

/**
 * Transaction that simulates taking away a watch.
 * @return unique_ptr - where if this object has a watch it is taken away,
 * otherwise an empty unique_ptr is returned.
 */
std::unique_ptr<Watch> Smalltalk::takeWatch() {
	if (this->pWatch == 0 || this->pWatch == NULL) {
		std::unique_ptr<Watch> empty_watch;
		return empty_watch;
	}
	this->pWatch = NULL;
	std::unique_ptr<Watch> removed_watch(new Watch());
	return removed_watch;
}

/**
 * Transaction that simulates giving away a watch.
 * @param pWatch - unique_ptr that contains a pointer to the watch
 * @return false - if already have a watch and don't change pWatch pointer
 * 		   true - accept watch and set this->pWatch=pWatch (use std::move)
 */
bool Smalltalk::giveWatch(std::unique_ptr<Watch> &pWatch) {
	if (this->pWatch == 0 || this->pWatch == NULL) {
		this->pWatch = std::move(pWatch);
		return true;
	}
	return false;
}

ST_American_DonutEnthusiest::~ST_American_DonutEnthusiest(void) {
}

/**
 * Populates mySmallTalk vector with ST_American_DonutEnthusiest phrases.
 */
void ST_American_DonutEnthusiest::populatePhrases() {
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_1);
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_2);
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_3);
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_4);
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_5);
}

