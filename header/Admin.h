#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <optional>
#include <limits>
#include "../header/Product.h"
#include "../header/Store.h"

using namespace std;

class Admin: public Store {

  public:

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
    // void setInventory(vector<Product>& inv) { inventory = inv; }
  
};

# endif