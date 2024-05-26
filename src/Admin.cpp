#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <optional>

#include "../header/Customer.h"
#include "../header/Inventory.h"
#include "../header/Admin.h"

using namespace std;


/*-----Inventory Management-----*/
void Admin::addProduct(const Inventory& product) {
    inventory.push_back(product);
}

void Admin::updateProduct(int productID, const optional<string>& name, const optional<int>& quantity,
                    const optional<double>& price, const optional<string>& category,
                    const optional<bool>& isStock) {

    for (auto& product: inventory) {
        if (product.getID() == productID) {
            if (name) product.setName(*name);
            if (quantity) product.setQuantity(*quantity);
            if (price) product.setPrice(*price);
            if (category) product.setCategory(*category);
            if (isStock) product.setIsStock(*isStock);
            break; 
        }
    }
}

void Admin::removeProduct(int productID) {

    inventory.erase(remove_if(inventory.begin(), inventory.end(),
                    [productID](const Inventory& product) { return product.getID() == productID; }),
                    inventory.end());

}

void Admin::viewInventory() const {

    if (inventory.empty()) {
        cout << "No inventory avaiable." << endl;
        return;
    }

    cout << "| ID | Product Name | Quantity | Price | Category | Status |" << endl;
    cout << "| -- | ------------ | -------- | ----- | -------- | ------ |" << endl;

    for (const auto& item: inventory) {
        cout << " | " << item.getName()
             << " | " << item.getQuantity()
             << " | " << item.getPrice()
             << " | " << item.getCategory();
        (cout << " | " << item.getisStock()) ? "In Stock" : "Out of Stock";
        cout << " | " << endl;
    }

}



/*-----Other feature-----*/
void Admin::viewAllOrders() const {


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

    cout << "List of feedback: " << endl;

    for (const auto& text: getFeedback()) {
        cout << text << endl;
    }
}

/*-----Get inventory content-----*/

// optional<Inventory> Admin::getProductById(int id) const {
    
//     for (const Inventory& item: inventory) {
//         if (item.getID() == id) 
//             return item; 
//         }
//     return nullopt; 
// }

//  bool Admin::isProductInInventory(int id) const {
//     return any_of(inventory.begin(), inventory.end(), [id](const Inventory& item) {
//         return item.getID() == id;
//     });
//  }
