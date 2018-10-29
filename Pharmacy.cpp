//
// Created by Maria João Senra Viana on 29/10/2018.
//

#include "Pharmacy.h"
#include <iomanip>
#include <vector>
#include <fstream>
#include <iostream>

Pharmacy::Pharmacy(string &name, string &address, string &manager):name(name), address(address), manager(manager)
{
}

string Pharmacy::getName()const {
    return name;
}

string Pharmacy::getAddress()const {
    return address;
}

string Pharmacy::getManager()const {
    return manager;
}

vector<string> Pharmacy::getEmployees()const{
    return employees;
}

vector<string> Pharmacy::getClients()const{
    return clients;
}

void Pharmacy::setName(string name){
    this->name = name;
}

void Pharmacy::setAddress(string address){
    this->address = address;
}

void Pharmacy::setManager(string manager){
    this->manager = manager;
}

void Pharmacy::displayPharmacy(){
    cout << "Name: " << " Pharmacy " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Manager: " << manager << endl;
}