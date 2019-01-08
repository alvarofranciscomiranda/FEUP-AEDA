#ifndef UNTITLED_PEOPLE_H
#define UNTITLED_PEOPLE_H

#include <iostream>
#include <vector>
#include "Sales.h"
using namespace std;

class People {

protected:
    string name, address;
	int taxNumber;

public:
	virtual ~People(){};
    People();
    People(string name, string address, int taxNumber);

    string getName() const;
    string getAddress() const;
    int getTaxNumber() const;

    void setName(string name);
    void setAddress(string address);
    void setTaxNumber(int taxNumber);

	virtual void printSimplifiedInfo(ostream & os) const = 0;
	virtual void displayPerson() const = 0;
};

class Employee : public People{

protected:
    float salary;
    string pharmacy, post;

public:
    ~Employee(){};
    Employee(string name, string address, int taxNumber, float salary, string pharmacy, string post);
	Employee(string employee);
    float getSalary() const;
    string getPharmacy() const;
    string getPost() const;
    void setSalary(float salary);
    void setPharmacy(string pharmacy);
    void setPost(string post);

    void displayPerson() const;
	void printSimplifiedInfo(ostream & os) const;
};

class Client : public People{
protected:
	vector<Sales *> purchases;
	string district;
public:
	static int id;
	int client_number;
	string getDistrict() const;
	void setDistrict(string district);
	int getClient_number() const;
	void setClient_number(int client_number);
	Client(int id,string name, string district, string address, int taxNumber);
	Client(string name, string district, string address, int taxNumber);
    vector<Sales *> getPurchases() const;
    void setPurchases(vector<Sales *> purchases);
	Client(string client);
	void addPurchases(Sales * purchases);
	bool operator<(const Client& c1) const;
	bool operator ==(const Client * c1){
		return name== c1->getName();
	}

	void displayPerson() const;
	void printSimplifiedInfo(ostream & os) const;
};

#endif //UNTITLED_PEOPLE_H
