#include <iostream>
#include <algorithm>
#include "Interfaces.h"
#include "Company.h"

using namespace std;

int main() {

    Company comp;

    comp.openPharmacyFile();
    comp.openEmployeesFile();
    comp.openClientsFile();
    comp.openProductsFile();
    comp.openRecipesFile();
    comp.openSalesFile();
    comp.addProductsQueue();

    ClearScreen();

    mainMenu(comp);

    return 0;
}
