/*
 * Animal.h
 *
 *  Created on: Jan 6, 2022
 *      Author: ise
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_
#include "priceList.h"

class Animal {
protected:
	int age;
	int die_age;
	int price;
public:
	Animal();
	virtual ~Animal(){};
	int yield();
	bool nextYear();
};

#endif /* ANIMAL_H_ */
