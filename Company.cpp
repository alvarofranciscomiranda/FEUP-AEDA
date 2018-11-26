#include "Company.h"
#include "Interfaces.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

Company::Company() {

    openPharmacyFile();
    openEmployeesFile();
    openClientsFile();
    openProductsFile();

}

void Company::openPharmacyFile(){

    ifstream pharmacyFile("/Users/mariajoaosenraviana/Desktop/untitled/PharmacyFile.txt");
    string pharmacy;

    //verify file is successfully opened

    if (pharmacyFile.is_open()) {
        while (!pharmacyFile.eof()) {

            getline(pharmacyFile, pharmacy);
            pharmacies.push_back(new Pharmacy(pharmacy));
        }
    }

    pharmacyFile.close();

}

void Company::openEmployeesFile(){

    ifstream employeeFile("/Users/mariajoaosenraviana/Desktop/untitled/Employees.txt");
    string employee;

    //verify file is successfully opened

    if (employeeFile.is_open()) {
        while (!employeeFile.eof()) {

            getline(employeeFile, employee);
            employees.push_back(new Employee(employee));
        }
    }

    employeeFile.close();

}

void Company::openClientsFile(){

    ifstream clientFile("/Users/mariajoaosenraviana/Desktop/untitled/Clients.txt");
    string client;

    //verify file is successfully opened

    if (clientFile.is_open()) {
        while (!clientFile.eof()) {

            getline(clientFile, client);
            clients.push_back(new Client(client));
        }
    }

    clientFile.close();

}

void Company::openProductsFile(){

    ifstream productFile("/Users/mariajoaosenraviana/Desktop/untitled/Products.txt");
    string product;

    //verify file is successfully opened

    if (productFile.is_open()) {
        while (!productFile.eof()) {

            getline(productFile, product);
            products.push_back(new Product(product));
        }
    }

    productFile.close();

}

void Company::displayPharmacies() {

    ClearScreen();

    for (unsigned int i = 0; i < pharmacies.size(); i++) {

         pharmacies.at(i)->displayPharmacy();

    }
    returnMainMenu();
}

void Company::displayEmployees() {

    ClearScreen();

    for (unsigned int i = 0; i < employees.size(); i++) {

        employees.at(i)->displayEmployee();

    }
    returnMainMenu();
}

void Company::displayClients() {

    ClearScreen();

    for (unsigned int i = 0; i < clients.size(); i++) {

        clients.at(i)->displayClient();

    }
    returnMainMenu();
}

void Company::displayProducts() {

    ClearScreen();

    for (unsigned int i = 0; i < products.size(); i++) {

        products.at(i)->displayProduct();

    }
    returnMainMenu();
}

void Company::searchPharmacyName() {

    string name;

    ClearScreen();

    sort(pharmacies.begin(),pharmacies.end(), orderByNamePharmacy);

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

    sort(pharmacies.begin(),pharmacies.end(),orderByNamePharmacy);

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

int Company::employeeExists(string name) {

    sort(employees.begin(),employees.end(),orderByNameEmployee);

    int left = 0, right = employees.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (employees.at(middle)->getName() < name)
            left = middle + 1;
        else if (name < employees.at(middle)->getName())
            right = middle - 1;
        else
            return middle; // encontrou
    }
    return -1; // não encontrou
}

int Company::clientExists(string name) {

    sort(clients.begin(),clients.end(),orderByNameClient);

    int left = 0, right = clients.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (clients.at(middle)->getName() < name)
            left = middle + 1;
        else if (name < clients.at(middle)->getName())
            right = middle - 1;
        else
            return middle; // encontrou
    }
    return -1; // não encontrou
}

int Company::productExists(string code) {

    sort(products.begin(),products.end(),orderByCodeProduct);

    int left = 0, right = products.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (products.at(middle)->getCode() < code)
            left = middle + 1;
        else if (code < products.at(middle)->getCode())
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

void Company::addEmployee() {
    string address, name, pharmacy, post;
    int taxNumber;
    float salary;

    cout << endl << "Insert name of the Employee: " << endl << "::: ";
    cin.ignore(1000, '\n');
    getline(cin, name);
    if(employeeExists(name) != -1) { throw  -1;}

    cout << endl << "Insert address (eg: Oeiras): " << endl << "::: ";
    getline(cin, address);

    cout << endl << "Insert tax Number " << endl << "::: ";
    cin >> taxNumber;
    fail(taxNumber);

    cout << endl << "Insert salary " << endl << "::: ";
    cin >> salary;
    fail(salary);

    cout << endl << "Insert pharmacy: " << endl << "::: ";
    getline(cin, pharmacy);

    cout << endl << "Insert post: " << endl << "::: ";
    getline(cin, post);


    employees.push_back(new Employee(name, address, taxNumber, salary, pharmacy, post));

    cout << string(2, '\n') << "Employee added successfully!" << string(2, '\n');
}

void Company::addClient() {
    string address, name;
    int taxNumber;

    cout << endl << "Insert name of the Client: " << endl << "::: ";
    cin.ignore(1000, '\n');
    getline(cin, name);
    if(clientExists(name) != -1) { throw  -1;}

    cout << endl << "Insert address (eg: Oeiras): " << endl << "::: ";
    getline(cin, address);

    cout << endl << "Insert tax Number " << endl << "::: ";
    cin >> taxNumber;
    fail(taxNumber);

    clients.push_back(new Client(name, address, taxNumber));

    cout << string(2, '\n') << "Client added successfully!" << string(2, '\n');
}

void Company::addProducts() {
    string code, name, description;
    float price;

    cout << endl << "Insert code of the product: " << endl << "::: ";
    cin.ignore(1000, '\n');
    getline(cin, code);
    if(productExists(code) != -1) { throw  -1;}

    cout << endl << "Insert name: " << endl << "::: ";
    getline(cin, name);

    cout << endl << "Insert price " << endl << "::: ";
    cin >> price;
    fail(price);

    cout << endl << "Insert description: " << endl << "::: ";
    getline(cin, description);


    products.push_back(new Product(code, name, price, description));

    cout << string(2, '\n') << "Employee added successfully!" << string(2, '\n');
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

void Company::removeEmployee() {
    string name;
    bool removed = false;

    cout << "Insert employee name: ";
    cin.ignore(1000, '\n');
    getline(cin, name);

    for (int i = 0; i < employees.size(); ++i) {

        if (employees.at(i)->getName() == name) {

            employees.erase(employees.begin() + i);
            cout << endl << name << " employee erased successfully!" << endl;
            removed = true;
        }
    }

    if (!removed) {
        cout << endl << "ERROR: There is no employee with the given name!" << string(4, '\n');
    }
}

void Company::removeClient() {
    string name;
    bool removed = false;

    cout << "Insert client name: ";
    cin.ignore(1000, '\n');
    getline(cin, name);

    for (int i = 0; i < clients.size(); ++i) {

        if (clients.at(i)->getName() == name) {

            clients.erase(clients.begin() + i);
            cout << endl << name << " client erased successfully!" << endl;
            removed = true;
        }
    }

    if (!removed) {
        cout << endl << "ERROR: There is no client with the given name!" << string(4, '\n');
    }
}

void Company::removeProduct() {
    string code;
    bool removed = false;

    cout << "Insert product code: ";
    cin.ignore(1000, '\n');
    getline(cin, code);

    for (int i = 0; i < products.size(); ++i) {

        if (products.at(i)->getName() == code) {

            products.erase(products.begin() + i);
            cout << endl << code << " product erased successfully!" << endl;
            removed = true;
        }
    }

    if (!removed) {
        cout << endl << "ERROR: There is no product with the given code!" << string(4, '\n');
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

void Company::updatePharmacyFile() {

    ofstream file;
    file.open("/Users/mariajoaosenraviana/Desktop/untitled/PharmacyFile.txt");

    sort(pharmacies.begin(),pharmacies.end(),orderByNamePharmacy);

    for (int i = 0; i < pharmacies.size(); i++) {
        pharmacies[i]->writePharmacy(file);
        if(i!=pharmacies.size()-1)
        file << endl;
    }


}

void Company::updateEmployeeFile() {

    ofstream file;
    file.open("/Users/mariajoaosenraviana/Desktop/untitled/Employees.txt");

    sort(employees.begin(),employees.end(),orderByNameEmployee);

    for (int i = 0; i<employees.size(); i++) {
        employees[i]->writeEmployee(file);
        if(i!=employees.size()-1)
            file << endl;
    }

}

void Company::updateClientFile() {

    ofstream file;
    file.open("/Users/mariajoaosenraviana/Desktop/untitled/Clients.txt");

    sort(clients.begin(),clients.end(),orderByNameClient);

    for (int i = 0; i<clients.size(); i++) {
        clients[i]->writeClient(file);
        if(i!=clients.size()-1)
            file << endl;
    }

}

void Company::updateProductFile() {

    ofstream file;
    file.open("/Users/mariajoaosenraviana/Desktop/untitled/Products.txt");

   sort(products.begin(), products.end(), orderByCodeProduct);

    for (int i = 0; i<products.size(); i++) {
        products[i]->writeProduct(file);
        if(i!=products.size()-1)
            file << endl;
    }

}

bool orderByNamePharmacy(Pharmacy *p1, Pharmacy *p2){

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

bool orderByCodeProduct(Product *p1, Product *p2){

    if(p1->getCode() < p2->getCode()) return true;
    else if(p1->getCode() > p2->getCode()) return false;
}

