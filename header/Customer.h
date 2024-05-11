#ifndef CUSTOMER_H
#define CUSTOMER_H


class Customer {

  private:
    vector<string> feedback;
    vector<Inventory> shopping_cart;

  public:
  
    // Shopping
    void browseProducts() const;
    void purchaseProduct(int productID, int quantity);
    void displayShoppingCart();

    // Order Inquiry
    void viewOrder() const;

    // Feedback System
    double findPrice(int productID);
    void provideFeedback(string feedback);

  
};

# endif