#ifndef ADMIN_H
#define ADMIN_H

class Admin {

  private:
    vector<Inventory> inventory;

  public:

    // Inventory Management
    void addProduct(const Inventory&);
    void updateProduct(int productID, const Inventory&);
    void removeProduct(int productID);
    void viewInventory() const;

    // Order Management
    void viewAllOrders() const;
    void updateOrder(int orderID);
    void recordSale(int productID, int quantity);

    // Reporting
    void salesReport() const;
    void inventoryReport() const;
    void backupRestore();

    // System Management
    void systemSettings();
    void displayFeedback();

  
};

# endif