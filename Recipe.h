#ifndef RECIPE_H_
#define RECIPE_H_

#include <iostream>
#include <Vector>
#include "Product.h"
using namespace std;

class Recipe {

protected:
    string user, medic;
    int number;
    vector<Product*> products;
    vector<Product*> sold;


public:
    Recipe(int number , string user, string medic);
    Recipe(string recipe);

    int getNumber() const;
    string getUser() const;
    string getMedic() const;
    vector <Product*> getProducts() const;
    vector <Product*>getSold() const;

    static int id;
    int recipe_number;
    void setNumber(int number);
    void setUser(string user);
    void setMedic(string medic);
    void setProducts(vector <Product*> products);
    void setSold(vector <Product *> sold);

    void addProduct(Product * product);
    void addSold(Product * sold);

    void printProductInfo() const;
	void printSimplifiedInfo(ostream & os) const;


};


#endif /* RECIPE_H_ */
