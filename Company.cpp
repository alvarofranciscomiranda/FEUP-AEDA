//
// Created by Maria João Senra Viana on 29/10/2018.
//

#include "Company.h"
#include "Interfaces.h"
#include <algorithm>
#include <fstream>
using namespace std;

Company::Company() {
    string filePharmacy = "PharmacyFile.txt";
    ifstream file;
    string pharmacy;
    unsigned long stop;

    //verify file is successfully opened

   /* file.open(filePharmacy);

    if (!file.is_open()) {
        cout << "Error in opening file. Exiting program...";
        exit(1);

    }*/
}

void Company::displayPharmacies() {

    int option;

    ClearScreen();

    for (unsigned int i = 0; i < pharmacies.size(); i++) {

        try { pharmacies.at(i)->displayPharmacy(); } catch (int x) {
            cout << endl << "This pharmacy doesn't have any services associated." << endl << endl;
        }


    }

    returnMainMenu();
}
