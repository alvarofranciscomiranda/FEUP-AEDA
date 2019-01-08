#include "Date.h"
#include <sstream>

using namespace std;

Date::Date(){ year = 0; month = 0; day = 0;}

Date::Date(int day, int month, int year): day(day), month(month), year(year){}

Date::Date(string date){
	unsigned long stop; //stop is pos for last ';' found

	//day
	stop = date.find_first_of('/');
	this->day = stoi(date.substr(0,stop));

	//month
	date = date.substr(stop + 1);
	stop = date.find_first_of('/');
	this->month = stoi(date.substr(0,stop));

	//year
	date = date.substr(stop + 1);
	this->year = stoi(date);
}

int Date::getDay() {
	return this->day;
}

int Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}

void Date::printDateInfo(ostream & os){
	os << day << "/" << month << "/" << year << endl;
}

void Date::printDate(){
	cout << this->day << "/"<< this->month << "/" << this->year << endl;
}


