#include "Product.h"
#include <iostream>

using namespace std;

Product::~Product(){
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

float Product::getStock() const{
    return stock;
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

void Product::setStock(float stock){
    this->stock = stock;
}

void Product::setDescription(string description){
    this->description = description;
}

bool Product::operator  ==(const Product & c) const{
	return (this->name == c.name && this->code == c.code && this->price == c.price);
}

Medicine::Medicine(string name, float stock, string code, float price, string description, bool prescription, bool needed, int discount)
:prescription(prescription), needed(needed), discount(discount)
{
	this->name = name;
	this->stock = stock;
	this->code = code;
	this->price = price;
	this->description = description;
}

Medicine::Medicine(string product){
	unsigned long stop; //stop is pos for last ';' found

	//name
	stop = product.find_first_of('/');
	this->name = product.substr(0,stop);

	//stock
	product = product.substr(stop +1);
	stop = product.find_first_of('/');
	this->stock = stof(product.substr(0, stop));

	//code
	product = product.substr(stop+1);
	stop = product.find_first_of('/');
	this->code = product.substr(0,stop);

	//price
	product = product.substr(stop +1);
	stop = product.find_first_of('/');
	this->price = stof(product.substr(0, stop));

	//description
	product = product.substr(stop + 1);
	stop = product.find_first_of('/');
	this->description = product.substr(0,stop);

	//prescription
    product = product.substr(stop + 1);
    stop = product.find_first_of('/');
    if(product.substr(0, stop) == "1")
    	this->prescription = true;
    else if(product.substr(0, stop) == "0")
        this->prescription = false;

    //needed
    product = product.substr(stop + 1);
    stop = product.find_first_of('/');
    if(product.substr(0, stop) == "1")
       this->needed = true;
    else if(product.substr(0, stop) == "0")
    	this->needed = false;

    //price
    product = product.substr(stop + 1);
    this->discount = stoi(product);
}


 Medicine::~Medicine(){

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

string Medicine::getTypeProduct() const{
	return "medicine";
}

float Medicine::getTotalPrice() const{
	if(prescription)
		return price - (price*discount/100);

	return price;
}

void Medicine::printProductInfo() const{

    cout << "Name: " << name << endl;
    cout << "Stock: " << stock << endl;
    cout << "Code: " << code << endl;
    cout << "Price: " << price << endl;
    cout << "Description: " << description << endl;
    cout << "Can be prescripted: " << prescription << endl;
    cout << "Prescription obligatory: " << needed << endl;
    cout << "Discount: " << discount << endl;
    cout << endl;
}

void Medicine::printSimplifiedInfo(ostream & os) const{
	os << "medicine" << "/"<<  name << '/' << stock << '/' << code << '/' << price << '/' << description << "/" << prescription << '/' << needed << '/' << discount;
}

void Medicine::printFileInfo(ostream & os) const{
	os << "medicine" << "/"<<  name << '/' << stock << '/' << code << '/' << price << '/' << description << "/" << prescription << '/' << needed << '/' << discount << ";";
}


Other::Other(string name,float stock, string code, float price, string description){
	this->name = name;
	this->stock = stock;
	this->code = code;
	this->price = price;
	this->description = description;
}

Other::Other(string product){
    unsigned long stop; //stop is pos for last ';' found

    //name
    stop = product.find_first_of('/');
    this->name = product.substr(0,stop);

    //stock
	product = product.substr(stop +1);
	stop = product.find_first_of('/');
	this->stock = stof(product.substr(0, stop));

    //code
    product = product.substr(stop+1);
    stop = product.find_first_of('/');
    this->code = product.substr(0,stop);

    //price
    product = product.substr(stop +1);
    stop = product.find_first_of('/');
    this->price = stof(product.substr(0, stop));

    //description
    product = product.substr(stop + 1);
    this->description = product;
}

Other::~Other(){

}

string Other::getTypeProduct() const{
	return "other";
}

float Other::getTotalPrice() const{
	return this->price;
}

void Other::printProductInfo() const{
    cout << "Name: " << name << endl;
    cout << "Code: " << code << endl;
    cout << "Price: " << price << endl;
    cout << "Description: " << description << endl;
    cout << endl << endl;
}

void Other::printSimplifiedInfo(ostream & os) const{
	os  << "other/" << name << '/' << stock << '/' << code << '/' << price << '/' << description;
}

void Other::printFileInfo(ostream & os) const{
	os  << "other/" << name << '/' << stock << '/' << code << '/' << price << '/' << description << ";";
}
