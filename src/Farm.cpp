/*
 * Farm.cpp
 *
 *  Created on: Jan 6, 2022
 *      Author: ise
 */

#include "Farm.h"

int Farm::count = 0;
const int Farm::start_animals = 3;

Farm::Farm() {
	count++;
	ID = count;
	Money = 10;
	Milk = 0;
	Wool = 0;
	Eggs = 0;
}

Farm::~Farm() {
	vector<Animal*>::iterator it;
	for(it=Animals.begin(); it != Animals.end(); ++it)
		delete *it;
	Animals.clear();
	Clients.clear();
}

ostream& operator<<(ostream& os, const Farm& me){
	me.print(os);
	return os;
}

void Farm::nextYear(){
	vector<Animal*>::iterator it;
	for(it=Animals.begin(); it != Animals.end(); ++it){
		if((*it)->nextYear()){
			delete *it;
			Animals.erase(it);
			it--;
		}
	}
	Money += 10;
}

int Farm::getID(){
	return ID;
}

