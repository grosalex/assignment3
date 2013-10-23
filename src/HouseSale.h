/*
 * HouseSale.h
 *
 *  Created on: 23 oct. 2013
 *      Author: grosalex
 */

#ifndef HOUSESALE_H_
#define HOUSESALE_H_
#include <string>
#include "Property.h"
class HouseSale : public Property{
public:
	HouseSale(string, string, Customer, RealEstateAgent, Date, int, int, int);
	~ HouseSale();
	virtual void print();
	int getNoOfRooms() const;
	void setNoOfRooms(int noOfRooms);
	int getPrice() const;
	void setPrice(int price);
	int getYearOfBuilt() const;
	void setYearOfBuilt(int yearOfBuilt);

private:
	int year_of_built;
	int no_of_rooms;
	int price;
};

#endif /* HOUSESALE_H_ */
