#ifndef Product_H
#define Product_H

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Product {

  public:
    Product(): _id(0), _name(""), _quantity(0), _price(0.0), _category(""), _isStock(false) {}
    Product(int id, const string& name, int quantity, double price, const string& category, bool isStock):
              _id(id), _name(name), _quantity(quantity), _price(price), _category(category), _isStock(isStock) {}
    ~Product() {}
    
    int getID() const           { return _id;       }
    string getName() const      { return _name;     }
    int getQuantity() const     { return _quantity; }
    double getPrice() const     { return _price;    }
    string getCategory() const  { return _category; }
    bool getIsStock() const     { return _isStock;  }

    void setID(int newID)                       { _id = newID;             }
    void setName(string newName)                { _name = newName;         }
    void setQuantity(int newQuantity)           { _quantity = newQuantity; }
    void setPrice(double newPrice)              { _price = newPrice;       }
    void setCategory(const string& newCategory) { _category = newCategory; }
    void setIsStock(bool newIsStock)            { _isStock = newIsStock;   }


  private:
    int _id;
    string _name;
    int _quantity;
    double _price;
    string _category;
    bool _isStock;
  
};

# endif