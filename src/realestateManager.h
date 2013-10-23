/*
 * realestateManager.h
 *
 *  Created on: 23 oct. 2013
 *      Author: grosalex
 */

#ifndef REALESTATEMANAGER_H_
#define REALESTATEMANAGER_H_
#include <string>
class realestateManager {
public:
	realestateManager();
	virtual ~realestateManager();

	bool insertAgent(RealEstateAgent *);//insert agent function adds a new agent to the agent Records array
	bool insertProperty(Property *);// insertProperty function adds a property to the first available location in the propertyListingArray
	bool propertysoldrented(Property *, Customer *);
	// When a property is sold/rented, the customer will be stored in the Property object and
	// the object itself will be transferred from propertyListingArray to the
	// archiveRecordsArray and null value will be inserted at its location at the
	// propertyListingArray.
	// findPropertiesCity function determines all the properties for sale in a given city and
	// prints them. String parameter of the function corresponds to a city name. You would
	// need to use dynamic_cast to determine the class of the objects stored in the
	// propertyListingArray (See section 13.8 in the textbook)
	void findPropertiesCity(string);
	// findPropertiesAgent function determines all the listings of an agent and prints them.
	void findPropertiesAgent(RealEstateAgent *);

private:
	static const int max_number_of_agents = 30;
	static const int listingsize = 1000;
	static const int archivesize = 2000;

	// The followings are array of pointers, all the arrays should be initialized to null values.
	RealEstateAgent * agentRecordsArray[max_number_of_agents];
	Property * propertyListingArray[listingsize];
	Property * archiveRecordsArray[archivesize];

};

#endif /* REALESTATEMANAGER_H_ */
