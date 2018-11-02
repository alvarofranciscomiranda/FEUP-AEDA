#ifndef UNTITLED_PEOPLE_H
#define UNTITLED_PEOPLE_H

#include <iostream>
using namespace std;

class People {

protected:
    string name, address, taxNumber;

public:
    People(string name, string address, string taxNumber);
    string getName() const;
    string getAddress() const;
    string getTaxNumber() const;
    void setName(string name);
    void setAddress(string address);
    void setTaxNumber(string taxNumber);
};

class Employee : public People{

private:
    float salary;
    string pharmacy, post;

public:
    Employee(string name, string address, string taxNumber, float salary, string pharmacy, string post);
    float getSalary() const;
    string getPharmacy() const;
    string getPost() const;
    void setSalary(float salary);
    void setPharmacy(string pharmacy);
    void setPost(string post);
};

class Client : public People{
public:
    Client(string name, string address, string taxNumber);
};

#endif //UNTITLED_PEOPLE_H
