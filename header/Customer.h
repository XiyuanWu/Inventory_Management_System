#ifndef CUSTOMER_H
#define CUSTOMER_H


class Customer {

  private:
    const Admin& admin;
    vector<string> feedback;
    vector<Inventory> shopping_cart;
    vector<Inventory> order;

  public:

    Customer(const Admin& admin): admin(admin) {}
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