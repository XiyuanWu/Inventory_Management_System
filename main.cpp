#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stdexcept>

#include "./header/Admin.h"
#include "./header/Customer.h"
#include "./header/Inventory.h"
#include "./header/Store.h"

using namespace std;


void primaryMunu();
void adminMunu();
void customerMunu();



int main() {

    Admin admin;
    Customer customer;

    char option;
    int choice = 0;

    primaryMunu();
    cin >> option;


    if (option == 'a' || option == 'A') {

        while (true) {
            adminMunu();
            cin >> choice;

            if (choice == 1) {
                admin.addProduct();
                continue;
            }
            else if (choice == 2) {
                admin.updateProduct();
                continue;
            }
            else if (choice == 3) {
                admin.removeProduct();
                continue;
            }
            else if (choice == 4) {
                admin.viewInventory();
                continue;
            }
            else if (choice == 5) {
                admin.viewAllOrders();
                continue;
            }
            else if (choice == 6) {
                admin.displayFeedback();
                continue;
            }
            else {
                cout << "Invalid input. Please enter a valid number." << endl;
                continue;
            }
        }
    }

    else if (option == 'c' || option == 'C') {
        customerMunu();

        while (cin >> choice) {
        
            if (choice == 1) {
                if (customer.isInventoryEmpty()) {
                    customer.browseProducts();
                    customer.purchaseProduct();
                    customer.confirmOrder();
                    break;
                }
                else {
                    cout << "Nothing avaiable in store in this moment. " << endl;
                    break;
                }
                continue;
            }
            else if (choice == 2) {
                customer.viewOrder();
                continue;
            }
            else if (choice == 3) {
                customer.provideFeedback();
                break;
            }
            else {
                cout << "Invalid input. Please enter a valid number." << endl;
                continue;
            }
        }
    }
    else {
        throw runtime_error("Invalid Input");
    }


    return 0;
}


/*---------Main Munu---------*/

void primaryMunu() {

    cout << "Welcome to Inventory Management System\n"
         << "Are you a Admin(a) or Customer(c)? " << endl;

}

/*---------Admin Munu---------*/

void adminMunu() {

    cout << endl;
    cout << "What would you like to do today?\n"
         << "P1 Inventory Management\n"
         << "1. Add Products\n"
         << "2. Update Products\n"
         << "3. Remove Products\n"
         << "4. View Inventory\n" 
         << endl
         << "P2 Other Feature\n"
         << "5. View All Orders\n"
         << "6. Display Feedback\n"
         << endl
         << "Please enter corresponding number for your choice: " << endl;

}


/*---------Customer Munu---------*/

void customerMunu() {

    cout << endl;
    cout << "What would you like to do today?\n"
         << "1. Shopping\n"
         << "2. View Orders\n"
         << "3. Provide Feedback\n"
         << "Please enter corresponding number for your choice: " << endl;

}