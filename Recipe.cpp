#include "Recipe.h"
#include <iostream>
using namespace std;

int Recipe::id = 1;

Recipe::Recipe(int number, string user, string medic) :number(number), user(user), medic(medic){
	if(number < id){
		this->number = id;
	}
	id++;

}

Recipe::Recipe(string recipe){
	unsigned long stop; //stop is pos for last ';' found

	//number
	stop = recipe.find_first_of(';');
	this->number = stoi(recipe.substr(0,stop));

	if(number < id){
		this->number=id;
	}
	id++;

	//user
	recipe = recipe.substr(stop + 1);
	stop = recipe.find_first_of(';');
	this->user = recipe.substr(0,stop);

	//medic
	recipe = recipe.substr(stop + 1);
	this->medic = recipe;
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

vector<Product*> Recipe::getProducts() const{
    return products;
}

vector<Product*> Recipe::getSold() const{
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

void Recipe::setProducts(vector<Product*> products){
	this->products = products;
}

void Recipe::setSold(vector<Product*> sold){
	this->sold = sold;
}

void Recipe::addProduct(Product * product){
	this->products.push_back(product);
}

void Recipe::addSold(Product * sold){
	this->sold.push_back(sold);
}

void Recipe::printProductInfo() const{

    cout << "Number: " << number << endl;
    cout << "User: " << user << endl;
    cout << "Medic: " << medic << endl;
    cout << "Products recited: " << endl;
   for(unsigned int i = 0; i < this->products.size(); i++)
    	products.at(i)->printProductInfo();
    cout << "Products sold: " << endl;
    for(unsigned int i = 0; i < this->sold.size(); i++)
       	sold.at(i)->printProductInfo();
    cout << endl;

}

void Recipe::printSimplifiedInfo(ostream & os) const{
	os <<  number << ';' << user << ';' << medic << endl;
	for(unsigned int i = 0; i < this->products.size(); i++){
    	products.at(i)->printFileInfo(os);
	}
	os << endl;
	for(unsigned int i = 0; i < this->sold.size(); i++){
		sold.at(i)->printFileInfo(os);
	}
}


