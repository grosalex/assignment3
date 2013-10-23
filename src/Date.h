/*
 * Date.h
 *
 *  Created on: 16 oct. 2013
 *      Author: William
 */

#ifndef DATE_H_
#define DATE_H_

#include <iostream>
using namespace std;

class Date {
public:
	Date();
	Date(int inputDay, int inputMonth, int inputYear);
	void print();

	int getDay() const;
	void setDay(int day);
	int getMonth() const;
	void setMonth(int month);
	int getYear() const;
	void setYear(int year);

private:
	int month;
	int day;
	int year;
};

#endif /* DATE_H_ */
