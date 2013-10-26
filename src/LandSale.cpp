/*
 * LandSale.cpp
 *
 *  Created on: 23 oct. 2013
 *      Author: grosalex
 */

#include "LandSale.h"

LandSale::LandSale(string inStreet, string inCity, Customer inLandLord , RealEstateAgent inAgent , Date inListing, double inArea , int inPrice)
: Property(inStreet, inCity, inLandLord , inAgent , inListing){
	area=inArea;
	price=inPrice;
}

LandSale::~LandSale(){
	// TODO !CodeTemplates.destructorstub.tododesc!
}

void LandSale::print() {
	Property::print();
	cout << "\n Area : " << area << endl;
	cout << "Price : " << price;
}

double LandSale::getArea() const {
	return area;
}

void LandSale::setArea(double area) {
	this->area = area;
}

int LandSale::getPrice() const {
	return price;
}

void LandSale::setPrice(int price) {
	this->price = price;
}
