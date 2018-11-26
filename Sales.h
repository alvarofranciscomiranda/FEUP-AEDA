#ifndef SALES_H_
#define SALES_H_

#include "Product.h"
#include "Date.h"
using namespace std;

class Sales{

protected:
	Product product;
    int quantity, iva, price, discount;
    Date date;

public:
    Sales();
    Sales(Product product, int quantity, int iva, int price, int discount, Date date);
    Product getProduct() const;
    int getQuantity() const;
    int getIva() const;
    int getPrice() const;
    int getDiscount() const;
    Date getDate() const;
    void setProduct(Product product);
    void setQuantity(int quantity );
    void setIva(int iva);
    void setPrice(int price);
    void setDiscount(int discount);
    void setDate(Date date);
};
#endif /* SALES_H_ */
