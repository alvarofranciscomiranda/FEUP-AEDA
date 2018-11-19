#include "Recipe.h"
#include <iostream>
using namespace std;

Recipe::Recipe(int number,string user, string medic, vector<Product> products, vector<Product> sold) :number(number), user(user), medic(medic), products(products), sold(sold){
}

int Recipe::getNumber() const{
    return number;
}

string Recipe::getUser() const{
    return user;
}

string Recipe::getMedic() const{
    return medic;
}

vector<Product> Recipe::getProducts() const{
    return products;
}

vector<Product> Recipe::getSold() const{
    return sold;
}

void Recipe::setNumber(int number){
    this->number = number;
}

void Recipe::setUser(string user){
	this->user = user;
}

void Recipe::setMedic(string medic){
    this->medic = medic;
}

void Recipe::setProducts(vector<Product> products){
    this->products = products;
}

void Recipe::setSold(vector<Product> sold){
    this->sold = sold;
}

void Recipe::addProduct(Product product){
	this->products.push_back(product);
}

void Recipe::addSold(Product sold){
	this->sold.push_back(sold);
}





