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

void Company::searchEmployees() {

    string employee;

    ClearScreen();

    cout << "Insert the employee of the pharmacy you wish to search for" << endl << ":::";
    cin.ignore(1000, '\n');
    getline(cin, employee);

    ClearScreen();

    for(int i = 0; i < pharmacies.size(); i++){
        vector <Employee *> temp=pharmacies.at(i)->getEmployees();
        sort(temp.begin(),temp.end(), orderByNameEmployee);
        int left = 0, right = temp.size() - 1;
     while (left <= right) {
        int middle = (left + right) / 2;
        if (temp.at(middle)->getName() < employee)
            left = middle + 1;
        else if (employee < temp.at(middle)->getName())
            right = middle - 1;
        else {
            pharmacies.at(i)->displayPharmacy();
            break;
        }
     }
    }

    returnMainMenu();
}

void Company::searchClients() {

    string client;

    ClearScreen();

    cout << "Insert the employee of the pharmacy you wish to search for" << endl << ":::";
    cin.ignore(1000, '\n');
    getline(cin, client);

    ClearScreen();

    for(int i = 0; i < pharmacies.size(); i++){
        vector <Client *> temp=pharmacies.at(i)->getClients();
        sort(temp.begin(),temp.end(), orderByNameClient);
        int left = 0, right = temp.size() - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (temp.at(middle)->getName() < client)
                left = middle + 1;
            else if (client < temp.at(middle)->getName())
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
        int taxN = stoi(taxNE,nullptr);

        cout << endl << "Employee's salary: ";
        cin >> salaryE;
        fail(salaryE);

        cout << endl << "Employee's post: ";
        cin.ignore(1000, '\n');
        getline(cin, postE);

        pharmacies.at(pharmacies.size() - 1)->addEmployee(new Employee(nameE, addressE, taxN, salaryE, nameE, postE));
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
        int taxN2 = stoi(taxNE,nullptr);


        pharmacies.at(pharmacies.size() - 1)->addClient(new Client(nameC, addressC, taxN2));
    }
    cout << string(2, '\n') << "Pharmacy added successfully!" << string(2, '\n');
}

void Company::removePharmacy() {
    string name;
    bool removed = false;

    cout << "Insert pharmacy name: ";
    cin.ignore(1000, '\n');
    getline(cin, name);

    for (int i = 0; i < pharmacies.size(); ++i) {

        if (pharmacies.at(i)->getName() == name) {

            pharmacies.erase(pharmacies.begin() + i);
            cout << endl << name << " pharmacy erased successfully!" << endl;
            removed = true;
        }
    }

    if (!removed) {
        cout << endl << "ERROR: There is no pharmacy with the given name!" << string(4, '\n');
    }
}

void Company::comparePharmacies(Pharmacy *p1, Pharmacy *p2) {
    unsigned long sizeE, sizeE1, sizeE2, sizeC, sizeC1, sizeC2;

    cout << string(100, '\n') << left;
    cout << "COMPARE PHARMACIES:" << endl << endl;
    cout << "|NAME:        | " << setw(25) << p1->getName() << " | " << setw(25) << p2->getName() << " |" << endl;
    cout << string(69, '-') << endl;
    cout << "|ADDRESS:     | " << setw(25) << p1->getAddress() << "| " << setw(25) << p2->getAddress() << " |" << endl;
    cout << string(69, '-') << endl;
    cout << "|MANAGER:     | " << setw(25) << p1->getManager() << " | " << setw(25) << p2->getManager() << " |" << endl;
    cout << string(69, '-') << endl;
    cout << "|EMPLOYEES: | ";

    sizeE1 = p1->getEmployees().size();
    sizeE2 = p2->getEmployees().size();

    if (sizeE1 > sizeE2)
        sizeE = sizeE1;
    else
        sizeE = sizeE2;

    for (unsigned int i = 0; i < sizeE; i++) {
        if (i < sizeE1)
            cout << "|           | " << setw(25) << p1->getEmployees().at(i)->getName() << " | ";
        else
            cout << "|           | " << setw(28) << " | " << left;
        if (i < sizeE2)
            cout << setw(25) << p2->getEmployees().at(i)->getName() << " | " << endl;
        else
            cout << right << setw(28) << " | " << endl << left;
    }

    cout << string(69, '-') << endl;

    cout << "|CLIENTS: | ";

    sizeC1 = p1->getClients().size();
    sizeC2 = p2->getClients().size();

    if (sizeC1 > sizeE2)
        sizeC = sizeC1;
    else
        sizeC = sizeC2;

    for (unsigned int i = 0; i < sizeC; i++) {
        if (i < sizeC1)
            cout << "|           | " << setw(25) << p1->getClients().at(i)->getName() << " | ";
        else
            cout << "|           | " << setw(28) << " | " << left;
        if (i < sizeC2)
            cout << setw(25) << p2->getClients().at(i)->getName() << " | " << endl;
        else
            cout << right << setw(28) << " | " << endl << left;
    }

    cout << string(69, '-') << endl << endl;

}

void Company::updateFile() {

    ofstream file;
    file.open("/Users/mariajoaosenraviana/Desktop/untitled/PharmacyFile.txt");

    sort(pharmacies.begin(),pharmacies.end(),orderByName);

    for (auto &i: pharmacies) {
        i->writePharmacy(file);
    }

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
