#include "../header/Customer.h"
// #include "../header/Inventory.h"
// #include "../header/Admin.h"

using namespace std;


/*-----Shopping helper-----*/
void Customer::browseProducts() {

    Admin admin;
    const auto& inventory = admin.getInventory();

    if (inventory.empty()) {
        cout << "Nothing avaiable at this time." << endl;
        return;
    }

    cout << "| ID | Product Name | Quantity | Price | Category | Status |" << endl;
    cout << "| -- | ------------ | -------- | ----- | -------- | ------ |" << endl;

    for (const auto& item: inventory) {
        cout << "| " << item.getID()
             << " | " << item.getName()
             << " | " << item.getQuantity()
             << " | " << item.getPrice()
             << " | " << item.getCategory();
        (cout << " | " << item.getisStock()) ? "In Stock" : "Out of Stock";
        cout << " | " << endl;
    }

    // After display all avaiable, guide customer add product to shopping cart
    purchaseProduct();
}

void Customer::displayShoppingCart() const {

    if (shopping_cart.empty()) {
        cout << "Nothing avaiable at this time." << endl;
        return;
    }

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
             << " | " << item.getCategory();
        (cout << " | " << item.getisStock()) ? "In Stock" : "Out of Stock";
        cout << " | " << endl;
    }

}

double Customer::findTotalPrice() {

    char option;
    double totalPrice = 0;

    if (shopping_cart.empty()) {
        cout << "Shoppping cart is empty." << endl;
        return 1;
    }

    for (const auto&item: shopping_cart) {
        totalPrice += item.getQuantity() * item.getPrice();
    }

    cout << "Your total price is " << totalPrice << endl;

    return totalPrice;
}

void Customer::clearShoppingCart() {
    shopping_cart.clear();
}


void Customer::removeItemFromCart() {

    if (shopping_cart.empty()) {
        cout << "Shopping cart is empty, nothing need to remove." << endl;
        return;
    }
	
    string input;
    int indexToRemove;

    cout << "which product you want to remove? Only enter product # not ID." << endl;
    cout << "Press 'q' if you are done for removal." << endl;

    while (true) {
        cin >> input;

        if (input == "q") {
            cout << "Done for removal." << endl;
            break;
        }

        // Convert string to int
        indexToRemove = atoi(input.c_str());

        if (indexToRemove > 0 && indexToRemove <= shopping_cart.size()) {
            shopping_cart.erase(shopping_cart.begin() + (indexToRemove - 1));
            cout << "Item removed successfully." << endl;
            cout << "Enter enter # you want to remove or press 'q' for done: " << endl;
            continue;
        }

        else {
            cout << "Invalid index. Please enter a valid #: " << endl;
            continue;
        }
    }
}



/*-----Shopping-----*/
void Customer::purchaseProduct() {

    Admin admin;
    string input;

    cout << "Please choose product you want to buy. Only enter ID for the product you want to buy.\n"
         << "If you are done with add item. you may press 'q' for display shopping cart at any time." << endl;
    
    while (cin >> input) {
        if (input == "q" || input == "Q") {
            displayShoppingCart();
            break;
        }
        
        int id = 0;
        try {
            id = stoi(input); // convert string to int
        } catch (const invalid_argument& e) {
            cout << "Invalid ID entered. Please enter a numeric ID: " << endl;
            continue; // Skip the rest of the loop iteration and prompt again
        } 

        if (admin.isProductInInventory(id)) {  // check if product is in inventory
            auto product = admin.getProductById(id);  // get product info based on user entered id
            if (product) {
                shopping_cart.push_back(*product);
            }
            else {
                cout << "Product not found. Please try again: " << endl;
                continue;
            }
        }
        else {
            cout << "Product no longer available or invalid input, try again: " << endl;
            continue;
        }
    }

    cout << "Your total price is " << findTotalPrice() << endl; 
    confirmOrder(); // ask customer want to confirm order

}


void Customer::confirmOrder() {

    char option;

    // And ask user if want to confirm order.
    cout << "Confirm order? (Y/N)" << endl;

    while (cin >> option) {

        if (option == 'Y' || option == 'y') { // order confirm, order recorded.
            finalizeOrder();  // This method now handles adding to order history and clearing the cart.
            break;
        }
        else if (option == 'N' || option == 'n') { // if user not confirm order, display shopping cart again and ask if user want to add or remove some item.
            displayShoppingCart();
            cout << "Do you want to add(a) or remove(r) item?" << endl;
            cin >> option;

            if (option == 'A' || option == 'a') { // add more item
                browseProducts();
                cout << "Now press Y to confirmed order." << endl;
                continue;
            }
            else if (option == 'R' || option == 'r') { // remove some item
                removeItemFromCart();
                cout << "Now press Y to confirmed order." << endl;
                continue;
            }
            else {
                cout << "Invalid input. Please try again: " << endl;
                continue;
            }
        }
        else {
            cout << "Invalid input. Please enter Y/N: " << endl;
            continue;
        }
    }

}

void Customer::finalizeOrder() {

    if (!shopping_cart.empty()) {
        orderHistory.push_back(shopping_cart);
        cout << "Order has complete." << endl;

        // after order is done, clear shipping cart
        shopping_cart.clear();
    }
    else {
        cout << "No items in the cart to finalize." << endl;
    }
}



/*-----Order Inquiry-----*/
void Customer::viewOrder() const {

    if (orderHistory.empty()) {
        cout << "No orders to display." << endl;
        return;
    }

    cout << "Order History:" << endl;

    int orderNumber = 1;
    for (const auto& order: orderHistory) {
        cout << "Order #" << orderNumber++ << ":" << endl;
        cout << "| ID | Product Name | Quantity | Price | Category |" << endl;
        cout << "| -- | ------------ | -------- | ----- | -------- |" << endl;

        for (const auto& item : order) {
            cout << "| " << item.getID()
                 << " | " << item.getName()
                 << " | " << item.getQuantity()
                 << " | $" << item.getPrice()
                 << " | " << item.getCategory()
                 << " |" << endl;
        }
        cout << endl; // Add a space between ordersy
    }

}


/*-----Feedback System-----*/
void Customer::provideFeedback() {

    string userFeedback;

    cout << "Please provide your feedback here: " << endl;
    cin.ignore();
    getline(cin, userFeedback);
    cout << "Feedback received!" << endl;

    feedback.push_back(userFeedback);
}
