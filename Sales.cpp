#include "Sales.h"
#include <iostream>
using namespace std;

Sales::Sales(){
	quantity = 0;
	iva= 0;
	price= 0;
	discount = 0;
};

Sales::Sales(Product product, int quantity, int iva, int price, int discount, Date date) : product(product), quantity(quantity), iva(iva), price(price), discount(discount), date(date){
}

Product Sales::getProduct() const{
    return product;
}

int Sales::getQuantity() const{
    return quantity;
}

int Sales::getIva() const{
    return iva;
}

int Sales::getPrice() const{
    return price;
}

int Sales::getDiscount() const{
    return discount;
}

Date Sales::getDate() const{
    return date;
}

void Sales::setProduct(Product product){
    this->product = product;
}

void Sales::setQuantity(int quantity){
    this->quantity = quantity;
}

void Sales::setIva(int iva){
    this->iva = iva;
}

void Sales::setPrice(int price){
    this->price;
}

void Sales::setDiscount(int discount){
    this->discount = discount;
}

void Sales::setDate(Date date){
    this->date = date;
}

