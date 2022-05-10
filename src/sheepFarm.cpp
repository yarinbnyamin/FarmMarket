/*
 * sheepFarm.cpp
 *
 *  Created on: Jan 9, 2022
 *      Author: ise
 */

#include "sheepFarm.h"

sheepFarm::sheepFarm() {
	for(int i=0; i<start_animals; i++)
		Animals.push_back(new Sheep());
}

void sheepFarm::production(){
	vector<Animal*>::iterator it;
	for(it=Animals.begin(); it != Animals.end(); ++it)
		Wool += (*it)->yield();
}

void sheepFarm::buy_animals(){

	int buy = Money / sheep_price;

	if(buy == 0)
		return;

	for(int i=0; i<buy; i++)
		Animals.push_back(new Sheep());

	Money %= sheep_price;

	cout << "Sheep farm(" << ID << ") bought " << buy << " sheeps for " << buy*sheep_price << " dollars" << endl;
}

void sheepFarm::print(std::ostream& os) const{
	os << "Farm Id: " << ID << ", type: Sheep farm, Money: " << Money << ", Animals: " << Animals.size()
			<< " sheep, Products: Milk[" << Milk << "], Wool[" << Wool << "], Eggs[" << Eggs << "]" << endl;
}

void sheepFarm::addClient(Farm* farm){
	if(!farm->want_wool())
		return;
	Clients.push_back(farm);
	cout << "Sheep farm(" << ID << ") Added Chicken farm(" << farm->getID() << ") to his client list" << endl;
}

void sheepFarm::buyProduct(const int seller_id, int &seller_inventory, int &seller_money){
	if(seller_inventory == 0 || Money == 0 || Money / milk_price == 0)
		return;

	int buy = Money / milk_price;

	if(seller_inventory < buy)
		buy = seller_inventory;

	Milk += buy;
	seller_inventory -= buy;

	Money -= buy*milk_price;
	seller_money += buy*milk_price;

	cout << "Sheep farm(" << ID << ") bought " << buy << " milk for " << buy*milk_price << " dollars from Cow farm(" << seller_id << ")" << endl;
}

void sheepFarm::sellProduct(){
	vector<Farm*>::iterator it;
	for(it=Clients.begin(); it != Clients.end(); ++it){
		(*it)->buyProduct(ID, Wool, Money);
		if(Wool == 0)
			break;
	}
}
