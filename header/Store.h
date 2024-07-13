#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <optional>
#include "../header/Product.h"

using namespace std;

class Store {

  protected:
    vector<Product> inventory;
    vector<vector<Product>> orderHistory; 
    vector<string> feedback;

  public:
    const vector<Product>& getInventory() const             { return inventory; }
    const vector<vector<Product>>& getOrderHistory() const  { return orderHistory; }
    const vector<string>& getFeedback() const               { return feedback; }

    // Get inventory content
    virtual bool isProductInInventory(int id) const;
    virtual optional<Product> getProductById(int id) const;

    // Customer Helper
    bool updateProductQuantity(int id, int quantity);
    bool replenishStock(int productId, int quantity);

    // Inventory Management
    void addProduct();
    void updateProduct();
    void removeProduct();
    void viewInventory() const;

    // Other feature
    void viewAllOrders() const;
    void displayFeedback();

    // To verify input are valid or not
    void verifyName(const string& name) const;
    void verifyCategory(const string& category) const;
    void verifyIsStock(bool isStock) const;







    // For test purpose
    void addProduct(const Product& item) { inventory.push_back(item); }
    void addFeedback(const string& feedbackMessage) { feedback.push_back(feedbackMessage); }

    // void viewInventory() const {

    //     if (inventory.empty()) {
    //         cout << "No inventory avaiable." << endl;
    //         return;
    //     }

    //     for (const auto& item: inventory) {
    //         cout << "| " << item.getID()
    //             << " | " << item.getName()
    //             << " | " << item.getQuantity()
    //             << " | " << item.getPrice()
    //             << " | " << item.getCategory();
    //         (cout << " | " << item.getisStock()) ? "In Stock" : "Out of Stock";
    //         cout << " | " << endl;
    //     }

    // }
};

#endif 
