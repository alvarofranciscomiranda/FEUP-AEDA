#ifndef SALES_H_
#define SALES_H_

#include "Product.h"
#include "Date.h"
#include <utility>
#include <vector>
using namespace std;

class Sales{

protected:
	vector<Product *> products;
	vector<int> quantity;
    Date date;


public:
    Sales();
    Sales(string product);
    Sales(vector<Product*> products,  vector<int> quantity, Date date);

    static int sales_id;
    vector<Product*> getProducts() const;
    vector<int> getQuantity() const;
    Date getDate() const;

    void setProducts(vector<Product*> product);
    void setQuantity(vector<int> product);
    void setDate(Date date);

    float getTotalValue() const;

    void addQuantity(string name, int quantity);
    void addQuantityOnly(int quantity);
    void addProduct(Product* product);
    void addProductOnly(Product* product);

    void printSalesInfo() const;
	void printSimplifiedInfo(ostream & os) const;
};
#endif /* SALES_H_ */
