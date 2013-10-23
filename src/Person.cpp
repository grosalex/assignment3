/*
 * Person.cpp
 *
 *  Created on: 16 oct. 2013
 *      Author: William
 */

#include "Person.h"

Person::Person(string inputName, string inputAdress, Date inputBirthdate) {
	name = inputName;
	adress = inputAdress;
	birthdate = inputBirthdate;

}

Person::~Person() {
	// TODO Auto-generated destructor stub
}

void Person::print() {
	cout << "Name : " << name << endl;
	cout << "Adress : " << adress << endl;
	cout << "Birth Date : ";
	birthdate.print();
}

const string& Person::getAdress() const {
	return adress;
}

void Person::setAdress(const string& adress) {
	this->adress = adress;
}

const Date& Person::getBirthdate() const {
	return birthdate;
}

void Person::setBirthdate(const Date& birthdate) {
	this->birthdate = birthdate;
}

const string& Person::getName() const {
	return name;
}

void Person::setName(const string& name) {
	this->name = name;
}
