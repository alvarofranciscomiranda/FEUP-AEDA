#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <iostream>
using namespace std;

class Product {

protected:
    string name, description, code;
    float price;

public:
    Product();
    Product(string name,string code, float price, string description);
    string getName() const;
    string getCode() const;
    float getPrice() const;
    string getDescription() const;
    void setName(string name);
    void setCode(string code);
    void setPrice(float price);
    void setDescription(string address);
    void displayProduct();
    Product(string product);
    void writeProduct(ofstream & file) const;
};

class Medicine : public Product{

protected:
    bool prescription, needed;
    int discount;
public:
    Medicine(string name,string code, float price, string description, bool prescription, bool needed, int discount);
    bool getPrescription() const;
    bool getNeeded() const;
    int getDiscount() const;
    void setPrescription(bool prescription);
    void setNeeded(bool needed);
    void setDiscount(int discount);
};



#endif /* PRODUCT_H_ */
