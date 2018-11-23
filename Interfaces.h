#ifndef UNTITLED_INTERFACES_H
#define UNTITLED_INTERFACES_H
#include <iostream>
#include "Company.h"


/**
 * @brief Redirects to main menu when user enters 0.
 */
void returnMainMenu();

/**
 * @brief Verifies if input given by user is between lowerL and upperL.
 * @param lowest input int possible
 * @param highest input int possible
 * @param input entered by user
 * @return 0 if success, 1 otherwise
 */
bool ValidMenuInput(int lowerL, int upperL, int input);

/**
 * @brief Main menu that allows user to choose a topic to take action in.
 * @param company
 */
void mainMenu(Company &company);

/**
 * @brief Clears screen.
 */
void ClearScreen();

/**
 * @brief Sub-menu from main menu that allows user to choose actions relating to the display of a determinate pharmacy.
 * @param company
 */
void displayMenu(Company &company);

/**
 * @brief Sub-menu from main menu that allows user to choose actions relating to the search of a determinate pharmacy.
 * @param company
 */
void searchMenu(Company &company);

/**
 * @brief Sub-menu from main menu that allows user to choose actions relating altering informarion about a pharmacy, adding or removing pharmacies.
 * @param company
 */
void AddAlterRemoveMenu(Company &company);

/**
 * @brief Sub-menu from Main menu that allows user to compare pharmacies.
 * @param company
 */
void compareMenu(Company &company);

/**
 * @brief Sub-menu from Main menu that allows user to save all the changed files.
 * @param company
 */
void updateFileMenu(Company &company);

/**
 * @brief Tests cin.fail.
 * @tparam template class T
 * @param value
 */
template <class T>
void fail (T &value){

    while(cin.fail()){

        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid value: ";
        cin >> value;
    }
}

#endif //UNTITLED_INTERFACES_H
