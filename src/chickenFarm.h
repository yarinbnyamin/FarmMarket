/*
 * chickenFarm.h
 *
 *  Created on: Jan 9, 2022
 *      Author: ise
 */

#ifndef CHICKENFARM_H_
#define CHICKENFARM_H_

#include "Farm.h"
#include "Chicken.h"

class chickenFarm: public Farm {
protected:
	virtual void print(std::ostream& os) const;
public:
	chickenFarm();
	virtual ~chickenFarm(){};
	virtual void production();
	virtual void buy_animals();
	virtual void addClient(Farm* farm);
	virtual void buyProduct(const int seller_id, int &seller_inventory, int &seller_money);
	virtual void sellProduct();
	virtual bool want_milk(){return false;};
	virtual bool want_wool(){return true;};
	virtual bool want_eggs(){return false;};
};

#endif /* CHICKENFARM_H_ */
