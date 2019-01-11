#ifndef UNTITLED_PEOPLE_H
#define UNTITLED_PEOPLE_H

#include <iostream>
#include <vector>
#include "Sales.h"
using namespace std;


class People {

protected:
    string name, address;
	int taxNumber;

public:
	/**
	* Desconstructor of class People.
	 */
	virtual ~People(){};

	/**
	* Constructor of class People.
	*/
    People();

    /**
    	* Constructor of class People.
    	*/
    People(string name, string address, int taxNumber);

    /**
    	* @return name
    	*/
    string getName() const;

    /**
    	* @return address
    	*/
    string getAddress() const;

    /**
    	* @return tax number
    	*/
    int getTaxNumber() const;

    /**
    * @brief Changes name.
    * @param name
    */
    void setName(string name);

    /**
    * @brief Changes address.
    * @param address
    */
    void setAddress(string address);

    /**
     * @brief Changes taxNumber.
     * @param taxNumber
     */
    void setTaxNumber(int taxNumber);

    /**
     * displays Info about something
     */
	virtual void printSimplifiedInfo(ostream & os) const = 0;

	/**
	 * Displays person
	 */
	virtual void displayPerson() const = 0;
};

class Employee : public People{

protected:
    float salary;
    string pharmacy, post;
    bool actualEmployee;

public:
    /**
        	* Desonstructor of class Employee.
        	*/
        ~Employee(){};

        /**
        	* Constructor of class Employee.
        	*/
        Employee(){};

        /**
        	* Constructor of class Employee.
        	*/
        Employee(string name, string address, int taxNumber, float salary, string pharmacy, string post, bool actualEmployee);

        /**
        	* Constructor of class Employee.
        	*/
    	Employee(string employee);

    	/**
    	* @return salary
    	*/
        float getSalary() const;

        /**
        * @return pharmacy
        	*/
        string getPharmacy() const;

        /**
        * @return post
        	*/
        string getPost() const;

        /**
        	* @return actual employee
        	*/
        bool getActualEmployee() const;

        /**
        * @brief Changes salary.
        * @param salary
        */
        void setSalary(float salary);

        /**
        * @brief Changes pharmacy.
        * @param pharmacy
        */
        void setPharmacy(string pharmacy);

        /**
        * @brief Changes post.
        * @param post
        */
        void setPost(string post);

        /**
        * @brief Changes actual employee.
        * @param actualEmployee
        */
        void setActualEmployee(bool actualEmployee);

        /**
        * Displays person
        */
        void displayPerson() const;

        /**
        	 * displays Info about something
        	 */
    	void printSimplifiedInfo(ostream & os) const;
};

class Client : public People{
protected:
	vector<Sales *> purchases;
	string district;
public:
	static int id;
	int client_number;

	/**
	* Desonstructor of class Employee.
	*/
	Client(){};

	/**
 	* Constructor of class Employee.
	*/
	Client(string client);

	/**
	* Constructor of class Employee.
 	*/
	Client(int id,string name, string district, string address, int taxNumber);

	/**
	* Constructor of class Employee.
 	*/
	Client(string name, string district, string address, int taxNumber);

    /**
    * @return district
    	*/
	string getDistrict() const;

    /**
    * @return client number
    	*/
	int getClient_number() const;

    /**
    * @return purchases
    	*/
	vector<Sales *> getPurchases() const;

	/**
	 * @brief Changes district.
	 * @param district
	 */
	void setDistrict(string district);

	/**
	 * @brief Changes client number.
	 * @param client_number
	 */
	void setClient_number(int client_number);

	/**
	* @brief Changes purchases.
	* @param purchases
	 */
    void setPurchases(vector<Sales *> purchases);

    /**
    	 * @brief Changes adds purchases.
    	 */
	void addPurchases(Sales * purchases);

	/**
	 * @brief < operator
	*/
	bool operator<(const Client c1) const;

	/**
	 * @brief == operator
	*/
	bool operator ==(const Client * c1){
		return name== c1->getName();}

	/**
	* Displays person
	*/
	void displayPerson() const;

	/**
	* displays Info about something
	*/
	void printSimplifiedInfo(ostream & os) const;
};

#endif //UNTITLED_PEOPLE_H
