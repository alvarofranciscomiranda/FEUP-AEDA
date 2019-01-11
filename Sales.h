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
    static int sales_id;
    int sale_id;

    /**
    	* Constructor of class Employee.
    */
    Sales();

    /**
    	* Constructor of class Employee.
    */
    Sales(string product);

    /**
    	* Constructor of class Employee.
    */
    Sales(vector<Product*> products,  vector<int> quantity, Date date);

    /**
    * @return products
    */
    vector<Product*> getProducts() const;

    /**
    * @return quantity
    	*/
    vector<int> getQuantity() const;

    /**
    * @return date
    	*/
    Date getDate() const;

    /**
    * @return total value
    	*/
    float getTotalValue() const;

    /**
    	* @brief Changes products.
    	* @param product
    	 */
    void setProducts(vector<Product*> product);

    /**
    	* @brief Changes quantity.
    	* @param product
    	 */
    void setQuantity(vector<int> product);

    /**
    	* @brief Changes date.
    	* @param date
    	 */
    void setDate(Date date);

    /**
    * adds quantity
    */
    void addQuantity(string name, int quantity);

    /**
     * adds quantity
    */
    void addQuantityOnly(int quantity);

    /**
    * adds product
    */
    void addProductOnly(Product* product);

    /**
    * displays sales info
    */
    void printSalesInfo() const;

    /**
    * displays Info about something
    */
	void printSimplifiedInfo(ostream & os) const;
};
#endif /* SALES_H_ */
