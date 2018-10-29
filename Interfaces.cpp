#include <iostream>
#include <iomanip>
#include <algorithm>

#include "Interfaces.h"

using namespace std;

void returnMainMenu(){
    int option;

    cout << endl << "0. Return to main menu" << endl << ":::";
    cin >> option;

    while (cin.fail() || !ValidMenuInput(0, 0, option)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid option: " << endl << ":::";
        cin >> option;
    }
}

bool ValidMenuInput(int lowerL, int upperL, int input){
    if(input<=upperL && input>=lowerL)
        return true;
    else return false;
}

void mainMenu(Company &company) {

    int option;

    cout << " MAIN MENU" << setw(40)<< setfill(' ') << " " << endl;
    cout << setfill('-') << setw(50)<<"-"<<endl;
    cout << "1. Display all pharmacy" << endl;
    cout << "2. Search pharmacy." << endl;
    cout << "3. Compare pharmacies" << endl;
    cout << "4. Add, alter or remove pharmacies" << endl;
    //cout << "5. Update pharmacies' file." << endl;

    cout << endl << "Enter a number option: " << endl << "::: ";
    cin >> option;

    //verifies if input is valid
    while(cin.fail()||!ValidMenuInput(1, 5, option)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid option: "<< endl << "::: ";
        cin >> option;
    }

    //redirect to next menu
    switch(option) {
        case 1:
            company.displayPharmacies();
            ClearScreen();
            mainMenu(company);
            break;
        case 2:
            //searchMenu(company);
            ClearScreen();
            mainMenu(company);
            break;
        case 3:
           // compareMenu(company);
            ClearScreen();
            mainMenu(company);
            break;
        case 4:
           // AddAlterRemoveMenu(company);
            ClearScreen();
            break;
        case 5:
            //company.updateFile();
            ClearScreen();
            mainMenu(company);
            break;

    }}

void ClearScreen() {

    cout << string(50,'\n');
}
