/*
 * Property.cpp
 *
 *  Created on: 23 oct. 2013
 *      Author: William
 */

#include "Property.h"

Property::Property(string inStreet_adress, string inCityName, Customer inLandlord, RealEstateAgent inAgent, Date inListingDate) {
	street_address=inStreet_adress;
	cityname=inCityName;
	landlord=inLandlord;
	agent=inAgent;
	listingdate=inListingDate;
	///TODO last customer
}

Property::~Property() {
	// TODO Auto-generated destructor stub
}

void Property::print() {
	///TODO print
}

const RealEstateAgent& Property::getAgent() const {
	return agent;
}

void Property::setAgent(const RealEstateAgent& agent) {
	this->agent = agent;
}

const string& Property::getCityname() const {
	return cityname;
}

void Property::setCityname(const string& cityname) {
	this->cityname = cityname;
}

const Customer& Property::getCustomer() const {
	return customer;
}

void Property::setCustomer(const Customer& customer) {
	this->customer = customer;
}

const Customer& Property::getLandlord() const {
	return landlord;
}

void Property::setLandlord(const Customer& landlord) {
	this->landlord = landlord;
}

const Date& Property::getListingdate() const {
	return listingdate;
}

void Property::setListingdate(const Date& listingdate) {
	this->listingdate = listingdate;
}

const string& Property::getStreetAddress() const {
	return street_address;
}

void Property::setStreetAddress(const string& streetAddress) {
	street_address = streetAddress;
}
