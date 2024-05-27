#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <optional>
#include <limits>

#include "../header/Customer.h"
#include "../header/Inventory.h"
#include "../header/Admin.h"

using namespace std;


/*-----Inventory Management-----*/
void Admin::addProduct() {

    int id, quantity;
    string name, category;
    double price;
    bool isStock;

    cout << "Enter Product you want to add here." << endl;

    cout << "Enter product ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    cout << "Enter product name: ";
    getline(cin, name);
    verifyName(name); 

    cout << "Enter product quantity: ";
    cin >> quantity;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter product price: ";
    cin >> price;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    cout << "Enter product category: ";
    getline(cin, category);
    verifyCategory(category);

    cout << "Is the product in stock (1 for yes, 0 for no): ";
    cin >> isStock;
    verifyIsStock(isStock);

    Inventory newProduct(id, name, quantity, price, category, isStock);
    inventory.push_back(newProduct);
    cout << "Product added successfully." << endl;
}

void Admin::updateProduct() {

    int productID;
    viewInventory();
    cout << "Enter the ID of the product you want to update: ";
    cin >> productID;

    if (!isProductInInventory(productID)) {
        cout << "Product ID not exist. Please try again." << endl;
        return;
    }

    // Find the product
    for (auto& product: inventory) {

        if (product.getID() == productID) {
            int choice;
            cout << "What would you like to update? (1.name, 2.quantity, 3.price, 5.category, 5.isStock): ";
            cin >> choice;

            if (choice == 1) {
                string newName;
                cout << "Enter new name: ";
                getline(cin, newName);
                verifyName(newName);
                product.setName(newName);
            } 

            else if (choice == 2) {
                int newQuantity;
                cout << "Enter new quantity: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> newQuantity;
                product.setQuantity(newQuantity);
            } 

            else if (choice == 3) {
                double newPrice;
                cout << "Enter new price: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> newPrice;
                product.setPrice(newPrice);
            } 

            else if (choice == 4) {
                string newCategory;
                cout << "Enter new category: ";
                getline(cin, newCategory);
                verifyCategory(newCategory);
                product.setCategory(newCategory);
            } 

            else if (choice == 5) {
                bool newIsStock;
                cout << "Is the product in stock (1 for yes, 0 for no): ";
                cin >> newIsStock;
                cin.ignore();
                verifyIsStock(newIsStock);
                product.setIsStock(newIsStock);
            } 

            else {
                cout << "Invalid choice. Try again." << endl;
                continue;
            }

            cout << "Product updated successfully." << endl;
            return;
        }
    }
    cout << "Product not found." << endl;
}

void Admin::removeProduct() {

    int productID;
    cout << "Enter the ID of the product you want to remove: ";
    cin >> productID;

    auto it = remove_if(inventory.begin(), inventory.end(),
                             [productID](const Inventory& product) {
                                 return product.getID() == productID;
                             });

    if (it != inventory.end()) {
        inventory.erase(it, inventory.end());
        cout << "Product removed successfully." << endl;
    } else {
        cout << "Product not found." << endl;
    }
}

void Admin::viewInventory() const {

    if (inventory.empty()) {
        cout << "No inventory avaiable." << endl;
        return;
    }

    cout << "Inventory Overview" << endl;
    cout << "| ID | Product Name | Quantity | Price | Category | Status |" << endl;
    cout << "| -- | ------------ | -------- | ----- | -------- | ------ |" << endl;

    for (const auto& item: inventory) {
        cout << "| " << item.getID()
             << " | " << item.getName()
             << " | " << item.getQuantity()
             << " | " << item.getPrice()
             << " | " << item.getCategory();
        (cout << " | " << item.getisStock()) ? "In Stock" : "Out of Stock";
        cout << " | " << endl;
    }

}



/*-----Other feature-----*/
void Admin::viewAllOrders() const {

    if (getOrderHistory().empty()) {
        cout << "No order right now." << endl;
        return;
    }

    cout << "Order History:" << endl;
    for (const auto& order: getOrderHistory()) {
        cout << "Order:" << endl;
        for (const auto& item: order) {
            cout << "| " << item.getID()
                 << " | " << item.getName()
                 << " | " << item.getQuantity()
                 << " | " << item.getPrice()
                 << " | " << item.getCategory()
                 << " | " << (item.getisStock() ? "In Stock" : "Out of Stock")
                 << " |" << endl;
        }
        cout << endl;
    }
}

void Admin::displayFeedback() {

    if (getFeedback().empty()) {
        cout << "There are no feedback right now." << endl;
        return;
    }

    cout << "List of feedback: " << endl;

    for (const auto& text: getFeedback()) {
        cout << text << endl;
    }
}



/*-----Verify Input-----*/
void Admin::verifyName(const string& name) const {
    if (name.empty()) {
        throw invalid_argument("Product name cannot be empty.");
    }
}

void Admin::verifyCategory(const string& category) const {
    if (category.empty()) {
        throw invalid_argument("Product category cannot be empty.");
    }
}

void Admin::verifyIsStock(bool isStock) const {
    if (isStock != 0 && isStock != 1) {
        throw invalid_argument("Invalid input for stock status. Please enter 1 for yes or 0 for no.");
    }
}
