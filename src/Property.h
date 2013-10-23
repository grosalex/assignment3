/*
 * Property.h
 *
 *  Created on: 23 oct. 2013
 *      Author: William
 */

#ifndef PROPERTY_H_
#define PROPERTY_H_

#include "RealEstateAgent.h"
#include "Customer.h"

class Property {
public:
	Property(string inStreet_adress, string inCityName, Customer inLandlord, RealEstateAgent inAgent, Date inListingDate);
	virtual ~Property();
	virtual void print();
	const RealEstateAgent& getAgent() const;
	void setAgent(const RealEstateAgent& agent);
	const string& getCityname() const;
	void setCityname(const string& cityname);
	const Customer& getCustomer() const;
	void setCustomer(const Customer& customer);
	const Customer& getLandlord() const;
	void setLandlord(const Customer& landlord);
	const Date& getListingdate() const;
	void setListingdate(const Date& listingdate);
	const string& getStreetAddress() const;
	void setStreetAddress(const string& streetAddress);

private:
	string street_address;
	string cityname;

	// Customer parameter in the constructor function should be used to initialize landlord.
	Customer landlord;
	RealEstateAgent agent;
	Date listingdate;

	// customer should be initialized to an empty string, � �.
	Customer customer;
};

#endif /* PROPERTY_H_ */
