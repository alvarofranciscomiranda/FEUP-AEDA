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
    People();
    People(string name, string address, int taxNumber);
    string getName() const;
    string getAddress() const;
    int getTaxNumber() const;
    void setName(string name);
    void setAddress(string address);
    void setTaxNumber(int taxNumber);
};

class Employee : public People{

protected:
    float salary;
    string pharmacy, post;

public:
    Employee(string name, string address, int taxNumber, float salary, string pharmacy, string post);
	Employee(string employee);
    float getSalary() const;
    string getPharmacy() const;
    string getPost() const;
    void setSalary(float salary);
    void setPharmacy(string pharmacy);
    void setPost(string post);
	void displayEmployee();
	void writeEmployee(ofstream & file) const;
};

class Client : public People{
protected:
	vector<Sales> purchases;
public:
	static int id;
	int client_number;
	int getClient_number() const;
	void setClient_number(int client_number);
	Client(int id,string name, string address, int taxNumber);
	Client(string name, string address, int taxNumber);
    vector<Sales> getPurchases() const;
    void setPurchases(vector<Sales> purchases);
	Client(string client);
	void displayClient();
	void writeClient(ofstream & file) const;
};


#endif //UNTITLED_PEOPLE_H
