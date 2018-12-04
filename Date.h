#ifndef DATE_H_
#define DATE_H_


#include <fstream>
#include <iostream>
using namespace std;

class Date{
protected:
	int day, month, year;

public:
	Date();
	Date(string date);
	Date(int day, int year , int month);

	int getDay();
	int getMonth();
	int getYear();

	void printDateInfo(ostream &os);
	void printDate();
};

#endif /* DATE_H_ */
