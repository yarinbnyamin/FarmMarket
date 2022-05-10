/*
 * Animal.cpp
 *
 *  Created on: Jan 6, 2022
 *      Author: ise
 */

#include "Animal.h"

Animal::Animal() {
	age = 0;
}

int Animal::yield(){
	return age;
}

bool Animal::nextYear(){
	age++;
	return age == die_age;
}
