#include "People.h"
#include <iostream>
using namespace std;


int Client::id=1;

People::People(){
	this->name = "";
	this->address = "";
	this->taxNumber = 0;
}

People::People(string name, string address, int taxNumber):name(name), address(address), taxNumber(taxNumber){
}

string People::getName() const{
    return name;
}

string People::getAddress() const{
    return address;
}

int People::getTaxNumber() const{
    return taxNumber;
}

void People::setName(string name){
    this->name = name;
}

void People::setAddress(string address){
    this->address = address;
}

void People::setTaxNumber(int taxNumber){
    this->taxNumber = taxNumber;
}

Employee::Employee(string name, string address, int taxNumber, float salary, string pharmacy, string post):People(name, address, taxNumber){
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

Employee::Employee(string employee){
    unsigned long stop; //stop is pos for last ';' found

    // name
    stop = employee.find_first_of(';');
    this->name = employee.substr(0,stop);

    // address
    employee = employee.substr(stop + 1);
    stop = employee.find_first_of(';');
    this->address = employee.substr(0,stop);

    //taxNumber
    employee = employee.substr(stop +1);
    stop = employee.find_first_of(';');
    this->taxNumber = stoi(employee.substr(0, stop));

    //salary
    employee = employee.substr(stop + 1);
    stop = employee.find_first_of(';');
    this->salary = stof(employee.substr(0, stop));

    //pharmacy
    employee = employee.substr(stop + 1);
    stop = employee.find_first_of(';');
    this->pharmacy = employee.substr(0, stop);

    //post
    employee = employee.substr(stop + 1);
    this->post = employee.substr(0);
}

void Employee::displayPerson() const{
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Tax Number: " << taxNumber << endl;
    cout << "Pharmacy: " << pharmacy << endl;
    cout << "Salary: " << salary << endl;
    cout << "Post: " << post << endl;
    cout << endl << endl;
}

void Employee::printSimplifiedInfo(ostream & os) const{
	os << name << ";" << address << ";" << taxNumber << ";" << salary << ";" << pharmacy << ";" << post;
}

Client::Client(string name, string address, int taxNumber): People(name, address, taxNumber){

    id++;
    client_number=id;

}

Client::Client(int id, string name, string address, int taxNumber):People(name, address, taxNumber){
    client_number=id;
}

vector<Sales*> Client::getPurchases() const{
    return purchases;
}

void Client::setPurchases(vector<Sales*> purchases){
    this->purchases = purchases;
}

Client::Client(string client){
    unsigned long last;
    unsigned long stop; //stop is pos for last ';' found
    string purchases;

    //id
    stop = client.find_first_of(';');
    this->client_number = stoi(client.substr(0,stop));

    // name
    client = client.substr(stop+1);
    stop = client.find_first_of(';');
    this->name = client.substr(0,stop);

    // address
    client = client.substr(stop+1);
    stop = client.find_first_of(';');
    this->address = client.substr(0,stop);

    //taxNumber
    client = client.substr(stop +1);
    stop = client.find_first_of(';');
    this->taxNumber = stoi(client.substr(0, stop));
}

void Client::displayPerson() const{
    cout << "Id: " << client_number<< endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Tax Number: " << taxNumber << endl;
    cout << "Purchases: ";
    for(unsigned int i = 0; i < this->purchases.size(); i++){
    	this->purchases.at(i)->printSalesInfo();
    }
    cout << endl;
}


void Client::printSimplifiedInfo(ostream & os) const{
	os << client_number << ";" << name << ";" << address << ";" << taxNumber << ";";
}

int Client::getClient_number() const {
    return client_number;
}

void Client::setClient_number(int client_number) {
    Client::client_number = client_number;
}

void Client::addPurchases(Sales * purchases){
	this->purchases.push_back(purchases);
}
