#include "Company.h"
#include "Interfaces.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

Company::Company() {

    ifstream file("/Users/mariajoaosenraviana/Desktop/untitled/PharmacyFile.txt");
    string pharmacy;
    unsigned long stop;

    //verify file is successfully opened

    if (file.is_open()) {
        while (!file.eof()) {

            getline(file, pharmacy);
            pharmacies.push_back(new Pharmacy(pharmacy));
            }
        }

        file.close();
}

void Company::displayPharmacies() {

    int option;

    ClearScreen();

    for (unsigned int i = 0; i < pharmacies.size(); i++) {

         pharmacies.at(i)->displayPharmacy();
            //cout << endl << "This pharmacy doesn't have any services associated." << endl << endl;

    }
    returnMainMenu();
}

void Company::searchName() {

    string name;
    int option;

    ClearScreen();

    sort(pharmacies.begin(),pharmacies.end(), orderByName);

    cout << "Insert the name of the pharmacy you wish to search for" << endl << ":::";
    cin.ignore(1000, '\n');
    getline(cin, name);

    ClearScreen();

    int left = 0, right = pharmacies.size() - 1;

    while (left <= right) {
        int middle = (left + right) / 2;
        if (pharmacies.at(middle)->getName() < name)
            left = middle + 1;
        else if (name < pharmacies.at(middle)->getName())
            right = middle - 1;
        else {
            pharmacies.at(middle)->displayPharmacy();
            break;
        }
    }

    returnMainMenu();
}

void Company::searchAddress() {

    string address;
    int option;

    ClearScreen();

    sort(pharmacies.begin(),pharmacies.end(), orderByNameAddress);

    cout << "Insert the address of the pharmacy you wish to search for" << endl << ":::";
    cin.ignore(1000, '\n');
    getline(cin, address);

    ClearScreen();

    int left = 0, right = pharmacies.size() - 1;

    while (left <= right) {
        int middle = (left + right) / 2;
        if (pharmacies.at(middle)->getAddress() < address)
            left = middle + 1;
        else if (address < pharmacies.at(middle)->getAddress())
            right = middle - 1;
        else {
            pharmacies.at(middle)->displayPharmacy();
            break;
        }
    }

    returnMainMenu();
}

void Company::searchManager() {

    string manager;
    int option;

    ClearScreen();

    sort(pharmacies.begin(),pharmacies.end(), orderByNameManager);

    cout << "Insert the manager of the pharmacy you wish to search for" << endl << ":::";
    cin.ignore(1000, '\n');
    getline(cin, manager);

    ClearScreen();

    int left = 0, right = pharmacies.size() - 1;

    while (left <= right) {
        int middle = (left + right) / 2;
        if (pharmacies.at(middle)->getManager() < manager)
            left = middle + 1;
        else if (manager < pharmacies.at(middle)->getManager())
            right = middle - 1;
        else {
            pharmacies.at(middle)->displayPharmacy();
            break;
        }
    }

    returnMainMenu();
}

//n funciona
void Company::searchEmployees() {

    string employee;
    int option;

    ClearScreen();



    cout << "Insert the employee of the pharmacy you wish to search for" << endl << ":::";
    cin.ignore(1000, '\n');
    getline(cin, employee);

    ClearScreen();

    for(int i = 0; i < pharmacies.size(); i++){
        sort(pharmacies.at(i)->getEmployees().begin(),pharmacies.at(i)->getEmployees().end(), orderByNameEmployee);
        int left = 0, right = pharmacies.at(i)->getEmployees().size() - 1;
     while (left <= right) {
        int middle = (left + right) / 2;
        if (pharmacies.at(i)->getEmployees().at(middle)->getName() < employee)
            left = middle + 1;
        else if (employee < pharmacies.at(i)->getEmployees().at(middle)->getName())
            right = middle - 1;
        else {
            pharmacies.at(i)->displayPharmacy();
            break;
        }
     }
    }

    returnMainMenu();
}

//n funciona
void Company::searchClients() {

    string client;
    int option;

    ClearScreen();

   // sort(pharmacies.begin(),pharmacies.end(), orderByNameClient);

    cout << "Insert the employee of the pharmacy you wish to search for" << endl << ":::";
    cin.ignore(1000, '\n');
    getline(cin, client);

    ClearScreen();
           pharmacies.at(0)->getClients()[0]->getName()  ;
    sort(pharmacies.at(0)->getClients().begin(),pharmacies.at(0)->getClients().end(), orderByNameClient);
    for(int i = 0; i < pharmacies.size(); i++){
         sort(pharmacies.at(i)->getClients().begin(),pharmacies.at(i)->getClients().end(), orderByNameClient);
        int left = 0, right = pharmacies.at(i)->getClients().size() - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (pharmacies.at(i)->getClients().at(middle)->getName() < client)
                left = middle + 1;
            else if (client < pharmacies.at(i)->getClients().at(middle)->getName())
                right = middle - 1;
            else {
                pharmacies.at(i)->displayPharmacy();
                break;
            }
        }
    }

    returnMainMenu();
}

int Company::pharmacyExists(string name) {

    sort(pharmacies.begin(),pharmacies.end(),orderByName);

    int left = 0, right = pharmacies.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (pharmacies.at(middle)->getName() < name)
            left = middle + 1;
        else if (name < pharmacies.at(middle)->getName())
            right = middle - 1;
        else
            return middle; // encontrou
    }
    return -1; // não encontrou
}

void Company::addPharmacy() {
    string address, name, manager;
    vector<Client*> clients;
    vector<Employee*> employees;
    int counter = 0, employee, client;
    string nameE, addressE, taxNE, pharmacyE, postE, nameC, addressC, taxNC;
    float salaryE;

    cout << endl << "Insert name of the pharmacy: " << endl << "::: ";
    cin.ignore(1000, '\n');
    getline(cin, name);
    if(pharmacyExists(name) != -1) { throw  -1;}

    cout << endl << "Insert address (eg: Oeiras): " << endl << "::: ";
    getline(cin, address);

    cout << endl << "Insert name of the manager " << endl << "::: ";
    getline(cin, manager);

    pharmacies.push_back(new Pharmacy(name, address, manager));

    cout << endl << "How many employees would you like to add? " << endl << "::: ";
    cin >> employee;
    fail(employee);
    cin.ignore(1000, '\n');
    counter = 0;
    while (counter < employee) {
        cout << endl << "Employee " << ++counter << ": ";

        cout << endl << "Employee's name: ";
        getline(cin, nameE);

        cout << endl << "Employee's address: ";
        getline(cin, addressE);

        cout << endl << "Employee's tax number: ";
        getline(cin, taxNE);

        cout << endl << "Employee's salary: ";
        cin >> salaryE;
        fail(salaryE);

        cout << endl << "Employee's pharmacy: ";
        cin.ignore(1000, '\n');
        getline(cin, pharmacyE);

        cout << endl << "Employee's post: ";
        cin.ignore(1000, '\n');
        getline(cin, postE);

        pharmacies.at(pharmacies.size() - 1)->addEmployee(new Employee(nameE, addressE, taxNE, salaryE, pharmacyE, postE));
    }

    cout << endl << "How many clients would you like to add?: " << endl << "::: ";
    cin >> client;
    fail(client);
    cin.ignore(1000, '\n');
    counter = 0;
    while (counter < client) {
        cout << endl << "Client " << ++counter << ": ";

        cout << endl << "Client's name: ";

        getline(cin, nameC);

        cout << endl << "Client's address: ";

        getline(cin, addressC);

        cout << endl << "Client's tax number: ";

        getline(cin, taxNC);

        pharmacies.at(pharmacies.size() - 1)->addClient(new Client(nameC, addressC, taxNC));
    }
    cout << string(2, '\n') << "Pharmacy added successfully!" << string(2, '\n');
}

bool orderByName(Pharmacy *p1, Pharmacy *p2){

    if(p1->getName() < p2->getName()) return true;
    else if(p1->getName() > p2->getName()) return false;
}

 bool orderByNameManager(Pharmacy *p1, Pharmacy *p2){

     if(p1->getManager() < p2->getManager()) return true;
     else if(p1->getManager() > p2->getManager()) return false;
 }

bool orderByNameAddress(Pharmacy *p1, Pharmacy *p2){

    if(p1->getAddress() < p2->getAddress()) return true;
    else if(p1->getAddress() > p2->getAddress()) return false;
}

bool orderByNameEmployee(Employee *p1, Employee *p2){

    if(p1->getName() < p2->getName()) return true;
    else if(p1->getName() > p2->getName()) return false;
}


bool orderByNameClient(Client *p1, Client *p2) {

    if (p1->getName() < p2->getName()) return true;
    else if (p1->getName() > p2->getName()) return false;
    else return false;
}