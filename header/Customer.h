#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include "../header/Inventory.h"
#include "../header/Store.h"

using namespace std;

class Customer: public Store {

  private:
    vector<Inventory> shopping_cart;

  public:

    // Shopping
    void purchaseProduct();
    void removeItemFromCart();
    void confirmOrder();
    void finalizeOrder();

    // Shopping helper
    void displayShoppingCart() const;
    void browseProducts();
    double findTotalPrice();
    void clearShoppingCart();
    bool isInventoryEmpty() const;

    // View order
    void viewOrder() const;

    // Feedback System
    void provideFeedback();
  
};

# endif