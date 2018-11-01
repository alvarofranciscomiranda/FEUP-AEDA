#ifndef UNTITLED_PHARMACY_H
#define UNTITLED_PHARMACY_H

#include "People.h"
#include <vector>
#include <string>
#include <math.h>
using namespace std;

class Pharmacy {
protected:
    string name, address, manager;
    vector<Employee> employees;
    vector<Client> clients;
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
    vector<Employee> getEmployees() const;

    /**
     * @return vector of Pharmacy clients
     */
    vector<Client> getClients() const;

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
    void setEmployees(vector<string> &employees);

    /**
     * @brief Changes clients.
     * @param clients
     */
    void setClients(vector<string> &clients);

    /**
     * @brief Displays all information about the pharmacy.
     */
    void displayPharmacy();


};

#endif //UNTITLED_PHARMACY_H
