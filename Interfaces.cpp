#include <iostream>
#include <iomanip>
#include <algorithm>

#include "Interfaces.h"

using namespace std;

void returnMainMenu() {
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

bool ValidMenuInput(int lowerL, int upperL, int input) {
	if (input <= upperL && input >= lowerL)
		return true;
	else
		return false;
}

void mainMenu(Company &company) {

	int option;

	cout << " MAIN MENU" << setw(40) << setfill(' ') << " " << endl;
	cout << setfill('-') << setw(50) << "-" << endl;
	cout << "1. Display" << endl;
	cout << "2. Search pharmacy" << endl;
	cout << "3. Compare pharmacies" << endl;
	cout << "4. Add or remove" << endl;
	cout << "5. Update files." << endl;
	cout << "6. Hire back or fire employees." << endl;

	cout << endl << "Enter a number option: " << endl << "::: ";
	cin >> option;

	//verifies if input is valid
	while (cin.fail() || !ValidMenuInput(1, 6, option)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a valid option: " << endl << "::: ";
		cin >> option;
	}

	//redirect to next menu
	switch (option) {
	case 1:
		displayMenu(company);
		ClearScreen();
		mainMenu(company);
		break;
	case 2:
		searchMenu(company);
		ClearScreen();
		mainMenu(company);
		break;
	case 3:
		compareMenu(company);
		ClearScreen();
		mainMenu(company);
		break;
	case 4:
		AddAlterRemoveMenu(company);
		ClearScreen();
		break;
	case 5:
		updateFileMenu(company);
		ClearScreen();
		mainMenu(company);
		break;
	case 6:
		hireFireMenu(company);
		ClearScreen();
		mainMenu(company);
		break;
	}
}

void ClearScreen() {

	cout << string(50, '\n');
}

void displayMenu(Company &company) {
	int option;

	cout << string(100, '\n');
	cout << " DISPLAY" << setw(37) << setfill(' ') << " " << endl;
	cout << setfill('-') << setw(47) << "-" << endl;
	cout << "1. Display all Pharmacies" << endl;
	cout << "2. Display all Employees" << endl;
	cout << "3. Display all Clients" << endl;
	cout << "4. Display all Products" << endl;
	cout << "5. Display all Recipes" << endl;
	cout << "6. Display all Sales" << endl;

	cout << endl << "Enter a number option: ";
	cin >> option;

	//verifies if input is valid
	while (cin.fail() || !ValidMenuInput(1, 6, option)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a valid option: ";
		cin >> option;
	}

	switch (option) {

	case 1:
		company.displayPharmacies();
		break;
	case 2:
		company.displayEmployees();
		break;
	case 3:
		company.displayClients();
		break;
	case 4:
		company.displayProducts();
		break;
	case 5:
		company.displayRecipes();
		break;
	case 6:
		company.displaySales();
		break;
	}

}

void searchMenu(Company &company) {
	int option;

	// cout << string(100,'\n');
	cout << " SEARCH PHARMACY" << setw(37) << setfill(' ') << " " << endl;
	cout << setfill('-') << setw(47) << "-" << endl;
	cout << "1. Search by name" << endl;
	cout << "2. Search by address" << endl;
	cout << "3. Search by manager" << endl;
	cout << "4. Search by employee" << endl;

	cout << endl << "Enter a number option: ";
	cin >> option;

	//verifies if input is valid
	while (cin.fail() || !ValidMenuInput(1, 4, option)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a valid option: ";
		cin >> option;
	}

	switch (option) {

	case 1:
		company.searchPharmacyName();
		break;
	case 2:
		company.searchAddress();
		break;
	case 3:
		company.searchManager();
		break;
	case 4:
		company.searchEmployees();
		break;
	}

}

void AddAlterRemoveMenu(Company &company) {

	int option;

	cout << string(100, '\n');
	cout << " ALTER FILES" << setw(37) << setfill(' ') << " " << endl;
	cout << setfill('-') << setw(47) << "-" << endl;
	cout << "1. Add, remove pharmacy" << endl;
	cout << "2. Add, remove employee" << endl;
	cout << "3. Add, remove client" << endl;
	cout << "4. Add, remove product" << endl;
	cout << "5. Add, remove recipe" << endl;
	cout << "6. Add, remove sales" << endl;
	cout << "7. Return to main menu" << endl;

	cout << endl << "Enter a number option: " << endl << "::: ";
	cin >> option;

	//verifies if input is valid
	while (cin.fail() || !ValidMenuInput(1, 7, option)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a valid option: " << endl << "::: ";
		cin >> option;
	}

	switch (option) {
	case 1:
		AddAlterRemoveMenuPharmacy(company);
		returnMainMenu();
		ClearScreen();
		mainMenu(company);
		break;
	case 2:
		AddAlterRemoveMenuEmployee(company);
		returnMainMenu();
		ClearScreen();
		mainMenu(company);
		break;
	case 3:
		AddAlterRemoveMenuClient(company);
		ClearScreen();
		mainMenu(company);
		break;
	case 4:
		AddAlterRemoveMenuProduct(company);
		ClearScreen();
		mainMenu(company);
		break;
	case 5:
		AddAlterRemoveMenuRecipe(company);
		ClearScreen();
		mainMenu(company);
		break;
	case 6:
		AddAlterRemoveMenuSales(company);
		ClearScreen();
		mainMenu(company);
		break;
	case 7:
		ClearScreen();
		mainMenu(company);
		break;
	}
}

void AddAlterRemoveMenuPharmacy(Company &company) {

	int option;

	cout << string(100, '\n');
	cout << " ALTER PHARMACY FILE" << setw(37) << setfill(' ') << " " << endl;
	cout << setfill('-') << setw(47) << "-" << endl;
	cout << "1. Add pharmacy" << endl;
	cout << "2. Remove pharmacy" << endl;
	cout << "3. Remove all pharmacys" << endl;
	cout << "4. Return to main menu" << endl;

	cout << endl << "Enter a number option: " << endl << "::: ";
	cin >> option;

	//verifies if input is valid
	while (cin.fail() || !ValidMenuInput(1, 3, option)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a valid option: " << endl << "::: ";
		cin >> option;
	}

	switch (option) {
	case 1:
		try {
			company.addPharmacy();
		} catch (int x) {
			cout << endl << "ERROR: Pharmacy already exists!" << endl;
		}
		returnMainMenu();
		ClearScreen();
		mainMenu(company);
		break;
	case 2:
		company.removePharmacy();
		ClearScreen();
		mainMenu(company);
		break;
	case 3:
		company.removeAllPharmacys();
		ClearScreen();
		mainMenu(company);
		break;
	case 4:
		ClearScreen();
		mainMenu(company);
		break;
	}
}

void AddAlterRemoveMenuEmployee(Company &company) {

	int option;

	cout << string(100, '\n');
	cout << " ALTER EMPLOYEE FILE" << setw(37) << setfill(' ') << " " << endl;
	cout << setfill('-') << setw(47) << "-" << endl;
	cout << "1. Add employee" << endl;
	cout << "2. Remove employee" << endl;
	cout << "3. Remove all employees" << endl;
	cout << "4. Return to main menu" << endl;

	cout << endl << "Enter a number option: " << endl << "::: ";
	cin >> option;

	//verifies if input is valid
	while (cin.fail() || !ValidMenuInput(1, 4, option)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a valid option: " << endl << "::: ";
		cin >> option;
	}

	switch (option) {
	case 1:
		try {
			company.addEmployee();
		} catch (int x) {
			cout << endl << "ERROR: Employee already exists!" << endl;
		}
		returnMainMenu();
		ClearScreen();
		mainMenu(company);
		break;
	case 2:
		company.removeEmployee();
		ClearScreen();
		mainMenu(company);
		break;
	case 3:
		company.removeAllEmployees();
		ClearScreen();
		mainMenu(company);
		break;
	case 4:
		ClearScreen();
		mainMenu(company);
		break;
	}
}

void AddAlterRemoveMenuClient(Company &company) {

	int option;

	cout << string(100, '\n');
	cout << " ALTER CLIENT FILE" << setw(37) << setfill(' ') << " " << endl;
	cout << setfill('-') << setw(47) << "-" << endl;
	cout << "1. Add client" << endl;
	cout << "2. Remove client" << endl;
	cout << "3. Remove all clients" << endl;
	cout << "4. Return to main menu" << endl;

	cout << endl << "Enter a number option: " << endl << "::: ";
	cin >> option;

	//verifies if input is valid
	while (cin.fail() || !ValidMenuInput(1, 4, option)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a valid option: " << endl << "::: ";
		cin >> option;
	}

	switch (option) {
	case 1:
		try {
			company.addClient();
		} catch (int x) {
			cout << endl << "ERROR: Client already exists!" << endl;
		}
		returnMainMenu();
		ClearScreen();
		mainMenu(company);
		break;
	case 2:
		company.removeClient();
		ClearScreen();
		mainMenu(company);
		break;
	case 3:
		company.removeAllClients();
		ClearScreen();
		mainMenu(company);
		break;
	case 4:
		ClearScreen();
		mainMenu(company);
		break;
	}
}

void AddAlterRemoveMenuProduct(Company &company) {

	int option;

	cout << string(100, '\n');
	cout << " ALTER PRODUCT FILE" << setw(37) << setfill(' ') << " " << endl;
	cout << setfill('-') << setw(47) << "-" << endl;
	cout << "1. Add product" << endl;
	cout << "2. Remove product" << endl;
	cout << "3. Remove all products" << endl;
	cout << "4. Return to main menu" << endl;

	cout << endl << "Enter a number option: " << endl << "::: ";
	cin >> option;

	//verifies if input is valid
	while (cin.fail() || !ValidMenuInput(1, 4, option)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a valid option: " << endl << "::: ";
		cin >> option;
	}

	switch (option) {
	case 1:
		try {
			company.addProducts();
		} catch (int x) {
			cout << endl << "ERROR: Products already exists!" << endl;
		}
		returnMainMenu();
		ClearScreen();
		mainMenu(company);
		break;
	case 2:
		company.removeProduct();
		ClearScreen();
		mainMenu(company);
		break;
	case 3:
		company.removeAllProducts();
		ClearScreen();
		mainMenu(company);
		break;
	case 4:
		ClearScreen();
		mainMenu(company);
		break;
	}
}

void AddAlterRemoveMenuRecipe(Company &company) {

	int option;

	cout << string(100, '\n');
	cout << " ALTER RECIPE FILE" << setw(37) << setfill(' ') << " " << endl;
	cout << setfill('-') << setw(47) << "-" << endl;
	cout << "1. Add recipe" << endl;
	cout << "2. Remove recipe" << endl;
	cout << "3. Remove all recipes" << endl;
	cout << "4. Return to main menu" << endl;

	cout << endl << "Enter a number option: " << endl << "::: ";
	cin >> option;

	//verifies if input is valid
	while (cin.fail() || !ValidMenuInput(1, 4, option)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a valid option: " << endl << "::: ";
		cin >> option;
	}

	switch (option) {
	case 1:
		try {
			company.addRecipe();
		} catch (int x) {
			cout << endl << "ERROR: Products already exists!" << endl;
		}
		returnMainMenu();
		ClearScreen();
		mainMenu(company);
		break;
	case 2:
		company.removeRecipe();
		ClearScreen();
		mainMenu(company);
		break;
	case 3:
		company.removeAllRecipes();
		ClearScreen();
		mainMenu(company);
		break;
	case 4:
		ClearScreen();
		mainMenu(company);
		break;
	}
}

void AddAlterRemoveMenuSales(Company &company) {

	int option;

	cout << string(100, '\n');
	cout << " ALTER SALES FILE" << setw(37) << setfill(' ') << " " << endl;
	cout << setfill('-') << setw(47) << "-" << endl;
	cout << "1. Add sale" << endl;
	cout << "2. Remove sale" << endl;
	cout << "3. Remove all sales" << endl;
	cout << "4. Return to main menu" << endl;

	cout << endl << "Enter a number option: " << endl << "::: ";
	cin >> option;

	//verifies if input is valid
	while (cin.fail() || !ValidMenuInput(1, 4, option)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a valid option: " << endl << "::: ";
		cin >> option;
	}

	switch (option) {
	case 1:
		try {
			company.addSale();
		} catch (int x) {
			cout << endl << "ERROR: Products already exists!" << endl;
		}
		returnMainMenu();
		ClearScreen();
		mainMenu(company);
		break;
	case 2:
		company.removeSale();
		ClearScreen();
		mainMenu(company);
		break;
	case 3:
		company.removeAllSales();
		ClearScreen();
		mainMenu(company);
		break;
	case 4:
		ClearScreen();
		mainMenu(company);
		break;
	}
}

void updateFileMenu(Company &company) {
	int option;

	cout << string(100, '\n');
	cout << " UPDATE" << setw(37) << setfill(' ') << " " << endl;
	cout << setfill('-') << setw(47) << "-" << endl;
	cout << "1. Update Pharmacies File" << endl;
	cout << "2. Update Employees File" << endl;
	cout << "3. Update Clients File" << endl;
	cout << "4. Update products File" << endl;
	cout << "5. Update recipes File" << endl;
	cout << "6. Update sales File" << endl;

	cout << endl << "Enter a number option: ";
	cin >> option;

	//verifies if input is valid
	while (cin.fail() || !ValidMenuInput(1, 6, option)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a valid option: ";
		cin >> option;
	}

	switch (option) {

	case 1:
		company.updatePharmacyFile();
		break;
	case 2:
		company.updateEmployeeFile();
		break;
	case 3:
		company.updateClientFile();
		break;
	case 4:
		company.updateProductFile();
		break;
	case 5:
		company.updateRecipeFile();
		break;
	case 6:
		company.updateSalesFile();
		break;
	}
}

void hireFireMenu(Company &company) {
	int option;

	cout << string(100, '\n');
	cout << " HIRE OR FIRE??" << setw(37) << setfill(' ') << " " << endl;
	cout << setfill('-') << setw(47) << "-" << endl;
	cout << "1. Hire an employee" << endl;
	cout << "2. Fire an employee" << endl;

	cout << endl << "Enter a number option: ";
	cin >> option;

	//verifies if input is valid
	while (cin.fail() || !ValidMenuInput(1, 2, option)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a valid option: ";
		cin >> option;
	}

	switch (option) {

	case 1:
		company.hireBack();
		break;
	case 2:
		company.fireEmployee();
		break;
	}
}

void compareMenu(Company &company) {

	string p1, p2;

	int ind1, ind2;

	cout << "Insert the name of the two pharmacies you wish to compare:" << endl
			<< ":::";
	cin.ignore(1000, '\n');
	getline(cin, p1);
	ind1 = company.pharmacyExists(p1);
	cout << ":::";
	getline(cin, p2);
	ind2 = company.pharmacyExists(p2);

	company.comparePharmacies(company.getPharmacies().at(ind1),
			company.getPharmacies().at(ind2));

	returnMainMenu();
}
