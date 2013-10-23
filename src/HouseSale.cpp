/*
 * HouseSale.cpp
 *
 *  Created on: 23 oct. 2013
 *      Author: grosalex
 */

#include "HouseSale.h"

HouseSale::HouseSale(string inStreet, string inCity, Customer inLandLord , RealEstateAgent inAgent , Date inListing, int inYear, int inRoom, int inPrice)
		: Property(inStreet, inCity, inLandLord , inAgent , inListing){
	year_of_built=inYear;
	no_of_rooms=inRoom;
	price=inPrice;
}

HouseSale::~HouseSale() {
	// TODO !CodeTemplates.destructorstub.tododesc!
}

int HouseSale::getNoOfRooms() const {
	return no_of_rooms;
}

void HouseSale::setNoOfRooms(int noOfRooms) {
	no_of_rooms = noOfRooms;
}

int HouseSale::getPrice() const {
	return price;
}

void HouseSale::setPrice(int price) {
	this->price = price;
}

int HouseSale::getYearOfBuilt() const {
	return year_of_built;
}

void HouseSale::print() {
	///TODO faire
}

void HouseSale::setYearOfBuilt(int yearOfBuilt) {
	year_of_built = yearOfBuilt;
}
