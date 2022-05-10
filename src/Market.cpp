/*
 * Market.cpp
 *
 *  Created on: Jan 6, 2022
 *      Author: ise
 */

#include "Market.h"
#include "cowFarm.h"
#include "sheepFarm.h"
#include "chickenFarm.h"
#include "exp.h"

Market::Market(){
	year = 0;
}

Market::~Market(){
	vector<Farm*>::iterator it;
	for(it=Farms.begin(); it != Farms.end(); ++it)
		delete *it;
	Farms.clear();
}

int Market::getYear(){
	return year;
}

void Market::nextYear(){
	year++;
	crateNewFarms();
	farmsProduction();
	tradeWithOthers();
	purchaseAnimals();
	farmsNextYear();
}

void Market::fastForwardYears(){
	int count;
	cout << "How many years to fast forward?" << endl;
	cin >> count;

	year += count;

	for(int i=0; i<count; i++){
		farmsProduction();
		tradeWithOthers();
		purchaseAnimals();
		farmsNextYear();
	}
}

void Market::printMarketFarms(){
	cout << "----Market Farms----" << endl;
	vector<Farm*>::iterator it;
	for(it=Farms.begin(); it != Farms.end(); ++it)
		cout << **it;
}

void Market::crateNewFarms(){
	int cow_farms, sheep_farms, chicken_farms;
	cout << "----Creating new farms----" << endl;
	while(true){
	try{
		cout << "How many new cow farms will be added this year?" << endl;
		cin >> cow_farms;
		if(cow_farms < 0)
			throw CowException();
		cout << "How many new sheep farms will be added this year?" << endl;
		cin >> sheep_farms;
		if(sheep_farms < 0)
			throw SheepException();
		cout << "How many new chicken farms will be added this year?" << endl;
		cin >> chicken_farms;
		if(chicken_farms < 0)
			throw ChickenException();
		break;
	}
	catch( exception& e ){
		cout << e.what();
	}
	}

	cout << "----Adding new farms to market----" << endl;
	Farm* farm;
	vector<Farm*>::iterator it;
	int i;
	for(i=0; i<cow_farms; i++){
		farm = new cowFarm();
		for(it=Farms.begin(); it != Farms.end(); ++it){
			farm->addClient(*it);
			(*it)->addClient(farm);
		}
		Farms.push_back(farm);
	}
	for(i=0; i<sheep_farms; i++){
		farm = new sheepFarm();
		for(it=Farms.begin(); it != Farms.end(); ++it){
			farm->addClient(*it);
			(*it)->addClient(farm);
		}
		Farms.push_back(farm);
	}
	for(i=0; i<chicken_farms; i++){
		farm = new chickenFarm();
		for(it=Farms.begin(); it != Farms.end(); ++it){
			farm->addClient(*it);
			(*it)->addClient(farm);
		}
		Farms.push_back(farm);
	}

}

void Market::farmsProduction(){
	vector<Farm*>::iterator it;
	for(it=Farms.begin(); it != Farms.end(); ++it)
			(*it)->production();
}

void Market::tradeWithOthers(){
	cout << "----Begin Market----" << endl;
	vector<Farm*>::iterator it;
	for(it=Farms.begin(); it != Farms.end(); ++it)
			(*it)->sellProduct();
}

void Market::purchaseAnimals(){
	cout << "----Buy Animals----" << endl;
	vector<Farm*>::iterator it;
	for(it=Farms.begin(); it != Farms.end(); ++it)
			(*it)->buy_animals();
}

void Market::farmsNextYear(){
	vector<Farm*>::iterator it;
	for(it=Farms.begin(); it != Farms.end(); ++it)
		(*it)->nextYear();
}

