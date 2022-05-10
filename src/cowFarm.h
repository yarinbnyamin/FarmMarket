/*
 * cowFarm.h
 *
 *  Created on: Jan 9, 2022
 *      Author: ise
 */

#ifndef COWFARM_H_
#define COWFARM_H_

#include "Farm.h"
#include "Cow.h"

class cowFarm: public Farm {
protected:
	virtual void print(std::ostream& os) const;
public:
	cowFarm();
	virtual ~cowFarm(){};
	virtual void production();
	virtual void buy_animals();
	virtual void addClient(Farm* farm);
	virtual void buyProduct(const int seller_id, int &seller_inventory, int &seller_money);
	virtual void sellProduct();
	virtual bool want_milk(){return false;};
	virtual bool want_wool(){return false;};
	virtual bool want_eggs(){return true;};
};

#endif /* COWFARM_H_ */
