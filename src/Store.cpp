#include "../header/Store.h"

using namespace std;

/*-----Get inventory content-----*/
bool Store::isProductInInventory(int id) const {

    return any_of(inventory.begin(), inventory.end(), [id](const Product& item) {
        return item.getID() == id;
    });
}

optional<Product> Store::getProductById(int id) const {

    for (const auto& product: inventory) {
        if (product.getID() == id) {
            return product;
        }
    }
    return nullopt;
}

/*-----Customer Helper-----*/
bool Store::updateProductQuantity(int productId, int changeInQuantity) {

    for (auto& product: inventory) {
        if (product.getID() == productId) {
            // Check if sufficient quantity is available before decrementing
            if (product.getQuantity() + changeInQuantity < 0) {  // changeInQuantity is negative for purchases
                return false;  // Not enough stock
            }
            product.setQuantity(product.getQuantity() + changeInQuantity);
            return true;  // Successfully updated the quantity
        }
    }
    return false;  // Product not found
}

bool Store::replenishStock(int productId, int quantity) {
    for (auto& product : inventory) {
        if (product.getID() == productId) {
            product.setQuantity(product.getQuantity() + quantity);
            return true;
        }
    }
    return false; // Product ID not found
}

/*-----Store Operation-----*/


/*-----Inventory Management-----*/
void Store::addProduct() {

    int id, quantity;
    string name, category;
    double price;
    bool isStock;

    cout << "Enter Product you want to add here." << endl;

    cout << "Enter product ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    cout << "Enter product name: ";
    getline(cin, name);
    verifyName(name); 

    cout << "Enter product quantity: ";
    cin >> quantity;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter product price: ";
    cin >> price;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    cout << "Enter product category: ";
    getline(cin, category);
    verifyCategory(category);

    cout << "Is the product in stock (1 for yes, 0 for no): ";
    cin >> isStock;
    verifyIsStock(isStock);

    Product newProduct(id, name, quantity, price, category, isStock);
    inventory.push_back(newProduct);
    cout << "Product added successfully." << endl;
}

void Store::updateProduct() {

    int productID;
    viewInventory();
    cout << "Enter the ID of the product you want to update: ";
    cin >> productID;

    if (!isProductInInventory(productID)) {
        cout << "Product ID not exist. Please try again." << endl;
        return;
    }

    // Find the product
    for (auto& product: inventory) {

        if (product.getID() == productID) {
            int choice;
            cout << "What would you like to update? (1.name, 2.quantity, 3.price, 5.category, 5.isStock): ";
            cin >> choice;

            if (choice == 1) {
                string newName;
                cout << "Enter new name: ";
                getline(cin, newName);
                verifyName(newName);
                product.setName(newName);
                continue;
            } 

            else if (choice == 2) {
                int newQuantity;
                cout << "Enter new quantity: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> newQuantity;
                product.setQuantity(newQuantity);
                continue;
            } 

            else if (choice == 3) {
                double newPrice;
                cout << "Enter new price: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> newPrice;
                product.setPrice(newPrice);
                continue;
            } 

            else if (choice == 4) {
                string newCategory;
                cout << "Enter new category: ";
                getline(cin, newCategory);
                verifyCategory(newCategory);
                product.setCategory(newCategory);
                continue;
            } 

            else if (choice == 5) {
                bool newIsStock;
                cout << "Is the product in stock (1 for yes, 0 for no): ";
                cin >> newIsStock;
                cin.ignore();
                verifyIsStock(newIsStock);
                product.setIsStock(newIsStock);
                continue;
            } 

            else {
                cout << "Invalid choice. Try again." << endl;
                continue;
            }

            cout << "Product updated successfully." << endl;
            return;
        }
    }
    cout << "Product not found." << endl;
}

void Store::removeProduct() {

    int productID;
    cout << "Enter the ID of the product you want to remove: ";
    cin >> productID;

    auto it = remove_if(inventory.begin(), inventory.end(),
                             [productID](const Product& product) {
                                 return product.getID() == productID;
                             });

    if (it != inventory.end()) {
        inventory.erase(it, inventory.end());
        cout << "Product removed successfully." << endl;
    } else {
        cout << "Product not found." << endl;
    }
}

void Store::viewInventory() const {

    if (inventory.empty()) {
        cout << "No inventory avaiable." << endl;
        return;
    }

    cout << "Inventory Overview" << endl;
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



/*-----Other feature-----*/
void Store::viewAllOrders() const {

    if (getOrderHistory().empty()) {
        cout << "No order right now." << endl;
        return;
    }

    cout << "Order History:" << endl;
    for (const auto& order: getOrderHistory()) {
        cout << "Order:" << endl;
        for (const auto& item: order) {
            cout << "| " << item.getID()
                 << " | " << item.getName()
                 << " | " << item.getQuantity()
                 << " | " << item.getPrice()
                 << " | " << item.getCategory()
                 << " | " << (item.getIsStock() ? "In Stock" : "Out of Stock")
                 << " |" << endl;
        }
        cout << endl;
    }
}

void Store::displayFeedback() {

    if (getFeedback().empty()) {
        cout << "There are no feedback right now." << endl;
        return;
    }

    cout << "List of feedback: " << endl;

    for (const auto& text: getFeedback()) {
        cout << text << endl;
    }
}



/*-----Verify Input-----*/
void Store::verifyName(const string& name) const {
    if (name.empty()) {
        throw invalid_argument("Product name cannot be empty.");
    }
}

void Store::verifyCategory(const string& category) const {
    if (category.empty()) {
        throw invalid_argument("Product category cannot be empty.");
    }
}

void Store::verifyIsStock(bool isStock) const {
    if (isStock != 0 && isStock != 1) {
        throw invalid_argument("Invalid input for stock status. Please enter 1 for yes or 0 for no.");
    }
}



