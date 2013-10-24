/*
 * realestateManager.cpp
 *
 *  Created on: 23 oct. 2013
 *      Author: grosalex
 */

#include "realestateManager.h"

realestateManager::realestateManager() {

	// TODO Stub du constructeur généré automatiquement

}

realestateManager::~realestateManager() {
	delete [] agentRecordsArray;
	delete [] propertyListingArray;
	delete [] archiveRecordsArray;
}

bool realestateManager::insertAgent(RealEstateAgent *agent) {
	bool agent_inserted = false;

	for(int i=0; i<max_number_of_agents; i++)
	{
		if(agentRecordsArray[i] == NULL)
		{
			agentRecordsArray[i] = agent;
			i = max_number_of_agents;
			agent_inserted = true;
		}
	}

	if(agent_inserted) cout << "Agent inserted successfully." << endl;
	else cout << "Agent was not inserted in the array." << endl;

	return agent_inserted;
}

bool realestateManager::insertProperty(Property* property) {
	bool property_inserted = false;

	for(int i=0; i<listingsize; i++)
	{
		if(propertyListingArray[i] == NULL)
		{
			propertyListingArray[i] = property;
			i = listingsize;
			property_inserted = true;
		}
	}

	if(property_inserted) cout << "Property inserted successfully." << endl;
	else cout << "Property was not inserted in the array." << endl;

	return property_inserted;
}

bool realestateManager::propertysoldrented(Property* property, Customer* customer) {
	bool propertysoldrented = false;
	bool propertyfound = false;


	property->setCustomer(*customer);

	//Deleting the Property in propertylistingarray
	for(int i=0; i<listingsize;i++)
	{
		if(propertyListingArray[i] != NULL)
			if(propertyListingArray[i]->getStreetAddress() == property->getStreetAddress())
			{
				propertyListingArray[i] = NULL;
				propertyfound = true;
				///TODO delete ? Not asked in pdf.
			}
	}

	if(propertyfound) cout << "Property found in property array, transfering property into ArchiveRecordsArray..." << endl;
	else cout << "Property not found in property array." << endl;

	//Transfering it into archiverecordsarray
	if(propertyfound)
		for(int i=0; i<archivesize;i++)
		{
			if(archiveRecordsArray[i] == NULL)
			{
				archiveRecordsArray[i] = property;
				i = archivesize;
				propertysoldrented = true;
			}
		}

	if(propertysoldrented) cout << "Property successfully rented." << endl;
	else cout << "Property wasn't rented." << endl;

	return propertysoldrented;
}

void realestateManager::findPropertiesCity(string city) {

	for(int i=0; i<listingsize;i++)
	{
		if(propertyListingArray[i] != NULL)
			if(propertyListingArray[i]->getCityname() == city)
			{
				HouseRental *tmpHouseRental = dynamic_cast <HouseRental*> (propertyListingArray[i]);
				if(tmpHouseRental != 0) tmpHouseRental->print();

				HouseSale *tmpHouseSale = dynamic_cast <HouseSale*> (propertyListingArray[i]);
				if(tmpHouseSale != 0) tmpHouseSale->print();

				LandSale *tmpLandSale = dynamic_cast <LandSale*> (propertyListingArray[i]);
				if(tmpLandSale != 0) tmpLandSale->print();
			}
	}
}

void realestateManager::findPropertiesAgent(RealEstateAgent* agent) {

	for(int i=0; i<listingsize;i++)
		{
			if(propertyListingArray[i] != NULL)
				if(propertyListingArray[i]->getAgent().getEmployeeid() == agent->getEmployeeid())
				{
					HouseRental *tmpHouseRental = dynamic_cast <HouseRental*> (propertyListingArray[i]);
					if(tmpHouseRental != 0) tmpHouseRental->print();

					HouseSale *tmpHouseSale = dynamic_cast <HouseSale*> (propertyListingArray[i]);
					if(tmpHouseSale != 0) tmpHouseSale->print();

					LandSale *tmpLandSale = dynamic_cast <LandSale*> (propertyListingArray[i]);
					if(tmpLandSale != 0) tmpLandSale->print();
				}
		}
}
