#include <iostream>
#include <algorithm>
#include "Interfaces.h"
#include "Company.h"

using namespace std;

int main() {

    Company comp("Employees.txt", "Clients.txt", "PharmacyFile.txt", "Products.txt");

    comp.openPharmacyFile();
    comp.openEmployeesFile();
    comp.openClientsFile();
    comp.openProductsFile();

    ClearScreen();

    mainMenu(comp);

    return 0;
}
