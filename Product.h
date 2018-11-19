#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <iostream>
using namespace std;

class Product {

protected:
    string name, description;
    int code, price;

public:
    Product();
    Product(string name,int code, int price, string description);
    string getName() const;
    int getCode() const;
    int getPrice() const;
    string getDescription() const;
    void setName(string name);
    void setCode(int code);
    void setPrice(int price);
    void setDescription(string address);
};

class Medicine : public Product{

protected:
    bool prescription, needed;
    int discount;
public:
    Medicine(string name,int code, int price, string description, bool prescription, bool needed, int discount);
    bool getPrescription() const;
    bool getNeeded() const;
    int getDiscount() const;
    void setPrescription(bool prescription);
    void setNeeded(bool needed);
    void setDiscount(int discount);


};



#endif /* PRODUCT_H_ */
