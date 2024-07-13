#include "gtest/gtest.h"
#include "../header/Customer.h"
#include "../header/Product.h"
#include "../header/Store.h"
#include <sstream>
#include <gtest/gtest.h>

using namespace std;

class CustomerTest : public ::testing::Test {
  protected:
    Customer *customer;
    Store store;  // Assuming Customer needs a Store object

    vector<Product> inventory;
    vector<string> feedback;

    void SetUp() override {
        // Setup code here. If Customer depends on Store being populated:
        inventory.push_back(Product(1, string("Apple"), 10, 5.0, string("Fruit"), true));
        inventory.push_back(Product(2, string("Beef"), 5, 20.0, string("Meat"), true));
        inventory.push_back(Product(3, string("Fish"), 20, 15.0, string("Seafood"), true));

        for (const auto& item: inventory) {
            store.addProduct(item);
        }

        // store.viewInventory();
        // cout << "Store inventory size before customer initialization: " << store.getInventory().size() << endl;
        customer = new Customer(store.getInventory());
        // cout << "Customer inventory size after initialization: " << customer->getInventorySize() << endl;
        customer -> browseProducts();
    }

    void TearDown() override {
        delete customer;  // Clean up dynamic memory if used
    }

    void simulateInput(const string& input) {
        static istringstream iss;
        iss.clear(); // Clear any errors
        iss.str(input); // Set the new input
        cin.rdbuf(iss.rdbuf()); // Redirect cin to use iss
    }

    void resetInput() {
        cin.rdbuf(cin.rdbuf()); // Reset cin to standard input
    }
};

// Test adding items to the shopping cart
TEST_F(CustomerTest, AddItemToCart) {
    simulateInput("1\n5\nq\n"); // Assume customer adds id 1 to shopping cart
    customer -> purchaseProduct();
    EXPECT_EQ(customer -> getCartSize(), 1);  
}

// // Test case for ensuring items can be removed from the cart
// TEST_F(CustomerTest, RemoveItemFromCart) {
//     customer->addItemToCart(1, 5);
//     customer->removeItemFromCart(1);
//     EXPECT_EQ(customer->getCartSize(), 0);
// }

// // Test case for checking the behavior when a non-existent item ID is used
// TEST_F(CustomerTest, AddNonExistentItem) {
//     customer->addItemToCart(999, 1);  // Assuming 999 is a non-existent product ID
//     EXPECT_EQ(customer->getCartSize(), 0);  // Assuming the cart should not accept invalid product IDs
// }

// test
