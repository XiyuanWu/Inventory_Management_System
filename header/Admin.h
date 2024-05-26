#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <optional>
#include "../header/Inventory.h"
#include "../header/Store.h"

using namespace std;

class Admin: public Store {

  public:

    // Inventory Management
    void addProduct(const Inventory&);
    void updateProduct(int productID, const optional<string>& name = nullopt, const optional<int>& quantity = nullopt,
                       const optional<double>& price = nullopt, const optional<string>& category = nullopt,
                       const optional<bool>& isStock = nullopt);
    void removeProduct(int productID);
    void viewInventory() const;

    // Other feature
    void viewAllOrders() const;
    void displayFeedback();

  
};

# endif