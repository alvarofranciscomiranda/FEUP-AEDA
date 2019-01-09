#include "Company.h"
#include "Interfaces.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void Company::fireEmployee(){
	string name;
	Employee e = Employee();

	cout << "Which employee do you want to fire?" << endl;
	getline(cin, name);

	for(int i = 0; i < employees.size(); i++){
		if(employees[i]->getName() == name){
			e = (*employees[i]);
			employees.erase(employees.begin()+i);
			break;
		}
	}

	iteratorH it = formerEmployees.begin();

		while (it != formerEmployees.end()) {
			if (it->getName() == name) {
				it = formerEmployees.erase(it);
				e.setActualEmployee(false);
				formerEmployees.insert(e);
				break;
			}

			it++;
	}
}

void Company::hireBack(){
	string name;
	Employee e = Employee();

	//dar display de todos

	iteratorH it = formerEmployees.begin();

			while (it != formerEmployees.end()) {
				if(it->getActualEmployee() == false)
				it->displayPerson();
				it++;
			}


	cout << "Which employee do you want to hire?" << endl;
	cin.ignore(1000, '\n');
	getline(cin, name);

		 it = formerEmployees.begin();

				while (it != formerEmployees.end()) {
					if (it->getName() == name) {
						e = *it;
						it = formerEmployees.erase(it);
						e.setActualEmployee(true);
						formerEmployees.insert(e);
						employees.push_back(&e);
						break;
					}

					it++;
			}
}

void Company::openPharmacyFile(){
	unsigned long stop;
    ifstream pharmacyFile("pharmacyFile.txt");
    string pharmacy;
    string prods;
    unsigned int i = 0;

    //verify file is successfully opened
    if (pharmacyFile.is_open()) {
        while (!pharmacyFile.eof()) {

            getline(pharmacyFile, pharmacy);
            pharmacies.push_back(new Pharmacy(pharmacy));

            getline(pharmacyFile, prods);

            while(prods != ""){
            	cout << i;
            	stop = prods.find_first_of(';');
            	this->pharmacies.at(i)->addProduct(prods.substr(0, stop));
            	prods = prods.substr(stop + 1);
            }
            i++;
        }
    }

    pharmacyFile.close();

}

void Company::openEmployeesFile(){

	ifstream employeeFile("employees.txt");
    string employee;
	string prods;

    //verify file is successfully opened
    if (employeeFile.is_open()) {
        while (!employeeFile.eof()) {

            getline(employeeFile, employee);
            Employee * e = new Employee(employee);
            if(e->getActualEmployee())
            employees.push_back(e);
			formerEmployees.insert(*e);
        }
    }
    employeeFile.close();

}

void Company::openClientsFile(){

    ifstream clientFile("clients.txt");
    string client;

    //verify file is successfully opened
    if (clientFile.is_open()) {
        while (!clientFile.eof()) {

            getline(clientFile, client);
            Client c= Client(client);
            clients.insert(c);
        }
    }
    clientFile.close();

}

void Company::openProductsFile(){

    ifstream productFile("products.txt");
    string product;

    //verify file is successfully opened
    if (productFile.is_open()) {
      while (!productFile.eof()) {

          unsigned long stop; //stop is pos for last ';' found

           getline(productFile, product);

           stop = product.find_first_of('/');

           if(product.substr(0,stop) == "other"){
            	product = product.substr(stop+1);
            	Other * pre = new Other(product);
            	products.push_back(pre);
           }
           else if(product.substr(0,stop) == "medicine"){
            	product = product.substr(stop+1);
            	Medicine * pre = new Medicine(product);
            	products.push_back(pre);
            }
        }
    }
    productFile.close();
}

void Company::openRecipesFile(){
	ifstream recipesFile("recipes.txt");
	string recipes;
	string prods;
	string sods;

    //verify file is successfully opened
    if (recipesFile.is_open()) {
      while (!recipesFile.eof()) {
    	  vector<Product *> products;
    	  vector<Product *> sold;

          int stop; //stop is pos for first '/' found
          int stop2; //stop is pos for first '/' found

           getline(recipesFile, recipes);
           Recipe * p = new Recipe(recipes);


           //gets product
           getline(recipesFile, prods);
           while(prods != ""){
               stop = prods.find_first_of('/');

        	   if(prods.substr(0,stop) == "other"){
        		  prods = prods.substr(stop + 1);
        		  stop2 = prods.find_first_of(';');
        	      Other * pre = new Other(prods.substr(0, stop2));
        	      p->addProduct(pre);
        	   }
        	   else if(prods.substr(0,stop) == "medicine"){
        		  prods = prods.substr(stop+1);
        		  stop2 = prods.find_first_of(';');
        	      Medicine * pre = new Medicine(prods.substr(0, stop2 ));
        	      p->addProduct(pre);
        	   }

               stop2 = prods.find_first_of(';');
        	   prods = prods.substr(stop2+1);
           }

           //gets sold
           getline(recipesFile, sods);
        while(sods != ""){
             stop = sods.find_first_of('/');

             if(sods.substr(0,stop) == "other"){
            	 sods = sods.substr(stop + 1);
            	 stop2 = sods.find_first_of(';');
            	 Other * pre = new Other(sods.substr(0, stop2));
            	 p->addSold(pre);
             }
             else if(sods.substr(0,stop) == "medicine"){
            	 sods = sods.substr(stop+1);
            	 stop2 = sods.find_first_of(';');
            	 Medicine * pre = new Medicine(sods.substr(0, stop2 ));
            	 p->addSold(pre);
             }



           stop2 = sods.find_first_of(';');
           sods = sods.substr(stop2+1);
        }

        BSTItrIn<Client > it(clients);
          while(!it.isAtEnd()){
        	if(it.retrieve().getName() == p->getUser() && p->getSold().size() != 0){
               vector<int> quant;
               for(unsigned int j = 0; j < p->getSold().size(); j++ ){
                   quant.push_back(1);
               }
               Sales * sale = new Sales(p->getSold(), quant, Date("4/10/2018"));
               it.retrieve().addPurchases(sale);
               this->sales.push_back(sale);
            }
        	it.advance();
        }

         this->recipes.push_back(p);
        }
    }
    recipesFile.close();
}

void Company::openSalesFile(){
	ifstream recipesFile("sales.txt");
	string recipes;
	string prods;
	string sods;

	    //verify file is successfully opened
	    if (recipesFile.is_open()) {
	    	while (!recipesFile.eof()) {
	    		vector<Product *> products;
	        	vector<int> quant;

	              int stop; //stop is pos for first '/' found
	              int stop2; //stop is pos for first '/' found

	               getline(recipesFile, recipes);
	               Sales * s = new Sales(recipes);

	               //gets product
	               getline(recipesFile, prods);
	               while(prods != ""){
	                   stop = prods.find_first_of('/');

	            	   if(prods.substr(0,stop) == "other"){
	            		  prods = prods.substr(stop + 1);
	            		  stop2 = prods.find_first_of(';');
	            	      Other * pre = new Other(prods.substr(0, stop2));
	            	      s->addProductOnly(pre);
	            	   }
	            	   else if(prods.substr(0,stop) == "medicine"){
	            		  prods = prods.substr(stop+1);
	            		  stop2 = prods.find_first_of(';');
	            	      Medicine * pre = new Medicine(prods.substr(0, stop2 ));
	            	      s->addProductOnly(pre);
	            	   }

	                   stop2 = prods.find_first_of(';');
	            	   prods = prods.substr(stop2+1);
	               }

	            //gets quantity
	            getline(recipesFile, sods);
	            while(sods != ""){
	                 stop = sods.find_first_of(';');
	                 s->addQuantityOnly(stoi(sods.substr(0,stop)));
	                 sods = sods.substr(stop + 1);
	            }

	             sales.push_back(s);
	            }
	        }
	        recipesFile.close();
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

        employees.at(i)->displayPerson();

    }
    returnMainMenu();
}

void Company::displayClients() {

    ClearScreen();

    BSTItrIn<Client > it(clients);
      while(!it.isAtEnd()){

       it.retrieve().displayPerson();

       it.advance();
    }
    returnMainMenu();
}

void Company::displayProducts() {

    ClearScreen();

    for (unsigned int i = 0; i < products.size(); i++) {

        products.at(i)->printProductInfo();

    }
    returnMainMenu();
}

void Company::displayRecipes() {

    ClearScreen();

    for (unsigned int i = 0; i < recipes.size(); i++) {

        recipes.at(i)->printProductInfo();

    }
    returnMainMenu();
}

void Company::displaySales() {

    ClearScreen();

    for (unsigned int i = 0; i < sales.size(); i++) {

        sales.at(i)->printSalesInfo();

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


   void Company::searchClients() {

       string employee;

       ClearScreen();

       cout << "Insert the client of the pharmacy you wish to search for" << endl << ":::";
       cin.ignore(1000, '\n');
       getline(cin, employee);

       Client c =  Client(employee,"","",0);
       Client c2;
          c2=clients.find(c);
//          if(c2.getName()==undefined)
//          	throw-1;

        c2.displayPerson();

       ClearScreen();


       returnMainMenu();
   }
void Company::searchEmployees() {

    string employee;

    ClearScreen();

    cout << "Insert the employee of the pharmacy you wish to search for" << endl << ":::";
    cin.ignore(1000, '\n');
    getline(cin, employee);

    ClearScreen();

    for(unsigned int i = 0; i < pharmacies.size(); i++){
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

int Company::recipeExists(int code) {

    sort(recipes.begin(),recipes.end(),orderByRecipeNumber);

    int left = 0, right = recipes.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (recipes.at(middle)->getNumber() < code)
            left = middle + 1;
        else if (code < recipes.at(middle)->getNumber())
            right = middle - 1;
        else
            return middle; // encontrou
    }
    return -1; // não encontrou
}

int Company::salesExists(int code) {

    sort(sales.begin(),sales.end(),orderByDate);

    int left = 0, right = sales.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (sales.at(middle)->sales_id < code)
            left = middle + 1;
        else if (code < sales.at(middle)->sales_id)
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

        pharmacies.at(pharmacies.size() - 1)->addEmployee(new Employee(nameE, addressE, taxN, salaryE, nameE, postE, true));
    }

    cout << endl << "How many products would you like to add? " << endl << "::: ";
    cin >> employee;
    fail(employee);
    cin.ignore(1000, '\n');
    counter = 0;
    while (counter < employee) {
    	cout << endl << "Product " << ++counter << ": ";

    	cout << endl << "Product's name: ";
    	        getline(cin, nameE);

    	unsigned int c1 = 0;
    	for(unsigned int i = 0; i < this->products.size(); i++)
    		if(this->products.at(i)->getName() != nameE)
    			c1++;

    	if(c1 == this->products.size()){

    		addProducts();
    	}

    	pharmacies.at(pharmacies.size() - 1)->addProduct(nameE);
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
    if(this->pharmacyExists(pharmacy) == -1)
    	pharmacy = this->pharmacies.at(1)->getName();

    cout << endl << "Insert post: " << endl << "::: ";
    getline(cin, post);


    employees.push_back(new Employee(name, address, taxNumber, salary, pharmacy, post, true));
    this->pharmacies.at(this->pharmacyExists(pharmacy))->addEmployee(new Employee(name, address, taxNumber, salary, pharmacy, post, true));
    cout << string(2, '\n') << "Employee added successfully!" << string(2, '\n');
}

void Company::addClient() {
    string address, name, district;
    int taxNumber;

    cout << endl << "Insert name of the Client: " << endl << "::: ";
    cin.ignore(1000, '\n');
    getline(cin, name);
    Client* c = new Client(name,"","",0);

    cout << endl << "Insert district (eg: Braga): " << endl << "::: ";
    getline(cin, district);

    cout << endl << "Insert address (eg: Oeiras): " << endl << "::: ";
    getline(cin, address);

    cout << endl << "Insert tax Number " << endl << "::: ";
    cin >> taxNumber;
    fail(taxNumber);

    clients.insert( Client(name, district, address, taxNumber));

    cout << string(2, '\n') << "Client added successfully!" << string(2, '\n');
}

void Company::addProducts() {
    string code, name, description, type, prescription, needed;
    float price;
    int discount;
    bool n1 = false, n2 = false;

    while(type != "medicine" && type != "other"){
    	type == "";
    	cin.ignore(1000, '\n');
    	cout << endl << "Insert type of the product: " << endl << "::: ";
    	getline(cin, type);
    }

    cout << endl << "Insert code of the product: " << endl << "::: ";
    //cin.ignore(1000, '\n');
    getline(cin, code);
    if(productExists(code) != -1) { throw  -1;}

    cout << endl << "Insert name: " << endl << "::: ";
    getline(cin, name);

    cout << endl << "Insert price " << endl << "::: ";
    cin >> price;
    fail(price);

    cin.ignore(1000, '\n');
    cout << endl << "Insert description: " << endl << "::: ";
    getline(cin, description);

    if(type == "other"){
        products.push_back(new Other(name, code, price, description));
    }

    else if(type == "medicine"){

        while(prescription != "y" && prescription != "n"){
        	prescription = "";
        	//cin.ignore(1000, '\n');
        	cout << endl << "Insert if the medicine can be prescripted(y/n): " << endl << "::: ";
        	getline(cin, prescription);
        	cout << prescription << endl;
        }
        if(prescription != "n")
        	while(needed != "y" && needed != "n"){
        		needed = "";
        		//cin.ignore(1000, '\n');
        		cout << endl << "Insert if the recipe is obrigatory(y/n): " << endl << "::: ";
        		getline(cin, needed);
        	}

        cout << endl << "Insert price(0-100) " << endl << "::: ";
        cin >> discount;
        fail(discount);

        if(prescription == "y")
        	n1 = true;
        if(needed == "y")
            n2 = true;

        products.push_back(new Medicine(name, code, price, description, n1, n2, discount));
    }

    cout << string(2, '\n') << "Product added successfully!" << string(2, '\n');
}

void Company::addRecipe(){
	string user, medic;
	vector<Product*> product2;
	vector<Product*> sold2;
	int number = Recipe::id;
	int counter = 0, prods, sods;

	cin.ignore(1000, '\n');
	cout << endl << "Insert name of the user: " << endl << "::: ";
	getline(cin, user);

	cout << endl << "Insert name of the medic: " << endl << "::: ";
	getline(cin, medic);

	cout << endl << "How many products would you like to add? " << endl << "::: ";
	cin >> prods;
	fail(prods);
	cin.ignore(1000, '\n');
	counter = 0;

	while (counter < prods) {
		counter++;
		string code, name, description, type, prescription, needed;
		float price;
		int discount;
		bool n1 = false, n2 = false;

		while(type != "medicine" && type != "other"){
		   type == "";
		   cin.ignore(1000, '\n');
		   cout << endl << "Insert type of the product: " << endl << "::: ";
		   getline(cin, type);
		}

		cout << endl << "Insert code of the product: " << endl << "::: ";
		//cin.ignore(1000, '\n');
		getline(cin, code);
		if(productExists(code) != -1) { throw  -1;}

		cout << endl << "Insert name: " << endl << "::: ";
		getline(cin, name);

		cout << endl << "Insert price " << endl << "::: ";
		cin >> price;
		fail(price);

		cin.ignore(1000, '\n');
		cout << endl << "Insert description: " << endl << "::: ";
		getline(cin, description);

		if(type == "other"){
		    product2.push_back(new Other(name, code, price, description));
		}

		else if(type == "medicine"){

		    while(prescription != "y" && prescription != "n"){
		    	prescription = "";
		    	//cin.ignore(1000, '\n');
		        cout << endl << "Insert if the medicine can be prescripted(y/n): " << endl << "::: ";
		        getline(cin, prescription);
		        cout << prescription << endl;
		    }
		    if(prescription != "n")
		        while(needed != "y" && needed != "n"){
		        	needed = "";
		        	//cin.ignore(1000, '\n');
		        	cout << endl << "Insert if the recipe is obrigatory(y/n): " << endl << "::: ";
		        	getline(cin, needed);
		        }

		    cout << endl << "Insert price(0-100) " << endl << "::: ";
		    cin >> discount;
		    fail(discount);

		    if(prescription == "y")
		    	n1 = true;
		    if(needed == "y")
		        n2 = true;

		    product2.push_back(new Medicine(name, code, price, description, n1, n2, discount));
		}
	}

	cout << endl << "How many products would you like to add? " << endl << "::: ";
	cin >> sods;
	fail(sods);
	cin.ignore(1000, '\n');
	counter = 0;

	while (counter < sods) {
		counter++;
		string code, name, description, type, prescription, needed;
		float price;
		int discount;
		bool n1 = false, n2 = false;

		while(type != "medicine" && type != "other"){
			type == "";
			cin.ignore(1000, '\n');
			cout << endl << "Insert type of the product: " << endl << "::: ";
			getline(cin, type);
		}

		cout << endl << "Insert code of the product: " << endl << "::: ";
		//cin.ignore(1000, '\n');
		getline(cin, code);
		if(productExists(code) != -1) { throw  -1;}

		cout << endl << "Insert name: " << endl << "::: ";
		getline(cin, name);

		cout << endl << "Insert price " << endl << "::: ";
		cin >> price;
		fail(price);

		cin.ignore(1000, '\n');
		cout << endl << "Insert description: " << endl << "::: ";
		getline(cin, description);

		if(type == "other"){
			sold2.push_back(new Other(name, code, price, description));
		}

		else if(type == "medicine"){

			while(prescription != "y" && prescription != "n"){
			    prescription = "";
			    //cin.ignore(1000, '\n');
			    cout << endl << "Insert if the medicine can be prescripted(y/n): " << endl << "::: ";
			    getline(cin, prescription);
			    cout << prescription << endl;
			}
			if(prescription != "n")
			    while(needed != "y" && needed != "n"){
			    	needed = "";
			        //cin.ignore(1000, '\n');
			        cout << endl << "Insert if the recipe is obrigatory(y/n): " << endl << "::: ";
			        getline(cin, needed);
			    }

			cout << endl << "Insert price(0-100) " << endl << "::: ";
			cin >> discount;
			fail(discount);

			if(prescription == "y")
			    n1 = true;
			if(needed == "y")
			    n2 = true;

			sold2.push_back(new Medicine(name, code, price, description, n1, n2, discount));
		}
	}
	Recipe * re =  new Recipe(number, user, medic);
	re->setProducts(product2);
	re->setSold(sold2);
	this->recipes.push_back(re);
}

void Company::addSale(){
	int day2, month2, year2;
	vector<Product*> product2;
	vector<int> quants1;
	int counter = 0, prods, sods;

	cin.ignore(1000, '\n');
	cout << endl << "Insert day of the sale: " << endl << "::: ";
	cin >> day2;
	fail(day2);

	cin.ignore(1000, '\n');
	cout << endl << "Insert month of the sale: " << endl << "::: ";
	cin >> month2;
	fail(month2);
	cin.ignore(1000, '\n');

	cout << endl << "Insert year of the sale: " << endl << "::: ";
	cin >> year2;
	fail(year2);

	cin.ignore(1000, '\n');
	cout << endl << "How many products would you like to add? " << endl << "::: ";
	cin >> prods;
	fail(prods);

	counter = 0;
	while (counter < prods) {
		counter++;
		string code, name, description, type, prescription, needed;
		float price;
		int discount;
		bool n1 = false, n2 = false;

		while(type != "medicine" && type != "other"){
			type == "";
			cin.ignore(1000, '\n');
			cout << endl << "Insert type of the product: " << endl << "::: ";
			getline(cin, type);
		}

		cout << endl << "Insert code of the product: " << endl << "::: ";
		//cin.ignore(1000, '\n');
		getline(cin, code);
		if(productExists(code) != -1) { throw  -1;}

		cout << endl << "Insert name: " << endl << "::: ";
		getline(cin, name);

		cout << endl << "Insert price " << endl << "::: ";
		cin >> price;
		fail(price);

		cin.ignore(1000, '\n');
		cout << endl << "Insert description: " << endl << "::: ";
		getline(cin, description);

		if(type == "other"){
			product2.push_back(new Other(name, code, price, description));
		}

		else if(type == "medicine"){

			while(prescription != "y" && prescription != "n"){
			    prescription = "";
			    //cin.ignore(1000, '\n');
			    cout << endl << "Insert if the medicine can be prescripted(y/n): " << endl << "::: ";
			    getline(cin, prescription);
			    cout << prescription << endl;
			}
			if(prescription != "n")
			    while(needed != "y" && needed != "n"){
			        needed = "";
			        //cin.ignore(1000, '\n');
			        cout << endl << "Insert if the recipe is obrigatory(y/n): " << endl << "::: ";
			        getline(cin, needed);
			    }

			cout << endl << "Insert price(0-100) " << endl << "::: ";
			cin >> discount;
			fail(discount);

			if(prescription == "y")
			    n1 = true;
			if(needed == "y")
			    n2 = true;

			product2.push_back(new Medicine(name, code, price, description, n1, n2, discount));
		}
	}

	while (counter > 0) {
		counter--;

		cin.ignore(1000, '\n');
		cout << endl << "Quantitie of the i introduzed product? " << endl << "::: ";
		cin >> sods;
		fail(sods);

		quants1.push_back(sods);
	}

	Sales * sa =  new Sales(product2, quants1, Date(day2, month2, year2));
	this->sales.push_back(sa);
}

void Company::removePharmacy(){
    string name;
    bool removed = false;

    cin.ignore(1000, '\n');
    cout << "Insert pharmacy name: " << endl;
    getline(cin, name);

    for (unsigned int i = 0; i < pharmacies.size(); ++i) {

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

    cin.ignore(1000, '\n');
    cout << "Insert employee name: " << endl;
    getline(cin, name);

    for (unsigned int i = 0; i < employees.size(); ++i) {

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

    cin.ignore(1000, '\n');
    cout << "Insert client name: " << endl;
    getline(cin, name);
    BSTItrIn<Client > it(clients);
   while(!it.isAtEnd()){

        if (it.retrieve().getName() == name) {

            clients.remove(it.retrieve());
            cout << endl << name << " client erased successfully!" << endl;
            removed = true;
        }
        it.advance();
    }

    if (!removed) {
        cout << endl << "ERROR: There is no client with the given name!" << string(4, '\n');
    }
}

void Company::removeProduct() {
    string code;
    bool removed = false;

    cin.ignore(1000, '\n');
    cout << "Insert product code: " << endl;
    getline(cin, code);

    for (unsigned int i = 0; i < products.size(); ++i) {

        if (products.at(i)->getCode() == code) {

            products.erase(products.begin() + i);
            cout << endl << code << " product erased successfully!" << endl;
            removed = true;
        }
    }

    if (!removed) {
        cout << endl << "ERROR: There is no product with the given code!" << string(4, '\n');
    }
}

void Company::removeRecipe(){
	string code;
	int number;
	bool removed = false;

	cin.ignore(1000, '\n');
	cout << "Insert recipe number: " << endl;
	cin >> number;

	for (unsigned int i = 0; i < recipes.size(); ++i) {

	   if (recipes.at(i)->getNumber() == number) {

	        recipes.erase(recipes.begin() + i);
	        cout << endl << code << " recipe erased successfully!" << endl;
	        removed = true;
	     }
	 }

	 if (!removed) {
	    cout << endl << "ERROR: There is no Recipe with the given number!" << string(4, '\n');
	 }
}

void Company::removeSale(){
	string code;
	int number;
	bool removed = false;

	cin.ignore(1000, '\n');
	cout << "Insert sales number: " << endl;
	cin >> number;

	for (unsigned int i = 0; i < sales.size(); ++i) {

		if (sales.at(i)->sale_id == number) {

			sales.erase(sales.begin() + i);
		    cout << endl << code << " sales erased successfully!" << endl;
		    removed = true;
		}
	}

	if (!removed) {
		cout << endl << "ERROR: There is no Sales with the given id!" << string(4, '\n');
	}
}

void Company::removeAllPharmacys(){
	this->pharmacies.clear();
}

void Company::removeAllEmployees(){
	this->employees.clear();
}

void Company::removeAllClients(){
	this->clients.makeEmpty();
}

void Company::removeAllProducts(){
	this->products.clear();
}

void Company::removeAllRecipes(){
	this->recipes.clear();
}

void Company::removeAllSales(){
	this->sales.clear();
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
}

void Company::updatePharmacyFile() {

	ofstream pharmacyFile("pharmacyFile.txt");

    sort(pharmacies.begin(),pharmacies.end(),orderByNamePharmacy);

    for (unsigned int i = 0; i < pharmacies.size(); i++) {
        pharmacies[i]->writePharmacy(pharmacyFile);
        if(i!=pharmacies.size()-1)
        pharmacyFile << endl;
    }


}

void Company::updateEmployeeFile() {

    ofstream employeesFile("employees.txt");

    iteratorH it = formerEmployees.begin();

    			while (it != formerEmployees.end()) {
    				it->printSimplifiedInfo(employeesFile);
    				employeesFile << endl;
    				it++;
    			}
}

void Company::updateClientFile() {

    ofstream clientsFile("clients.txt");
int i=0;

BSTItrIn<Client> it(clients);
  while(!it.isAtEnd()){

        it.retrieve().printSimplifiedInfo(clientsFile);
        if(!it.isAtEnd())
        clientsFile << endl;
        i++;
        it.advance();
    }


}

void Company::updateProductFile() {

   ofstream clientsFile("products.txt");

   sort(products.begin(), products.end(), orderByCodeProduct);

    for (unsigned int i = 0; i<products.size(); i++) {
        products[i]->printSimplifiedInfo(clientsFile);
        if(i!=products.size()-1)
        	clientsFile << endl;
    }

}

void Company::updateRecipeFile() {

   ofstream recipesFile("recipes.txt");

   sort(recipes.begin(), recipes.end(), orderByRecipeNumber);

    for (unsigned int i = 0; i<recipes.size(); i++) {
        recipes[i]->printSimplifiedInfo(recipesFile);
        if(i!=recipes.size()-1)
        	recipesFile << endl;
    }

}

void Company::updateSalesFile(){
	ofstream salesFile("sales.txt");

	sort(sales.begin(), sales.end(), orderByDate);

	 for (unsigned int i = 0; i<sales.size(); i++) {
		 sales[i]->printSimplifiedInfo(salesFile);
	     if(i != sales.size()- 1)
	        salesFile << endl;
	 }
}

bool orderByNamePharmacy(Pharmacy *p1, Pharmacy *p2){

    if(p1->getName() < p2->getName()) return true;
    else if(p1->getName() > p2->getName()) return false;
    return false;
}

bool orderByNameManager(Pharmacy *p1, Pharmacy *p2){

     if(p1->getManager() < p2->getManager()) return true;
     else if(p1->getManager() > p2->getManager()) return false;
     return false;
 }

bool orderByNameAddress(Pharmacy *p1, Pharmacy *p2){

    if(p1->getAddress() < p2->getAddress()) return true;
    else if(p1->getAddress() > p2->getAddress()) return false;
    return false;
}

bool orderByNameEmployee(Employee *p1, Employee *p2){

    if(p1->getName() < p2->getName()) return true;
    else if(p1->getName() > p2->getName()) return false;
    return false;
}

bool orderByNameClient(Client *p1, Client *p2) {

    if (p1->getName() < p2->getName()) return true;
    else if (p1->getName() > p2->getName()) return false;
    return false;
}

bool orderByCodeProduct(Product *p1, Product *p2){

    if(p1->getCode() < p2->getCode()) return true;
    else if(p1->getCode() > p2->getCode()) return false;
    return false;
}

bool orderByRecipeNumber(Recipe *p1, Recipe *p2){

    if(p1->getNumber() < p2->getNumber()) return true;
    else if(p1->getNumber() > p2->getNumber()) return false;

    return false;
}

bool orderByDate(Sales *p1, Sales *p2){
	if(p1->getDate().getYear() < p2->getDate().getYear())
		return true;
	else if(p1->getDate().getYear() > p2->getDate().getYear())
		return false;
	else if(p1->getDate().getMonth() < p2->getDate().getMonth())
		return true;
	else if(p1->getDate().getMonth() > p2->getDate().getMonth())
		return false;
	else if(p1->getDate().getDay() < p2->getDate().getDay())
		return true;
	else if(p1->getDate().getDay() > p2->getDate().getDay())
		return false;

	return false;
}

