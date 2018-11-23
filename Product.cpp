#include "Product.h"
#include <iostream>
using namespace std;

Product::Product(){
	name = "";
	code = "";
	price =  0;
	description = "";
}

Product::Product(string name,string code, float price, string description) :name(name), code(code), price(price), description(description){
}

string Product::getName() const{
    return name;
}

string Product::getCode() const{
    return code;
}

float Product::getPrice() const{
    return price;
}

string Product::getDescription() const{
    return description;
}

void Product::setName(string name){
    this->name = name;
}

void Product::setCode(string code){
	this->code = code;
}

void Product::setPrice(float price){
    this->price = price;
}

void Product::setDescription(string description){
    this->description = description;
}

void Product::displayProduct(){
    cout << "Name: " << name << endl;
    cout << "Code: " << code << endl;
    cout << "Price: " << price << endl;
    cout << "Description: " << description << endl;
    cout << endl << endl;
}

Product::Product(string product){
    unsigned long stop; //stop is pos for last ';' found

    //name
    stop = product.find_first_of(';');
    this->name = product.substr(0,stop);

    //code
    product = product.substr(stop+2);
    stop = product.find_first_of(';');
    this->code = product.substr(0,stop);

    //price
    product = product.substr(stop +2);
    stop = product.find_first_of(';');
    this->price = stof(product.substr(0, stop));

    //description
    product = product.substr(stop +2);
    stop = product.find_first_of(';');
    this->description = product.substr(0, stop);

}

void Product::writeProduct(ofstream & file) const{
/*
    file << name << "; ";
    file << code << "; ";
    file << price << "; ";
    file << description; */
}


Medicine::Medicine(string name,string code, float price, string description, bool prescription, bool needed, int discount):Product(name, code, price, description), prescription(prescription), needed(needed), discount(discount){
}
bool Medicine::getPrescription() const{
    return prescription;
}

bool Medicine::getNeeded() const{
    return needed;
}

int Medicine::getDiscount() const{
    return discount;
}

void Medicine::setPrescription(bool prescription){
    this->prescription = prescription;
}

void Medicine::setNeeded(bool needed){
	this->needed = needed;
}

void Medicine::setDiscount(int discount){
    this->discount = discount;
}
