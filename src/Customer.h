/*
 * Customer.h
 *
 *  Created on: 22 oct. 2013
 *      Author: William
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "Person.h"

class Customer : public Person {
public:
	Customer(string inputName, string inputAdress, Date inputBirthdate, string inputSsn);
	Customer();
	virtual ~Customer();
	virtual void print();

	const string& getSocialinsurancenumber() const;
	void setSocialinsurancenumber(const string& socialinsurancenumber);

private:
	string socialinsurancenumber;
};

#endif /* CUSTOMER_H_ */
