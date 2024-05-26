#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <vector>
#include <string>
#include "../header/Inventory.h"

using namespace std;

class Store {

  protected:
    vector<Inventory> inventory;
    vector<vector<Inventory>> orderHistory; 
    vector<string> feedback;

  public:
    const vector<Inventory>& getInventory() const { return inventory; }
    const vector<vector<Inventory>>& getOrderHistory() const { return orderHistory; }
    const vector<string>& getFeedback() const { return feedback; }

};

#endif 
