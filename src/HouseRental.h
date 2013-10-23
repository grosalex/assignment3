/*
 * HouseRental.h
 *
 *  Created on: 23 oct. 2013
 *      Author: William
 */

#ifndef HOUSERENTAL_H_
#define HOUSERENTAL_H_

#include "Property.h"

class HouseRental: public Property {
public:
	HouseRental(string, string, Customer, RealEstateAgent, Date, int, int, int);
	virtual ~HouseRental();
	virtual void print();

private:
	int year_of_built;
	int no_of_rooms;
	int monthly_rental;
};

#endif /* HOUSERENTAL_H_ */
