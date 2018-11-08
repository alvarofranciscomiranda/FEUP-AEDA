#ifndef UNTITLED_COMPANY_H
#define UNTITLED_COMPANY_H

#include <iomanip>
#include <math.h>
#include "Pharmacy.h"

using namespace std;

class Company {
private:
    vector<Pharmacy *> pharmacies;
public:

    /**
     * Constructor of class Company.
     */
    Company();

    /**
    * @return vector Pharmacies
    */
    vector<Pharmacy *> getPharmacies(){
        return pharmacies;
    }
    /**
    * @brief Displays the information about all pharmacies.
    */
    void displayPharmacies();

    /**
     * @brief Search pharmacy by name and displays its information.
     */
    void searchName();

    /**
     * @brief Search pharmacy by address and displays its information.
     */
    void searchAddress();

    /**
     * @brief Search pharmacy by manager and displays its information.
     */
    void searchManager();

    /**
     * @brief Search pharmacy by employee and displays its information.
     */
    void searchEmployees();

    /**
     * @brief Search pharmacy by client and displays its information.
     */
    void searchClients();

    /**
    * @brief Verifies if pharmacy with certain name exist.
    * @param name
    * @return pos of beach in Pharmacies' vector if pharmacy with name exists, -1 otherwise
    */
    int pharmacyExists(string name);

    /**
    * @brief Adds pharmacy to Pharmacies' vector with user's input information.
    */
    void addPharmacy();
};

    /**
    * @brief Sorts pharmacies vector by name's alphabetic order.
    * @param s1
    * @param s2
    * @return
    */
    bool orderByName(Pharmacy *s1, Pharmacy *s2);
    bool orderByNameAddress(Pharmacy *p1, Pharmacy *p2);
    bool orderByNameEmployee(Employee *p1, Employee *p2);
    bool orderByNameManager(Pharmacy *p1, Pharmacy *p2);
    bool orderByNameClient(Client *p1, Client *p2);



#endif //UNTITLED_COMPANY_H
