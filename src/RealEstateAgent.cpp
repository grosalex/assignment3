/*
 * RealEstateAgent.cpp
 *
 *  Created on: 22 oct. 2013
 *      Author: William
 */

#include "RealEstateAgent.h"

RealEstateAgent::RealEstateAgent(string inputName, string inputAdress, Date inputBirthdate, Date inputEmploymentDate, int inputEmploeeId)
	:Person(inputName, inputAdress, inputBirthdate)
{
	employmentdate = inputEmploymentDate;
	employeeid = inputEmploeeId;
}

RealEstateAgent::RealEstateAgent()
	:Person("", "", Date())
{
	employeeid = 0;
}

RealEstateAgent::~RealEstateAgent() {
	// TODO Auto-generated destructor stub
}

void RealEstateAgent::print() {
	Person::print();
	cout << "\n Employee ID : " << employeeid << endl;
	cout << "Employment Date : ";
	employmentdate.print();
}

int RealEstateAgent::getEmployeeid() const {
	return employeeid;
}

void RealEstateAgent::setEmployeeid(int employeeid) {
	this->employeeid = employeeid;
}

const Date& RealEstateAgent::getEmploymentdate() const {
	return employmentdate;
}

void RealEstateAgent::setEmploymentdate(const Date& employmentdate) {
	this->employmentdate = employmentdate;
}
