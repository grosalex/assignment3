/*
 * Customer.cpp
 *
 *  Created on: 22 oct. 2013
 *      Author: William
 */

#include "Customer.h"

Customer::Customer(string inputName, string inputAdress, Date inputBirthdate, string inputSsn)
	:Person(inputName, inputAdress, inputBirthdate)
{
	socialinsurancenumber = inputSsn;
}

Customer::~Customer() {
	// TODO Auto-generated destructor stub
}

void Customer::print() {
	Person::print();
	cout << "\n Social Insurance Number : " << socialinsurancenumber << endl;
}

const string& Customer::getSocialinsurancenumber() const {
	return socialinsurancenumber;
}

void Customer::setSocialinsurancenumber(const string& socialinsurancenumber) {
	this->socialinsurancenumber = socialinsurancenumber;
}
