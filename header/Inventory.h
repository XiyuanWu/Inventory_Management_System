#ifndef INVENTORY_H
#define INVENTORY_H


class Inventory {

  private:
    int setID(int newID)                    { id = newID;             }
    string setName(int newName)             { name = newName;         }
    int setQuantity(int newQuantity)        { quantity = newQuantity; }
    double setPrice(int newPrice)           { price = newPrice;       }
    string setCategory(string newCategory)  { category = newCategory; }
    bool setStatus(bool newStatus)          { status = newStatus;     }


  public:
    int getID() const           { return id;       }
    string getName() const      { return name;     }
    int getQuantity() const     { return quantity; }
    double getPrice() const     { return price;    }
    string getCategory() const  { return category; }
    bool getStatus() const      { return status;   }

  private:
    int id;
    string name;
    int quantity;
    double price;
    string category;
    bool status;
  
};

# endif