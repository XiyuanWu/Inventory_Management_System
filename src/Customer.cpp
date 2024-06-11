#include "../header/Customer.h"
// #include "../header/Inventory.h"
// #include "../header/Admin.h"

using namespace std;


/*-----Shopping helper-----*/
bool Customer::isInventoryEmpty() const {

    const auto& inventory = getInventory();

    return inventory.empty() ? false : true;
}

void Customer::browseProducts() {

    cout << "Product Overview" << endl;
    cout << "| ID | Product Name | Quantity | Price | Category | Status |" << endl;
    cout << "| -- | ------------ | -------- | ----- | -------- | ------ |" << endl;

    for (const auto& item: inventory) {
        cout << "| " << item.getID()
             << " | " << item.getName()
             << " | " << item.getQuantity()
             << " | " << item.getPrice()
             << " | " << item.getCategory();
        (cout << " | " << item.getIsStock()) ? "In Stock" : "Out of Stock";
        cout << " | " << endl;
    }
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
        (cout << " | " << item.getIsStock()) ? "In Stock" : "Out of Stock";
        cout << " | " << endl;
    }

}

// In this project, assume tax is included in price
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

        try {
            indexToRemove = stoi(input);  // Convert string to int
        } catch (const invalid_argument& e) {
            cout << "Invalid index. Please enter a valid #: " << endl;
            continue;
        }

        if (indexToRemove > 0 && indexToRemove <= shopping_cart.size()) {
            // Get the product ID and quantity to be replenished to the inventory
            auto& product = shopping_cart.at(indexToRemove - 1);
            int productId = product.getID();
            int quantityToReplenish = product.getQuantity();

            // Remove the item from the cart
            shopping_cart.erase(shopping_cart.begin() + (indexToRemove - 1));
            cout << "Item removed successfully." << endl;

            // Replenish the stock in the inventory
            if (!replenishStock(productId, quantityToReplenish)) {
                cout << "Failed to update the inventory." << endl;
            }

            cout << "Enter # of the product you want to remove or press 'q' for done: " << endl;
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
    
    string input;

    cout << "Please choose the product you want to buy. Only enter the ID for the product." << endl;
    cout << "If you are done adding items, you may press 'q' at any time to display the shopping cart." << endl;
 
    while (cin >> input) {
        if (input == "q" || input == "Q") {
            displayShoppingCart();
            break;
        }

        int id = 0;
        try {
            id = stoi(input); // Convert string to int
        } catch (const invalid_argument& e) {
            cout << "Invalid ID entered. Please enter a numeric ID: " << endl;
            continue; 
        }

        if (!isProductInInventory(id)) {
            cout << "Product not in inventory, try again." << endl;
            continue;
        }

        auto product = getProductById(id); // Get product info based on user-entered ID
        if (!product) {
            cout << "Product not found, try again." << endl;
            continue;
        }

        cout << "Enter the quantity you want: ";
        int quantity;
        if (!(cin >> quantity) || quantity <= 0) {
            cout << "Invalid quantity entered. Please enter a positive number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (!updateProductQuantity(id, quantity)) {
            cout << "Insufficient stock available, try again." << endl;
            continue;
        }

        // Add product and quantity to the shopping cart
        Product cartItem = *product;
        cartItem.setQuantity(quantity); // Assuming Product has a quantity field that can be set
        shopping_cart.push_back(cartItem);
        cout << "Added " << quantity << " of " << product -> getName() << " to the cart." << endl;
    }
}




void Customer::confirmOrder() {

    char option;

    // And ask user if want to confirm order.
    cout << "Confirm order? (Y/N)" << endl;
    cin >> option;

    if (option == 'Y' || option == 'y') { // order confirm, order recorded.
            finalizeOrder();  // This method now handles adding to order history and clearing the cart.
            return;
    }

    while (true) {

        cout << "Do you want to confirmed order(Y), add more product(A), or remove some item(R)?" << endl;

        if (option == 'Y' || option == 'y') { // order confirm, order recorded.
            break;
        }
        else if (option == 'N' || option == 'n') { // if user not confirm order, display shopping cart again and ask if user want to add or remove some item.
            displayShoppingCart();
            cout << "Do you want to add(a) or remove(r) item?" << endl;
            cin >> option;

            if (option == 'A' || option == 'a') { // add more item
                browseProducts();         // show cart
                purchaseProduct();        // make purchase
                displayShoppingCart();    // show cart after purchase
                cout << "Product add successfully." << endl;
                continue;
            }
            else if (option == 'R' || option == 'r') { // remove some item
                removeItemFromCart();
                displayShoppingCart(); 
                cout << "Product add successfully." << endl;
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

    finalizeOrder();  

}

void Customer::finalizeOrder() {

    if (shopping_cart.empty()) {
        cout << "No items in the cart." << endl;
        return;
    }

    bool inventoryUpdated = true;
    // Attempt to update inventory for each item in the cart
    for (const auto& item: shopping_cart) {
        if (!updateProductQuantity(item.getID(), -item.getQuantity())) {  // Note the negative quantity for reduction
            inventoryUpdated = false;
            cout << "Failed to update inventory for product ID " << item.getID() << ". Insufficient stock." << endl;
            // Optionally, handle partial inventory updates (rollback or confirm partial)
        }
    }

    if (inventoryUpdated) {
        orderHistory.push_back(shopping_cart);
        cout << "Order has been confirmed and completed." << endl;
        shopping_cart.clear(); // Clear the cart after confirming the order
    } else {
        cout << "Order could not be finalized due to inventory constraints." << endl;
        // Here you could choose to not clear the cart to allow the customer to adjust their order
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
