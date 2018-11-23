#ifndef UNTITLED_COMPANY_H
#define UNTITLED_COMPANY_H

#include <iomanip>
#include <math.h>
#include <String>
#include "Pharmacy.h"
#include "Recipe.h"
#include "Sales.h"
#include "People.h"


using namespace std;

class Company {
private:
    vector<Pharmacy *> pharmacies;
    vector<Employee *> employees;
    vector<Client *> clients;
    vector<Product *> products;
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
    * @brief Opens Pharmacy File.
    */
    void openPharmacyFile();

    /**
   * @brief Opens Employees File.
   */
    void openEmployeesFile();

    /**
   * @brief Opens Clients File.
   */
    void openClientsFile();

    /**
   * @brief Opens Products File.
   */
    void openProductsFile();

    /**
    * @brief Displays the information about all pharmacies.
    */
    void displayPharmacies();

    /**
    * @brief Displays the information about all employees.
    */
    void displayEmployees();

    /**
     * @brief Displays the information about all clients.
     */
    void displayClients();

    /**
    * @brief Displays the information about all products.
    */
    void displayProducts();

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

    /**
     * @brief Removes pharmacy to Pharmacies' vector with user's input information.
     */
    void removePharmacy();

    /**
    * @brief Displays information about 2 pharmacies side by side.
    * @param 1st Pharmacy
    * @param 2nd Pharmacy
    */
    void comparePharmacies(Pharmacy *p1, Pharmacy *p2);

    /**
    * @brief Updates the file containing the information about the pharmacies according to the changes made in the program.
    */
    void updatePharmacyFile();

    /**
    * @brief Updates the file containing the information about the employees according to the changes made in the program.
    */
    void updateEmployeeFile();

    /**
    * @brief Updates the file containing the information about the clients according to the changes made in the program.
    */
    void updateClientFile();

    /**
    * @brief Updates the file containing the information about the products according to the changes made in the program.
    */
    void updateProductFile();
};
    /**
    * @brief Sorts pharmacies vector by name's alphabetic order.
    * @param s1
    * @param s2
    * @return
    */
    bool orderByNamePharmacy(Pharmacy *s1, Pharmacy *s2);
    bool orderByNameAddress(Pharmacy *p1, Pharmacy *p2);
    bool orderByNameEmployee(Employee *p1, Employee *p2);
    bool orderByNameManager(Pharmacy *p1, Pharmacy *p2);
    bool orderByNameClient(Client *p1, Client *p2);
    bool orderByNameProduct(Product *p1, Product *p2);



#endif //UNTITLED_COMPANY_H
