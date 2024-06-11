#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include "../header/Product.h"
#include "../header/Store.h"

using namespace std;

class Customer: public Store {

  private:
    const std::vector<Product>& inventory;
    vector<Product> shopping_cart;

  public:

    Customer(const std::vector<Product>& inventory) : inventory(inventory) {}


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

    // For Test purpose
    int getCartSize() { return shopping_cart.size(); }
    // void setInventory(const vector<Inventory>& inv) { inventory = inv; }
  
};

# endif