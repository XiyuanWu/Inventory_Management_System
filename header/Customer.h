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
    vector<Inventory> order;

  public:
    // Customer(): 
    Customer(const Admin& admin): _admin(admin) {}

    // Shopping
    void browseProducts() const;
    void purchaseProduct();
    void displayShoppingCart();
    void confirmOrder();

    // Order Inquiry
    void viewOrder() const;
    double findTotalPrice();

    // Feedback System
    void provideFeedback();

  
};

# endif