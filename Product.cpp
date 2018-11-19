#include "Product.h"
#include <iostream>
using namespace std;

Product::Product(){
	name = "";
	code = 0;
	price =  0;
	description = "";
}

Product::Product(string name,int code, int price, string description) :name(name), code(code), price(price), description(description){
}

string Product::getName() const{
    return name;
}

int Product::getCode() const{
    return code;
}

int Product::getPrice() const{
    return price;
}

string Product::getDescription() const{
    return description;
}

void Product::setName(string name){
    this->name = name;
}

void Product::setCode(int code){
	this->code = code;
}

void Product::setPrice(int price){
    this->price = price;
}

void Product::setDescription(string description){
    this->description = description;
}

Medicine::Medicine(string name,int code, int price, string description, bool prescription, bool needed, int discount):Product(name, code, price, description), prescription(prescription), needed(needed), discount(discount){
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
