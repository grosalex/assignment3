/*
 * RealEstateAgent.h
 *
 *  Created on: 22 oct. 2013
 *      Author: William
 */

#ifndef REALESTATEAGENT_H_
#define REALESTATEAGENT_H_

#include "Person.h"

class RealEstateAgent : public Person {
public:
	RealEstateAgent(string inputName, string inputAdress, Date inputBirthdate, Date inputEmploymentDate, int inputEmploeeId);
	RealEstateAgent();
	virtual ~RealEstateAgent();

	int getEmployeeid() const;
	void setEmployeeid(int employeeid);
	const Date& getEmploymentdate() const;
	void setEmploymentdate(const Date& employmentdate);

	virtual void print();

private:
	Date employmentdate;
	int employeeid;
};

#endif /* REALESTATEAGENT_H_ */
