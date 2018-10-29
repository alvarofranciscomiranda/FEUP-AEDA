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
    vector<Pharmacy *> getPharmacies(){return pharmacies;}

    /**
   * @brief Displays the information about all pharmacies.
   */
    void displayPharmacies();
};


#endif //UNTITLED_COMPANY_H
