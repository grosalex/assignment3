/*
 * Person.h
 *
 *  Created on: 16 oct. 2013
 *      Author: William
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include "Date.h"

class Person {
public:
	Person(string inputName, string inputAdress, Date inputBirthdate);
	virtual ~Person();
	virtual void print();

	const string& getAdress() const;
	void setAdress(const string& adress);
	const Date& getBirthdate() const;
	void setBirthdate(const Date& birthdate);
	const string& getName() const;
	void setName(const string& name);

private:
	string name;
	string adress;
	Date birthdate;
};

#endif /* PERSON_H_ */
