/*
 * Farm.h
 *
 *  Created on: Jan 6, 2022
 *      Author: ise
 */

#ifndef FARM_H_
#define FARM_H_

#include <iostream>
#include "Animal.h"
#include <vector>
using namespace std;

class Farm {
private:
	static int count;
protected:
	int ID;
	int Money;
	vector<Animal*> Animals;
	vector<Farm*> Clients;
	int Milk;
	int Wool;
	int Eggs;

	static const int start_animals;  // how much animals each farm start with

	virtual void print(std::ostream& os) const = 0;
public:
	Farm();
	virtual ~Farm();
	virtual void production()=0;
	virtual void buy_animals()=0;
	friend ostream& operator<<(ostream& os, const Farm& me);
	virtual void addClient(Farm* farm)=0;
	virtual void buyProduct(const int seller_id, int &seller_inventory, int &seller_money)=0;  // get the id, max inventory and money of the seller
	virtual void sellProduct()=0;
	virtual bool want_milk()=0;
	virtual bool want_wool()=0;
	virtual bool want_eggs()=0;
	void nextYear();
	int getID();
};

#endif /* FARM_H_ */
