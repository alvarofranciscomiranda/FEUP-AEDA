#ifndef UNTITLED_PHARMACY_H
#define UNTITLED_PHARMACY_H

#include "People.h"
#include "Product.h"
#include <vector>
#include <string>
#include <math.h>

using namespace std;


class Pharmacy {
protected:
    string name, address, manager;
    vector<Employee*> employees;
    vector<string> products;

public:
    /**
     * @brief Constructor for class Pharmacy.
     * @param name
     * @param address
     * @param manager
     */
    Pharmacy(string name, string address, string manager);

    /**
    * @brief Alternative constructor for class Beach.
    */
    Pharmacy(string pharmacy);

    /**
     * @return name
     */
    string getName() const;

    /**
     * @return address
     */
    string getAddress() const;

    /**
     * @return manager
     */
    string getManager() const;

    /**
     *
     * @return vector of Pharmacy employees
     */
    vector<Employee*> getEmployees() const;

    /**
    *
    * @return vector of Pharmacy products
    */
    vector<string> getProducts() const;

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
     * @brief Changes manager.
     * @param manager
     */
    void setManager(string manager);

    /**
     * @brief Changes employees.
     * @param employees
     */
    void setEmployees(vector<Employee*> &employees);

    /**
     * @brief Changes products.
     * @param employees
     */
    void setProducts(vector<string> products);

    /**
    * @brief Adds employee to the vector.
    * @param employee
    */
    void addEmployee(Employee *employee);

    /**
    * @brief Adds product to the vector.
    * @param product
    */
    void addProduct(string product);

    /**
     * @brief Displays all information about the pharmacy.
     */
    void displayPharmacy();


    /**
     * @brief Writes information about the pharmacy in .txt file.
     * @param file
     */
    void writePharmacy(ofstream & file) const;
};

#endif //UNTITLED_PHARMACY_H
