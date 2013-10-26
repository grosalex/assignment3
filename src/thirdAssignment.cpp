/*
 ============================================================================
 Name        : thirdAssignment.cpp
 Author      : grosalex
 Version     :
 Copyright   : do what you want with it
 Description : Hello World in C++,
 ============================================================================
 */

#include <iostream>
#include "Date.h"
#include "Date.cpp"
#include "RealEstateAgent.h"
#include "RealEstateAgent.cpp"
#include "HouseRental.h"
#include "HouseSale.h"
#include "Property.h"
#include "LandSale.h"
using namespace std;
#define maxPropertyNumber 20
#define maxAgentNumber 20
int main(void) {
	int i=0;
	char choice=' ';
	char propertySort=' ';
	string cityToFind;
	RealEstateAgent ** agentArray= new RealEstateAgent* [maxAgentNumber];//declaring the agent array
	Property ** propertyArray = new Property* [maxPropertyNumber];//declaring the property array
	for(i=0;i<maxAgentNumber;i++){//setting the array of agent to null pointer
		agentArray[i]=NULL;
	}
	for(i=0;i<maxPropertyNumber;i++){//setting the array of property to null pointer
		propertyArray[i]=NULL;
	}
	cout << "This is the third Assignment" << endl; /* prints This is the third Assignment */

	cout << "1 - Add an agent" << endl;
	cout << "2 - Add a property" << endl;
	cout << "3 - Rent or Sold a Property" << endl;
	cout << "4 - Find properties in a city" << endl;
	cout << "5 - Find properties by agent" << endl;
	cout << "q - to quit" << endl;

	cin >> choice;
	///T'as le menu, d�sormais je te souhaite bon courage, ou encore, glhf comme on dit chez nous.
	while(choice!='q'){
			switch(choice){
			case '1'://add an agent
				for(i=0;i<maxAgentNumber;i++){
					if(agentArray[i]==NULL){
						agentArray[i]=new RealEstateAgent;///TODO set the parameter
						i=maxAgentNumber;
					}
				}
				break;
			case '2'://add a property
				cout << "For a LandSale enter L, for a house sale enter H and for a house rental enter h :";
				do{
					cin >> propertySort;
				}while(propertySort!='L' || propertySort!='H' || propertySort!='h');
				for(i=0;i<maxPropertyNumber;i++){
					 if(propertyArray[i]==NULL){
						 switch(propertySort){///TODO set the parameter
						 case 'L':
							 propertyArray[i]=new LandSale();
							 break;
						 case 'H':
							 propertyArray[i]=new HouseRental;
							 break;
						 case 'h':
							 propertyArray[i]=new HouseSale;
							 break;
						 }
						 i=maxPropertyNumber;
					 }
				}
				break;
			case '3'://rent or sold a property
				break;
			case '4'://find a property in a city

				break;
			case '5'://find property by agent
				break;
			case 'q'://quit
				return 0;
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

	return 0;
}
