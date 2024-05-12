#include "header/Customer.h"
#include "header/Inventory.h"
#include "header/Admin.h"

using namespace std;


/*-----Shopping-----*/
void Customer::browseProducts() const {

    Admin admin;
    const auto& inventory = admin.getInventory();

    cout << "| ID | Product Name | Quantity | Price | Category | Status |" << endl;
    cout << "| -- | ------------ | -------- | ----- | -------- | ------ |" << endl;

    for (const auto& item: inventory) {
        cout << "| " << item.getID()
             << " | " << item.getName()
             << " | " << item.getQuantity()
             << " | " << item.getPrice()
             << " | " << item.getCategory();
        (cout << " | " << item.getStatus()) ? "In Stock" : "Out of Stock";
        cout << " | " << endl;
    }
}


void Customer::purchaseProduct() {

    // Admin admin;
    std::string input;

    cout << "Please choose product you want to buy. Only enter ID for the product you want to buy.\n"
         << "If you are done with add item. press 'q' for display shopping cart." << endl;
    
    while (cin >> input) {
        if (input == "q") {
            displayShoppingCart();
            break;
        }
        
        // int id = stoi(input); // convert string to int
        int id = 0;
        try {
            id = stoi(input); // convert string to int
        } catch (const invalid_argument& e) {
            cout << "Invalid ID entered. Please enter a numeric ID." << endl;
            continue; // Skip the rest of the loop iteration and prompt again
        } catch (const out_of_range& e) {
            cout << "ID is out of range. Please enter a smaller ID." << endl;
            continue; // Skip the rest of the loop iteration and prompt again
        }


        if (admin.isProductInInventory(id)) {
            const Inventory product = admin.getProductById(id);  // get product info based on user entered id
            if (product) {
                shopping_cart.push_back(*product);
            }
            else {
                cout << "Product not found. Please try again." << endl;
            }
        }
        else {
            cout << "Product no longer available or invalid input.\n";
        }
    }

    findTotalPrice();  // After added item and display, calculate total price
    confirmOrder(); // proceed with confirm order

}

void Customer::confirmOrder() {

    int number;
    char option;

    // And ask user if want to confirm order.
    cout << "Confirm order? (Y/N)" << endl;

    while (cin >> option) {

        if (option == 'Y' || option == 'y') { // order confirm, order recorded.
            order.push_back(shopping_cart); // to be done, also need a order number
        }
        else if (option == 'N' || option == 'n') { // if user not confirm order, display shopping cart again and ask if user want to add or remove some item.
            displayShoppingCart();
            cout << "Do you want to add(a) or remove(r) item?" << endl;

            if (option == 'A' || option == 'a') { // add more item
                browseProducts();
                // user add more item
                purchaseProduct();
            }
            else if (option == 'R' || option == 'r') { // remove some item
                displayShoppingCart(); // display shopping cart to user
                // ask user which item want to remove from shopping cart
                cout << "which product you want to remove? Only enter product # not ID." << endl;
                cin >> number;
                if (/*number found in shopping cart*/) {
                    // remove it: to be complete
                    displayShoppingCart();
                    cout << "Want remove more?" << endl;
                    // to be complete
                }
                else {
                    cout << "The number you enter are invalid or don't exists, try again." << endl;
                }
            }
            else {
                cout << "Invalid input. Please try again." << endl;
            }
        }
        else {
            cout << "Invalid input. Please enter Y/N." << endl;
        }
    }
}


void Customer::displayShoppingCart() {

    int count = 1;

    cout << "Your shopping cart:" << endl;
    cout << "| # | ID | Product Name | Quantity | Price | Category | Status |" << endl;
    cout << "| - | -- | ------------ | -------- | ----- | -------- | ------ |" << endl;

    for (const auto& item: shopping_cart) {
        cout << "| " << count++
             << " | " << item.getID()
             << " | " << item.getName()
             << " | " << item.getQuantity()
             << " | " << item.getPrice()
             << " | " << item.getCategory()
             << " | " << item.getStatus() ? "In Stock" : "Out of Stock"
             << " | " << endl;
    }

}

/*-----Order Inquiry-----*/
void Customer::viewOrder() const {

    cout << "| ID | Product Name | Quantity | Price | Category |" << endl;
    cout << "| -- | ------------ | -------- | ----- | -------- |" << endl;

    for (const auto& item: shopping_cart) {
        cout << " | " << item.getID()
             << " | " << item.getName()
             << " | " << item.getQuantity()
             << " | " << item.getPrice()
             << " | " << item.getCategory()
             << " | " << endl;
    }
}


double Customer::findTotalPrice() {

    char option;
    double totalPrice = 0;

    for (const auto&item: shopping_cart) {
        totalPrice += item.getQuantity() * item.getPrice();
    }

    cout << "Your total price is " << totalPrice << endl;

    return totalPrice;
}


/*-----Feedback System-----*/
void Customer::provideFeedback() {

    string userFeedback;

    cout << "Please provide your feedback here: " << endl;
    getline(cin, userFeedback);

    feedback.push_back(userFeedback);
}
