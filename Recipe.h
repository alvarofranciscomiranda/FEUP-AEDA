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
    static int id;
    int recipe_number;

    /**
    * Constructor of class Employee.
    	*/
    Recipe(int number , string user, string medic);

    /**
    * Constructor of class Employee.
    	*/
    Recipe(string recipe);

    /**
    * @return number
    */
    int getNumber() const;

    /**
    * @return user
    	*/
    string getUser() const;

    /**
    * @return medic
    */
    string getMedic() const;

    /**
    * @return products
   	*/
    vector <Product*> getProducts() const;

    /**
    * @return sold
    	*/
    vector <Product*>getSold() const;

    /**
    	 * @brief Changes number.
    	 * @param number
    	 */
    void setNumber(int number);

    /**
    	 * @brief Changes user.
    	 * @param user
    	 */
    void setUser(string user);

    /**
    	 * @brief Changes medic.
    	 * @param medic
    	 */
    void setMedic(string medic);

    /**
    	 * @brief Changes products.
    	 * @param products
    	 */
    void setProducts(vector <Product*> products);

    /**
    	 * @brief Changes sold.
    	 * @param sold
    	 */
    void setSold(vector <Product *> sold);

    /**
    	* adds products
    	*/
    void addProduct(Product * product);

    /**
    	* adds sold recipes
    	*/
    void addSold(Product * sold);

    /**
    	* displays product info
    	*/
    void printProductInfo() const;

    /**
    	* displays Info about something
    	*/
	void printSimplifiedInfo(ostream & os) const;

        /**
        * @return medic
        */
        string getMedic() const;

        /**
        * @return products
       	*/
        vector <Product*> getProducts() const;

        /**
        * @return sold
        	*/
        vector <Product*>getSold() const;

        /**
        	 * @brief Changes number.
        	 * @param number
        	 */
        void setNumber(int number);

        /**
        	 * @brief Changes user.
        	 * @param user
        	 */
        void setUser(string user);

        /**
        	 * @brief Changes medic.
        	 * @param medic
        	 */
        void setMedic(string medic);

        /**
        	 * @brief Changes products.
        	 * @param products
        	 */
        void setProducts(vector <Product*> products);

        /**
        	 * @brief Changes sold.
        	 * @param sold
        	 */
        void setSold(vector <Product *> sold);

        /**
        	* adds products
        	*/
        void addProduct(Product * product);

        /**
        	* adds sold recipes
        	*/
        void addSold(Product * sold);

        /**
        	* displays product info
        	*/
        void printProductInfo() const;

        /**
        	* displays Info about something
        	*/
    	void printSimplifiedInfo(ostream & os) const;


};


#endif /* RECIPE_H_ */
