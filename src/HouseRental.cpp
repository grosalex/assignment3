/*
 * HouseRental.cpp
 *
 *  Created on: 23 oct. 2013
 *      Author: William
 */

#include "HouseRental.h"

HouseRental::HouseRental(string inStreet_adress, string inCityName, Customer inLandlord, RealEstateAgent inAgent, Date inListingDate, int inYearofBuilt, int inNoofRooms, int inMonthlyRental)
	:Property(inStreet_adress, inCityName, inLandlord, inAgent, inListingDate)
{
	year_of_built = inYearofBuilt;
	no_of_rooms = inNoofRooms;
	monthly_rental = inMonthlyRental;

}

HouseRental::~HouseRental() {

}

void HouseRental::print() {
	Property::print();
	cout << "\nYear of built : " << year_of_built << endl;
	cout << "Number of rooms : " << no_of_rooms << endl;
	cout << "Monthly rental  " << monthly_rental;
}
