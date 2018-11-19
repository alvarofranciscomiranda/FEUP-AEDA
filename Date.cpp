#include "Date.h"
#include <sstream>

using namespace std;

Date::Date(){}

Date::Date(int minute, int hour, int day, int month, int year): minutes(minute), hours(hour), day(day), month(month), year(year){}

Date::Date(const Date &t1):
		minutes(t1.minutes),
		hours(t1.hours),
		day(t1.day),
		month(t1.month),
		year(t1.year)
{}

Date::Date(string date){
	stringstream ss;
	char slash;
	char double_point;
	ss << date;
	ss >> this->year >> slash >> this->month >> slash >> this->day >> this->hours >> double_point >> this->minutes;
}

int Date::getMinutes(){
	return this->minutes;
}

int Date::getHours(){
	return this->hours;
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

void Date::printDate(ostream & os){
	os << year << "/" << month << "/" << day << " " << hours << ":" << minutes;
}

ostream & operator<<(ostream & os, Date & d){
	d.printDate(os);
	return os ;
}
