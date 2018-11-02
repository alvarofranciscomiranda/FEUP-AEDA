#include "People.h"
#include <iostream>
using namespace std;

People::People(string name, string address, string taxNumber):name(name), address(address), taxNumber(taxNumber){
}

string People::getName() const{
    return name;
}

string People::getAddress() const{
    return address;
}

string People::getTaxNumber() const{
    return taxNumber;
}

void People::setName(string name){
    this->name = name;
}

void People::setAddress(string address){
    this->address = address;
}

void People::setTaxNumber(string taxNumber){
    this->taxNumber = taxNumber;
}

Employee::Employee(string name, string address, string taxNumber, float salary, string pharmacy, string post):People(name, address, taxNumber){
    this->salary = salary;
    this->pharmacy = pharmacy;
    this->post = post;
}

float Employee::getSalary() const{
    return salary;
}

string Employee::getPharmacy() const{
    return pharmacy;
}

string Employee::getPost() const{
    return post;
}

void Employee::setSalary(float salary){
    this->salary = salary;
}

void Employee::setPharmacy(string pharmacy){
    this->pharmacy = pharmacy;
}

void Employee::setPost(string post){
    this->post = post;
}

Client::Client(string name, string address, string taxNumber):People(name, address, taxNumber){
}