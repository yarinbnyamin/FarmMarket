/*
 * sheepFarm.h
 *
 *  Created on: Jan 9, 2022
 *      Author: ise
 */

#ifndef SHEEPFARM_H_
#define SHEEPFARM_H_

#include "Farm.h"
#include "Sheep.h"

class sheepFarm: public Farm {
protected:
	virtual void print(std::ostream& os) const;
public:
	sheepFarm();
	virtual ~sheepFarm(){};
	virtual void production();
	virtual void buy_animals();
	virtual void addClient(Farm* farm);
	virtual void buyProduct(const int seller_id, int &seller_inventory, int &seller_money);
	virtual void sellProduct();
	virtual bool want_milk(){return true;};
	virtual bool want_wool(){return false;};
	virtual bool want_eggs(){return false;};
};

#endif /* SHEEPFARM_H_ */
