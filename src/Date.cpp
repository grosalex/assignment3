/*
 * Date.cpp
 *
 *  Created on: 16 oct. 2013
 *      Author: William
 */

#include "Date.h"

Date::Date() {
	day = month = year = 0;
}

Date::Date(int inputDay, int inputMonth, int inputYear) {
	day = inputDay;
	month = inputMonth;
	year = inputYear;
}



void Date::print() {
	cout << day << "/" << month << "/" << year;
}

int Date::getDay() const {
	return day;
}

void Date::setDay(int day) {
	this->day = day;
}

int Date::getMonth() const {
	return month;
}

void Date::setMonth(int month) {
	this->month = month;
}

int Date::getYear() const {
	return year;
}

void Date::setYear(int year) {
	this->year = year;
}
