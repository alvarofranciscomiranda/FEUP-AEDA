#include "Pharmacy.h"
#include <iomanip>
#include <vector>
#include <fstream>
#include <iostream>

Pharmacy::Pharmacy(string name, string address, string manager):name(name), address(address), manager(manager)
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

vector<Employee*> Pharmacy::getEmployees()const{
    return employees;
}

vector<Client*> Pharmacy::getClients()const{
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

void Pharmacy::setEmployees(vector<Employee*> &employees){
    this->employees = employees;
}

void Pharmacy::setClients(vector<Client*> &clients){
    this->clients = clients;
}

void Pharmacy::addEmployee(Employee *employee){
    this->employees.push_back(employee);
}

void Pharmacy::addClient(Client *client){
    this->clients.push_back(client);
}

void Pharmacy::displayPharmacy(){
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Manager: " << manager << endl;
    cout << "Employees: ";
    for(unsigned int i = 0; i < employees.size(); i++){
        if(i == employees.size()-1) {
            cout << employees[i]->getName();
        } else {
            cout << employees[i]->getName() << ", ";
        }
    }
    cout << endl;

    cout << "Clients: ";
    for(unsigned int i = 0; i < clients.size(); i++){
        if(i == clients.size()-1) {
            cout << clients[i]->getName();
        } else {
            cout << clients[i]->getName() << ", ";
        }
    }
    cout << endl << endl;
}

Pharmacy::Pharmacy(string pharmacy){
    unsigned long last;
    unsigned long stop; //stop is pos for last ';' found
    string employees, client;

    // name
    stop = pharmacy.find_first_of(';');
    this->name = pharmacy.substr(0,stop);

    // address
    pharmacy = pharmacy.substr(stop+2);
    stop = pharmacy.find_first_of(';');
    this->address = pharmacy.substr(0,stop);

    //manager
    pharmacy = pharmacy.substr(stop +2);
    stop = pharmacy.find_first_of(';');
    this->manager = pharmacy.substr(0, stop);

    //employees
    pharmacy = pharmacy.substr(stop+2);
    last = pharmacy.find(';');
    employees = pharmacy.substr(0,last);
    unsigned long st;

    while(stop!=string::npos && !employees.empty()){
        st = employees.find_first_of(',');
        this->employees.push_back(new Employee(employees.substr(0,st),"", 0, 0, this->name, ""));
        if(st==string::npos)
            break;
        employees = employees.substr(st+2);
        stop = st;
    }

    //clients
    pharmacy = pharmacy.substr(last+2);
    last = pharmacy.find(';');
    client = pharmacy.substr(0,last);

    while(stop!=string::npos && !client.empty()){
        st = client.find_first_of(',');
        string temp=client.substr(0,st);
        this->clients.push_back(new Client(temp,"", 0));
        if(st==string::npos)
            break;
        client = client.substr(st+2);
        stop = st;
    }

}

void Pharmacy::writePharmacy(ofstream & file) const{
    file << this->getName() << "; ";
    file << this->getAddress() << "; ";
    file << this->getManager() << "; ";

    //write employees

    if (!this->getEmployees().empty()) {
        for (unsigned int i = 0; i < this->getEmployees().size(); i++) {
            if(i == getEmployees().size() -1)
                file << this->getEmployees()[i]->getName() << "; ";
            else
                file << this->getEmployees()[i]->getName() << ", ";
        }
    }

    //write clients
    if (!this->getClients().empty()) {
        for (unsigned int i=0; i < this->getClients().size(); i++) {
            if(i == this->getClients().size() -1)
                file << this->getClients()[i]->getName() << "; ";
            else
                file << this->getClients()[i]->getName() << ", ";
        }
    }


}
