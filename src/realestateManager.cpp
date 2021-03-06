/*
 * realestateManager.cpp
 *
 *  Created on: 23 oct. 2013
 *      Author: grosalex
 */

#include "realestateManager.h"

realestateManager::realestateManager() {
	int i=0;
	for(i=0;i<max_number_of_agents;i++){
		agentRecordsArray[i]=NULL;
	}
	for(i=0;i<listingsize;i++){
		propertyListingArray[i]=NULL;
	}
	for(i=0;i<archivesize;i++){
		archiveRecordsArray[i]=NULL;
	}
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


	if(property!= NULL) property->setCustomer(*customer);

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
				HouseRental *tmpHouseRental = dynamic_cast<HouseRental*>(propertyListingArray[i]);

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

void realestateManager::controller() {
	int i, index;
	string inputName;
	string inputAdress;
	Date inputBirthdate;
	Date inputEmploymentDate;
	int inputEmploeeId;
	string findByCity;
	string inStreet_adress;
	string inCityName;
	string inputSSN;
	int inputDay, inputMonth, inputYear;
	char choice=' ';
	char propertySort;
	bool validate=false;
	double inputArea;
	int inputPrice;
	int inYear;
	int inRoom;
	int inPrice;

	while(choice!='q'){

		cout << "1 - Add an agent" << endl;
		cout << "2 - Add a property" << endl;
		cout << "3 - Rent or Sold a Property" << endl;
		cout << "4 - Find properties in a city" << endl;
		cout << "5 - Find properties by agent" << endl;
		cout << "6 - Display agents" << endl;
		cout << "7 - Display available properties" << endl;
		cout << "8 - Display sold or rented properties" << endl;
		cout << "q - to quit" << endl;

		cin >> choice;
		switch(choice){
		case '1'://add an agent
			cout << "Enter the agent name : ";
			cin >> inputName;
			cout << "Enter the address : ";
			cin >>inputAdress;
			cout << "Enter his birth date (day, month year) : " << endl;
			cin >> inputDay;
			cin >> inputMonth;
			cin >> inputYear;
			inputBirthdate.setDay(inputDay);
			inputBirthdate.setMonth(inputMonth);
			inputBirthdate.setYear(inputYear);
			cout << "Enter his employment date (day, month year) : " << endl;
			cin >> inputDay;
			cin >> inputMonth;
			cin >> inputYear;
			inputEmploymentDate.setDay(inputDay);
			inputEmploymentDate.setMonth(inputMonth);
			inputEmploymentDate.setYear(inputYear);
			cout << "Enter the employee id : ";
			cin >> inputEmploeeId;
			validate=this->insertAgent(new RealEstateAgent(inputName, inputAdress, inputBirthdate, inputEmploymentDate,inputEmploeeId));
			break;
		case '2'://add a property
			cout << "For a LandSale enter L, for a house sale enter H and for a house rental enter h :";
			cin >> propertySort;
			for(i=0;i<this->listingsize;i++){
				if(this->propertyListingArray[i]==NULL){
					for(i=0;i<max_number_of_agents;i++){
						if(this->agentRecordsArray[i]!=NULL)
						{
							cout <<"index"<< i << endl;
							this->agentRecordsArray[i]->print();
							cout << endl;
						}
					}
					do {
						cout << "Enter the agent's index you want : ";
						cin >> index;
					}while(this->agentRecordsArray[index]==NULL);

					cout << "Enter the address : ";
					cin >> inStreet_adress;
					cout << "Enter the city name : ";
					cin >> inCityName;
					cout << "Enter the listing date (day, month year) : " << endl;
					cin >> inputDay;
					cin >> inputMonth;
					cin >> inputYear;
					Date inputDate(inputDay,inputMonth,inputYear);
					cout << "Enter the landlord's name : ";
					cin >>inputName;
					cout << "enter the landlord's address : ";
					cin >> inputAdress;
					cout << "Enter his SSN : ";
					cin >> inputSSN;
					cout << "Enter his birth date (day, month year) : " << endl;
					cin >> inputDay;
					cin >> inputMonth;
					cin >> inputYear;
					inputBirthdate.setDay(inputDay);
					inputBirthdate.setMonth(inputMonth);
					inputBirthdate.setYear(inputYear);
					Customer inputCustomer(inputName,inputAdress, inputBirthdate,inputSSN);
					switch(propertySort){
					case 'L':
						cout << "Enter the area : ";
						cin >> inputArea;
						cout << "Enter the price : ";
						cin >> inputPrice;
						//LandSale * inputLandSale = new LandSale(inStreet_adress, inCityName, inputCustomer, *(this->agentRecordsArray[index]),inputDate,inputArea,inputPrice);
						this->insertProperty(new LandSale(inStreet_adress, inCityName, inputCustomer, *(this->agentRecordsArray[index]),inputDate,inputArea,inputPrice));
						break;
					case 'H':
						cout << "Enter the year of building : ";
						cin >> inYear;
						cout << "Enter the number of room : ";
						cin >> inRoom;
						cout << "Enter the price : ";
						cin >> inPrice;
						//Property * inputProperty = new HouseSale(inStreet_adress, inCityName, new Customer(inputName,inputAdress, inputBirthdate,inputSSN),this->agentRecordsArray[index], new Date(inputDay,inputMonth,inputYear), inYear,inRoom,inPrice);
						this->insertProperty(new HouseSale(inStreet_adress, inCityName, inputCustomer,*(this->agentRecordsArray[index]),inputDate, inYear,inRoom,inPrice));
						break;
					case 'h':
						cout << "Enter the year of building : ";
						cin >> inYear;
						cout << "Enter the number of room : ";
						cin >> inRoom;
						cout << "Enter the monthly price : ";
						cin >> inPrice;
						//Property * inputProperty = new HouseRental(inStreet_adress, inCityName, new Customer(inputName,inputAdress, inputBirthdate,inputSSN),this->agentRecordsArray[index], new Date(inputDay,inputMonth,inputYear), inYear,inRoom,inPrice);
						this->insertProperty(new HouseRental(inStreet_adress, inCityName,inputCustomer,*(this->agentRecordsArray[index]),inputDate, inYear,inRoom,inPrice));
						break;
					}

				}
				i = listingsize;
			}
			break;
		case '3'://rent or sold a property

			cout << "Enter the customer's name : ";
			cin >>inputName;
			cout << "enter the customer's address : ";
			cin >> inputAdress;
			cout << "Enter his SSN : ";
			cin >> inputSSN;
			cout << "Enter his birth date (firts day, month year) : " << endl;
			cin >> inputDay;
			cin >> inputMonth;
			cin >> inputYear;
			inputBirthdate.setDay(inputDay);
			inputBirthdate.setMonth(inputMonth);
			inputBirthdate.setYear(inputYear);
			//Customer * buyer=new Customer(inputName,inputAdress, inputBirthdate,inputSSN);
			for(i=0;i<this->listingsize;i++){
				if(this->propertyListingArray[i]!=NULL)
				{
					cout <<"index "<< i << endl;
					this->propertyListingArray[i]->print();
					cout << endl;
				}
			}

			do {
				cout << "Which property you want (enter index) : ";
				cin >> i;
			}while(this->propertyListingArray[i]==NULL);
			this->propertysoldrented(this->propertyListingArray[i],new Customer(inputName,inputAdress, inputBirthdate,inputSSN));
			break;
		case '4'://find a property in a city
			cout << "Enter the city name :";
			cin >> findByCity;
			this->findPropertiesCity(findByCity);
			break;
		case '5'://find property by agent
			for(i=0;i<max_number_of_agents;i++){
				if(this->agentRecordsArray[i]!=NULL)
				{
					cout <<"index "<< i << endl;
					this->agentRecordsArray[i]->print();
					cout << endl;
				}
			}
			do{
				cout << "Enter the agent's index you want : ";
				cin >> i;
			}while(this->agentRecordsArray[i]==NULL);
			this->findPropertiesAgent(this->agentRecordsArray[i]);
			break;

		case '6':
			for(i=0;i<max_number_of_agents;i++){
				if(this->agentRecordsArray[i]!=NULL)
				{
					cout <<"Agent "<< i << endl;
					this->agentRecordsArray[i]->print();
					cout << endl << endl;
				}
			}
			break;

		case '7':
			for(i=0;i<this->listingsize;i++){
				if(this->propertyListingArray[i]!=NULL)
				{
					cout <<"Property "<< i << endl;
					this->propertyListingArray[i]->print();
					cout << endl << endl;
				}
			}
			break;

		case '8':
			for(i=0;i<this->archivesize;i++){
				if(this->archiveRecordsArray[i]!=NULL)
				{
					cout << "Property " << i << endl;
					this->archiveRecordsArray[i]->print();
					cout << endl << endl;
				}
			}
			break;
		case 'q'://quit
			break;
		default:
			cout << "Please enter a correct choice : " << endl;
			cout << "1 - Add an agent" << endl;
			cout << "2 - Add a property" << endl;
			cout << "3 - Rent or Sold a Property" << endl;
			cout << "4 - Find properties in a city" << endl;
			cout << "5 - Find properties by agent" << endl;
			cout << "q - to quit" << endl;

			cin >> choice;
			break;
		}
	}
}
