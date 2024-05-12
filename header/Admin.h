#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <optional>
#include "../header/Inventory.h"

using namespace std;

class Admin {

  private:
    vector<Inventory> inventory;

  public:

    // Inventory Management
    void addProduct(const Inventory&);
    void updateProduct(int productID, const Inventory&);
    void removeProduct(int productID);
    void viewInventory() const;

    // Order Management
    void viewAllOrders() const;
    void updateOrder(int orderID);
    void recordSale(int productID, int quantity);

    // Reporting
    void salesReport() const;
    void inventoryReport() const;
    void backupRestore();

    // System Management
    void systemSettings();
    void displayFeedback();

    // Get inventory content
    const vector<Inventory>& getInventory() const { return inventory; }
    // const Inventory* getProductById(int id) const;
    std::optional<Inventory> getProductById(int id) const;
    bool isProductInInventory(int id) const;

  
};

# endif