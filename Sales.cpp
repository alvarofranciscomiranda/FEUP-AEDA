#include "Sales.h"
#include <iostream>
using namespace std;

int Sales::sales_id = 1;

Sales::Sales(){};

Sales::Sales( vector<Product*> prod, vector<int> quant, Date date) : products(prod), quantity(quant) ,date(date){
	this->sales_id = sales_id;
	sales_id++;
}

Sales::Sales(string sale){
	Date * d = new Date(sale);
	this->date = *d;

	this->sales_id = sales_id;
	sales_id++;
}

vector<Product*> Sales::getProducts() const{
    return products;
}

vector<int> Sales::getQuantity() const{
    return quantity;
}

Date Sales::getDate() const{
    return date;
}


float Sales::getTotalValue() const{
    float total = 0;
    vector<Product*>::const_iterator it = products.begin();
    unsigned int i = 0;
    for(; it != products.end(); it++, i++){
    	total += (*it)->getTotalPrice();
    }
    return total;
}

void Sales::setProducts(vector<Product*> product){
    this->products = product;
}

void Sales::setQuantity(vector<int> quant){
    this->quantity = quant;
}

void Sales::setDate(Date date){
    this->date = date;
}

void Sales::addQuantity(string name, int quant){
	vector<Product*>::iterator it;
	unsigned int i = 0;
	for(it = products.begin(); it != products.end(); it++, i++){
		if((*it)->getName() == name){
			this->quantity.at(i) = quantity.at(i)+ quant;
		}
	}
}

void Sales::addQuantityOnly(int quantity){
	 this->quantity.push_back(quantity);
}


void Sales::addProduct(Product* product){
	this->products.push_back(product);
	this->quantity.push_back(1);
}

void Sales::addProductOnly(Product* product){
	this->products.push_back(product);
}

void Sales::printSalesInfo() const{
	cout << "Date: " ;
    this->getDate().printDate();
    for(unsigned int i = 0; i < this->products.size(); i++){
    	cout << "Products sold: ";
    	this->products.at(i)->printProductInfo();
    	cout << "Quantity sold: ";
    	cout << this->quantity.at(i);
    	cout << endl << endl;
    }
    cout << endl;
}

void Sales::printSimplifiedInfo(ostream & os) const{

	getDate().printDateInfo(os);
	for(unsigned int i = 0; i < this->products.size(); i++){
	    products.at(i)->printFileInfo(os);
	}
	os << endl;
	for(unsigned int i = 0; i < this->quantity.size(); i++){
		os << quantity.at(i) << ";";
	}
}


