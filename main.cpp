#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stdexcept>

#include "../header/Admin.h"
#include "../header/Customer.h"
#include "../header/Enhanced.h"
#include "../header/Inventory.h"

using namespace std;


void primaryMunu() const;
void adminMunu() const;
void customerMunu() const;



int main() {

    Inventory inventory;
    Admin admin;
    Customer customer;
    Enhanced enhanced;

    char option;
    double choice;

    primaryMunu();

    while (cin >> option) {

        if (option == 'a' || option == 'A') {
            adminMunu();

            if (choice == 1.1) {

            }
            else if (choice == 1.2) {

            }
            else if (choice == 1.3) {

            }
            else if (choice == 1.4) {

            }
            else if (choice == 2.1) {

            }
            else if (choice == 2.2) {

            }
            else if (choice == 2.3) {

            }
            else if (choice == 3.1) {

            }
            else if (choice == 3.2) {

            }
            else if (choice == 4.1) {

            }
            else if (choice == 4.2) {

            }
            else if (choice == 4.3) {

            }
            else {
                throw runtime_error("Invalid input. Please enter a valid number");
            }
        }

        else if (option == 'c' || option == 'C') {
            customerMunu();

            if (choice == 1) {
                // Customer choose shopping, we will display all inventory first.
                customer.browseProducts();
                // After display, proceed with purchase product.
                customer.purchaseProduct();
            }
            else if (choice == 2) {

            }
            else if (choice == 3) {

            }
            else {
                throw runtime_error("Invalid input. Please enter a valid number.");
            }
        }
        else {
            throw runtime_error("Invalid input. Please enter 'c' or 'a'.");
        }
    }


    return 0;
}


/*---------Main Munu---------*/

void primaryMunu() const {

    cout << "Welcome to Inventory Management System\n"
         << "Are you a Admin(a) or Customer(c)?\n"
         << "Please enter your choice to continue." << endl; 

}

/*---------Admin Munu---------*/

void adminMunu() const {

    cout << "Welcome! What would you like to do today?\n"
         << "P1 Inventory Management\n"
         << "1.1 Add Products\n"
         << "1.2 Update Products\n"
         << "1.3 Remove Products\n"
         << "1.4 View Inventory\n" 
         << endl
         << "P2 Order Management\n"
         << "2.1 View All Orders\n"
         << "2.2 Update Orders\n"
         << "2.3 Record Sales\n"
         << endl
         << "P3 Reporting\n"
         << "3.1 Sales Reports\n"
         << "3.2 Inventory Reports\n"
         << endl
         << "P4 System Management\n"
         << "4.1 Backup and Restore\n"
         << "4.2 System Settings\n"
         << "4.3 Display Feedback\n"
         << endl
         << "Please enter corresponding number for your choice(eg '1.1', '3.1')." << endl;

}


/*---------Customer Munu---------*/

void customerMunu() const {

    cout << "Welcome! What would you like to do today?\n"
         << "1. Shopping\n"
         << "2. View Orders\n"
         << "3. Provide Feedback\n"
         << "Please enter corresponding number for your choice(eg '1')." << endl;

}