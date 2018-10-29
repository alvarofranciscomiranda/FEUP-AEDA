//
// Created by Maria João Senra Viana on 29/10/2018.
//

#ifndef UNTITLED_PHARMACY_H
#define UNTITLED_PHARMACY_H

#include <vector>
#include <string>
#include <math.h>
using namespace std;

class Pharmacy {
protected:
    string name, address, manager;
    vector<string> employees;
    vector<string> clients;
public:
    /**
     * @brief Constructor for class Pharmacy.
     * @param name
     * @param address
     * @param manager
     */
    Pharmacy(string &name, string &address, string &manager);

    /**
    * @brief Alternative constructor for class Beach.
    */
    Pharmacy(){};

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
    vector<string> getEmployees() const;

    /**
     * @return vector of Pharmacy clients
     */
    vector<string> getClients() const;

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

    void displayPharmacy();


};


#endif //UNTITLED_PHARMACY_H
