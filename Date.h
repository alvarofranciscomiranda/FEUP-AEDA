#ifndef DATE_H_
#define DATE_H_


#include <fstream>
#include <iostream>
using namespace std;

class Date{
protected:
	int day, month, year;

public:
	/**
	 * Constructor of class Date.
	*/
	Date();

	/**
	* Constructor of class Date.
	*/
	Date(string date);

	/**
	* Constructor of class Date.
	*/
	Date(int day, int year , int month);

	/**
	* @return day
	*/
	int getDay();

	/**
	 * @return month
	*/
	int getMonth();

	/**
	* @return year
	*/
	int getYear();

	/**
	* @return displays date
	*/
	void printDateInfo(ostream &os);

	/**
	* @return displays date
	*/
	void printDate();
};

#endif /* DATE_H_ */
