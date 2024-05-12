#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <optional>

#include "header/Customer.h"
#include "header/Inventory.h"
#include "header/Admin.h"

using namespace std;


/*-----Inventory Management-----*/
void Admin::addProduct(const Inventory&) {

}

void Admin::updateProduct(int productID, const Inventory&) {

}

void Admin::removeProduct(int productID) {

}

void Admin::viewInventory() const {

}


/*-----Order Management-----*/
void Admin::viewAllOrders() const {

}

void Admin::updateOrder(int orderID) {

}

void Admin::recordSale(int productID, int quantity) {

}


/*-----Reporting-----*/
void Admin::salesReport() const {

}

void Admin::inventoryReport() const {

}

void Admin::backupRestore() {

}


/*-----System Management-----*/
void Admin::systemSettings() {

}

void Admin::displayFeedback() {

}

/*-----Get inventory content-----*/
// const Inventory* Admin::getProductById(int id) const {
//     for (const auto& item : inventory) {
//         if (item.getID() == id) {
//             return &item; 
//         }
//     }
//     return nullptr; // no item found
// }

std::optional<Inventory> Admin::getProductById(int id) const {
    for (const Inventory& item: inventory) {
        if (item.getID() == id) {
            return item;  // Return the item wrapped in std::optional
        }
    }
    return std::nullopt;  // Return std::nullopt if no item is found
}

 bool Admin::isProductInInventory(int id) const {
    return any_of(inventory.begin(), inventory.end(), [id](const Inventory& item) {
        return item.getID() == id;
    });
 }
