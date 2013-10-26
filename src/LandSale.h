/*
 * LandSale.h
 *
 *  Created on: 23 oct. 2013
 *      Author: grosalex
 */

#ifndef LANDSALE_H_
#define LANDSALE_H_
#include "Property.h"
class LandSale : public Property{

public:
	LandSale(string, string, Customer, RealEstateAgent, Date, double, int);
	~ LandSale( );
	virtual void print( );
	double getArea() const;
	void setArea(double area);
	int getPrice() const;
	void setPrice(int price);

private:
	double area;
	int price;

};

#endif /* LANDSALE_H_ */
