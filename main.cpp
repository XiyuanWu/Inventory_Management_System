#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stdexcept>

#include "header/Admin.h"
#include "header/Customer.h"
#include "header/Enhanced.h"
#include "header/Inventory.h"

using namespace std;


void primaryMunu();
void adminMunu();
void customerMunu();



int main() {

    Inventory inventory;
    Admin admin;
    Customer customer(admin);
    // Enhanced enhanced;

    char option;
    int choice = 0;

    primaryMunu();

    while (cin >> option) {

        if (option == 'a' || option == 'A') {
            adminMunu();

            if (choice == 1) {

            }
            else if (choice == 2) {

            }
            else if (choice == 3) {

            }
            else if (choice == 4) {

            }
            else if (choice == 5) {

            }
            else if (choice == 6) {

            }
            else if (choice == 7) {

            }
            else if (choice == 8) {

            }
            else if (choice == 9) {

            }
            else if (choice == 10) {

            }
            else if (choice == 11) {

            }
            else if (choice == 12) {

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

void primaryMunu() {

    cout << "Welcome to Inventory Management System\n"
         << "Are you a Admin(a) or Customer(c)?\n"
         << "Please enter your choice to continue." << endl; 

}

/*---------Admin Munu---------*/

void adminMunu() {

    cout << "Welcome! What would you like to do today?\n"
         << "P1 Inventory Management\n"
         << "1. Add Products\n"
         << "2. Update Products\n"
         << "3. Remove Products\n"
         << "4. View Inventory\n" 
         << endl
         << "P2 Order Management\n"
         << "5. View All Orders\n"
         << "6. Update Orders\n"
         << "7. Record Sales\n"
         << endl
         << "P3 Reporting\n"
         << "8. Sales Reports\n"
         << "9. Inventory Reports\n"
         << endl
         << "P4 System Management\n"
         << "10. Backup and Restore\n"
         << "11. System Settings\n"
         << "12. Display Feedback\n"
         << endl
         << "Please enter corresponding number for your choice(eg '2', '9')." << endl;

}


/*---------Customer Munu---------*/

void customerMunu() {

    cout << "Welcome! What would you like to do today?\n"
         << "1. Shopping\n"
         << "2. View Orders\n"
         << "3. Provide Feedback\n"
         << "Please enter corresponding number for your choice(eg '1')." << endl;

}