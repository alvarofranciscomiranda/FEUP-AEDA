#ifndef DATE_H_
#define DATE_H_


#include <fstream>
#include <iostream>
using namespace std;

class Date{
protected:
	int minutes, hours, day, month, year;

public:
	Date();
	Date(const Date &date);
	Date(string date);
	Date(int minute, int hour, int day, int year , int month);

	int getMinutes();
	int getHours();
	int getDay();
	int getMonth();
	int getYear();
	void printDate(ostream &os);

};

#endif /* DATE_H_ */
