#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include "../header/Inventory.h"

using namespace std;

class Customer {

  private:
    const Admin& _admin;
    vector<string> feedback;
    vector<Inventory> shopping_cart;
    vector<vector<Inventory>> orderHistory;

  public:
    Customer(const Admin& admin): _admin(admin) {}

    // Shopping
    void purchaseProduct();
    void removeItemFromCart();
    void confirmOrder();
    void finalizeOrder();

    // Shopping helper
    void displayShoppingCart() const;
    void browseProducts() const;
    double findTotalPrice();
    void clearShoppingCart();

    // View order
    void viewOrder() const;

    // Feedback System
    void provideFeedback();

    // Get order history
    const vector<vector<Inventory>>& getIOrderHistory() const { return orderHistory; }
  
};

# endif