/*
 * cowFarm.cpp
 *
 *  Created on: Jan 9, 2022
 *      Author: ise
 */

#include "cowFarm.h"

cowFarm::cowFarm() {
	for(int i=0; i<start_animals; i++)
		Animals.push_back(new Cow());
}

void cowFarm::production(){
	vector<Animal*>::iterator it;
	for(it=Animals.begin(); it != Animals.end(); ++it)
		Milk += (*it)->yield();
}

void cowFarm::buy_animals(){

	int buy = Money / cow_price;

	if(buy == 0)
		return;

	for(int i=0; i<buy; i++)
		Animals.push_back(new Cow());

	Money %= cow_price;

	cout << "Cow farm(" << ID << ") bought " << buy << " cows for " << buy*cow_price << " dollars" << endl;
}

void cowFarm::print(std::ostream& os) const{
	os << "Farm Id: " << ID << ", type: Cow farm, Money: " << Money << ", Animals: " << Animals.size()
			<< " cows, Products: Milk[" << Milk << "], Wool[" << Wool << "], Eggs[" << Eggs << "]" << endl;
}

void cowFarm::addClient(Farm* farm){
	if(!farm->want_milk())
		return;
	Clients.push_back(farm);
	cout << "Cow farm(" << ID << ") Added Sheep farm(" << farm->getID() << ") to his client list" << endl;
}

void cowFarm::buyProduct(const int seller_id, int &seller_inventory, int &seller_money){
	if(seller_inventory == 0 || Money == 0 || Money / eggs_price == 0)
		return;

	int buy = Money / eggs_price;

	if(seller_inventory < buy)
		buy = seller_inventory;

	Eggs += buy;
	seller_inventory -= buy;

	Money -= buy*eggs_price;
	seller_money += buy*eggs_price;

	cout << "Cow farm(" << ID << ") bought " << buy << " eggs for " << buy*eggs_price << " dollars from Chicken farm(" << seller_id << ")" << endl;
}

void cowFarm::sellProduct(){
	vector<Farm*>::iterator it;
	for(it=Clients.begin(); it != Clients.end(); ++it){
		(*it)->buyProduct(ID, Milk, Money);
		if(Milk == 0)
			break;
	}
}
