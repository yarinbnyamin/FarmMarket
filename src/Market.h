/*
 * Market.h
 *
 *  Created on: Jan 6, 2022
 *      Author: ise
 */

#ifndef MARKET_H_
#define MARKET_H_

#include <iostream>
#include "Farm.h"
#include <vector>
using namespace std;


class Market {
private:
	int year;
	vector<Farm*> Farms;
public:
	Market();
	virtual ~Market();
	int getYear();
	void nextYear();
	void fastForwardYears();
	void printMarketFarms();
	void crateNewFarms();
	void farmsProduction();
	void tradeWithOthers();
	void purchaseAnimals();
	void farmsNextYear();
};

#endif /* MARKET_H_ */
