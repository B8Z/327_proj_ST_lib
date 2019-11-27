/*
 * Functions.cpp
 *
 *  Created on: Nov 23, 2019
 *      Author: Adam Bates
 */
#include <iostream>
#include <memory>

#include "./includes/constants.h"
#include "./includes/Functions.h"
#include "./includes/Smalltalk_American.h"
#include "./includes/Smalltalk_Brit.h"
#include "./includes/ST_American_DonutEnthusiest.h"
#include "./includes/Watch.h"

/**
 * Create a vector with appropriate numbers of Smalltalk_Brit,Smalltalk_American and ST_American_DonutEnthusiest
 * objects using unique pointers.  Watches are given sequentially starting with first person in the vector until
 * all watches given or everyone has a watch (case where more watches than people).
 * @param numBrit - int value that holds the number of brits.
 * @param numAmerican - int value that holds the number of Americans.
 * @param numbAmericanDonutEnthusiest - int value that holds the number of ST_American_DonutEnthusiest.
 * @param numWatches - int value that holds the number of watches.
 * @return Smalltalk_Holder - vector containing all given Smalltalk_Brit,Smalltalk_American and ST_American_DonutEnthusiest
 * 		objects.  Also keeps track of watches for given objects.
 */
std::vector<std::unique_ptr<Smalltalk>> getPeople(int numBrit, int numAmerican,
		int numbAmericanDonutEnthusiest, int numWatches) {

	//create a vector to hold SmallTalk unique pointers
	std::vector<std::unique_ptr<Smalltalk>> Smalltalk_Holder;
	int size = numAmerican + numbAmericanDonutEnthusiest + numBrit;

	for (int i = 0; i < size; i++) {
		//add brits to vector
		if (i <= numBrit) {
			Smalltalk_Holder.push_back(
					std::unique_ptr<Smalltalk_Brit>(new Smalltalk_Brit(i)));
		}
		//add americans  to vector
		else if (i <= numAmerican && i > numBrit) {
			Smalltalk_Holder.push_back(
					std::unique_ptr<Smalltalk_American>(
							new Smalltalk_American(i)));
		}
		//add american donut enthusiest  to vector
		else if (i <= size && i > numAmerican) {
			Smalltalk_Holder.push_back(
					std::unique_ptr<ST_American_DonutEnthusiest>(
							new ST_American_DonutEnthusiest(i)));
		}
	}

	//create some watches (as long as number watches <= numb people)
	int num_watches_holder = numWatches;

	if (num_watches_holder > (int) Smalltalk_Holder.size()) {
		num_watches_holder = (int) Smalltalk_Holder.size();
	}

	//then give the watches away to first NUM_WATCHES people in the vector
	for (int i = 0; i < num_watches_holder; i++) {
		std::unique_ptr<Watch> pWatch(new Watch());
		Smalltalk_Holder[i]->giveWatch(pWatch);
	}

	//return vector
	return Smalltalk_Holder;
}
