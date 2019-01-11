#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <iostream>
#include <string>

using namespace std;

class Product {

protected:
    string name, description, code;
    float price, stock;

public:
    virtual ~Product();

    string getName() const;
    string getCode() const;
    float getPrice() const;
    float getStock() const;
    string getDescription() const;

    void setName(string name);
    void setCode(string code);
    void setPrice(float price);
    void setStock(float stock);
    void setDescription(string address);

	virtual string getTypeProduct() const = 0;
	virtual float getTotalPrice() const = 0;
	virtual void printProductInfo() const = 0;
	virtual void printSimplifiedInfo(ostream & os) const = 0;
	virtual void printFileInfo(ostream & os) const = 0;


    bool operator ==(const Product & c) const;

};

class Medicine : public Product{

protected:
    bool prescription, needed;
    int discount;
public:
    ~Medicine();
    Medicine(string product);
    Medicine(string name, float stock, string code, float price, string description, bool prescription, bool needed, int discount);
    bool getPrescription() const;
    bool getNeeded() const;
    int getDiscount() const;
    void setPrescription(bool prescription);
    void setNeeded(bool needed);
    void setDiscount(int discount);

    string getTypeProduct() const;
    float getTotalPrice() const;
    void printProductInfo() const;
	void printSimplifiedInfo(ostream & os) const;
	void printFileInfo(ostream & os) const;


};



class Other : public Product{

protected:

public:
    ~Other();
    Other(string product);
    Other(string name, float stock, string code, float price, string description);

    string getTypeProduct() const;
    float getTotalPrice() const;
    void printProductInfo() const;
	void printSimplifiedInfo(ostream & os) const;
	void printFileInfo(ostream & os) const;
};



#endif /* PRODUCT_H_ */
