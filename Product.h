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
    /**
    	* Desconstructor of class Product.
    	 */
    virtual ~Product();

    /**
     * @return name
    	*/
    string getName() const;

    /**
    * @return code
    	*/
    string getCode() const;

    /**
    * @return price
  	*/
    float getPrice() const;

    /**
    * @return stock
    	*/
    float getStock() const;

    /**
    * @return description
   */
    string getDescription() const;

    /**
     * @brief Changes name.
     * @param name
     */
    void setName(string name);

    /**
   * @brief Changes code.
   * @param code
   */
    void setCode(string code);

    /**
     * @brief Changes price.
     * @param price
     */
    void setPrice(float price);

    /**
    * @brief Changes stock.
    * @param stock
    */
    void setStock(float stock);

    /**
     * @brief Changes description.
     * @param address
     */
    void setDescription(string address);

    /**
    * @return product type
    */
	virtual string getTypeProduct() const = 0;

	/**
	 * @return total price
	 */
	virtual float getTotalPrice() const = 0;

	/**
	 * displays product info
	*/
	virtual void printProductInfo() const = 0;

	/**
	* displays Info about something
	*/
	virtual void printSimplifiedInfo(ostream & os) const = 0;

	/**
	 * displays file info
	 */
	virtual void printFileInfo(ostream & os) const = 0;

    bool operator ==(const Product & c) const;

};

class Medicine : public Product{

protected:
    bool prescription, needed;
    int discount;
public:

    /**
    	* Desonstructor of class Medicine.
    	*/
    ~Medicine();

    /**
    * Constructor of class Employee.
    	*/
    Medicine(string product);

    /**
    * Constructor of class Employee.
    	*/
    Medicine(string name, float stock, string code, float price, string description, bool prescription, bool needed, int discount);

    /**
    * @return  prescription
    	*/
    bool getPrescription() const;

    /**
    * @return needed
    	*/
    bool getNeeded() const;

    /**
    * @return  discount
    	*/
    int getDiscount() const;

    /**
    	 * @brief Changes prescription.
    	 * @param prescription
    	 */
    void setPrescription(bool prescription);

    /**
    	 * @brief Changes needed.
    	 * @param needed
    	 */
    void setNeeded(bool needed);

    /**
    	 * @brief Changes discount.
    	 * @param discount
    	 */
    void setDiscount(int discount);

    /**
    * @return product type
    */
    string getTypeProduct() const;

    /**
    * @return total price
   	*/
    float getTotalPrice() const;

    /**
    	* displays product info
    	*/
    void printProductInfo() const;

    /**
    	* displays Info about something
    	*/
	void printSimplifiedInfo(ostream & os) const;

	/**
	* displays file info
	*/
	void printFileInfo(ostream & os) const;


};



class Other : public Product{

protected:

public:
	/**
	* Desonstructor of class Employee.
	*/
    ~Other();

    /**
    * Constructor of class Employee.
    	*/
    Other(string product);

    /**
    * Constructor of class Employee.
    	*/
    Other(string name, float stock, string code, float price, string description);

    /**
    * @return product type
   	*/
    string getTypeProduct() const;

    /**
    * @return total price
    */
    float getTotalPrice() const;

    /**
    * displays product info
    	*/
    void printProductInfo() const;

    /**
    	* displays Info about something
    	*/
	void printSimplifiedInfo(ostream & os) const;

	/**
	* displays file info
	*/
	void printFileInfo(ostream & os) const;
};



#endif /* PRODUCT_H_ */
