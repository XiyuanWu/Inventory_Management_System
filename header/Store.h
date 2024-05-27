#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <optional>
#include "../header/Inventory.h"

using namespace std;

class Store {

  protected:
    vector<Inventory> inventory;
    vector<vector<Inventory>> orderHistory; 
    vector<string> feedback;

  public:
    const vector<Inventory>& getInventory() const             { return inventory; }
    const vector<vector<Inventory>>& getOrderHistory() const  { return orderHistory; }
    const vector<string>& getFeedback() const                 { return feedback; }

    // Get inventory content
    bool isProductInInventory(int id) const;
    optional<Inventory> getProductById(int id) const;

    // For test purpose
    void addProduct(const Inventory& item) { inventory.push_back(item); }


};

#endif 
