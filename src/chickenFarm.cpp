/*
 * chickenFarm.cpp
 *
 *  Created on: Jan 9, 2022
 *      Author: ise
 */

#include "chickenFarm.h"

chickenFarm::chickenFarm() {
	for(int i=0; i<start_animals; i++)
		Animals.push_back(new Chicken());
}

void chickenFarm::production(){
	vector<Animal*>::iterator it;
	for(it=Animals.begin(); it != Animals.end(); ++it)
		Eggs += (*it)->yield();
}

void chickenFarm::buy_animals(){

	int buy = Money / chicken_price;

	if(buy == 0)
		return;

	for(int i=0; i<buy; i++)
		Animals.push_back(new Chicken());

	Money %= chicken_price;

	cout << "Chicken farm(" << ID << ") bought " << buy << " chickens for " << buy*chicken_price << " dollars" << endl;
}

void chickenFarm::print(std::ostream& os) const{
	os << "Farm Id: " << ID << ", type: Chicken Farm, Money: " << Money << ", Animals: " << Animals.size()
			<< " chickens, Products: Milk[" << Milk << "], Wool[" << Wool << "], Eggs[" << Eggs << "]" << endl;
}

void chickenFarm::addClient(Farm* farm){
	if(!farm->want_eggs())
		return;
	Clients.push_back(farm);
	cout << "Chicken farm(" << ID << ") Added Cow farm(" << farm->getID() << ") to his client list" << endl;
}

void chickenFarm::buyProduct(const int seller_id, int &seller_inventory, int &seller_money){
	if(seller_inventory == 0 || Money == 0 || Money / wool_price == 0)
		return;

	int buy = Money / wool_price;

	if(seller_inventory < buy)
		buy = seller_inventory;

	Wool += buy;
	seller_inventory -= buy;

	Money -= buy*wool_price;
	seller_money += buy*wool_price;

	cout << "Chicken farm(" << ID << ") bought " << buy << " wool for " << buy*wool_price << " dollars from Sheep farm(" << seller_id << ")" << endl;
}

void chickenFarm::sellProduct(){
	vector<Farm*>::iterator it;
	for(it=Clients.begin(); it != Clients.end(); ++it){
		(*it)->buyProduct(ID, Eggs, Money);
		if(Eggs == 0)
			break;
	}
}
