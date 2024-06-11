#include "gtest/gtest.h"
// #include "./header/Admin.h"
// #include "./header/Customer.h"
#include "../header/Product.h"
#include "../header/Store.h"
#include <sstream>
#include <gtest/gtest.h>

using namespace std;

class StoreTest : public ::testing::Test {

  protected:
    vector<Product> inventory;
    vector<string> feedback;
    Store store;

    void SetUp() override {
        inventory.push_back(Product(1, string("Apple"), 10, 5.0, string("Fruit"), true));
        inventory.push_back(Product(2, string("Beef"), 5, 20.0, string("Meat"), true));
        inventory.push_back(Product(3, string("Fish"), 20, 15.0, string("Seafood"), true));

        for (const auto& item: inventory) {
            store.addProduct(item);
        }

        store.addFeedback("Great");

        // customer = new Customer(store.getInventory());
    }

    // void TearDown() override {
    //     delete customer;
    // }


    void simulateInput(const string& input) {
        static istringstream iss(input);
        cin.rdbuf(iss.rdbuf());   // Redirect cin to read from iss
    }

    // void simulateInput(const string& input) {
    //     static istringstream iss(input);
    //     static streambuf* cinbuf = cin.rdbuf();  // preserve old buf
    //     cin.rdbuf(iss.rdbuf());  // redirect cin to use iss

    //     // Your test execution, e.g., customer->purchaseProduct();

    //     // Reset cin to standard input again
    //     cin.rdbuf(cinbuf);
    // }

};

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*-----Test Store-----*/

// Test for getInventory
TEST_F(StoreTest, GetInventory) {
    const auto& inv = store.getInventory();
    EXPECT_EQ(inv.size(), 3);  // We added 3 items in SetUp
    EXPECT_EQ(inv[0].getName(), "Apple");
    EXPECT_EQ(inv[1].getName(), "Beef");
    EXPECT_EQ(inv[2].getName(), "Fish");
}

// Test for getOrderHistory
TEST_F(StoreTest, GetOrderHistory) {
    const auto& orderHistory = store.getOrderHistory();
    EXPECT_TRUE(orderHistory.empty());  // Initially, order history should be empty
}

// Test for get feedback
TEST_F(StoreTest, GetFeedback) {
    const auto& feedback = store.getFeedback();
    EXPECT_EQ(feedback.size(), 1);  // Check if there is exactly one feedback
    EXPECT_EQ(feedback[0], "Great");  // Check if the feedback is the expected one
}


// Test for isProductInInventory
TEST_F(StoreTest, IsProductInInventory) {
    EXPECT_TRUE(store.isProductInInventory(1));  
    EXPECT_TRUE(store.isProductInInventory(2));  
    EXPECT_TRUE(store.isProductInInventory(3)); 
    EXPECT_FALSE(store.isProductInInventory(999));  
}

// Test for getProductById
TEST_F(StoreTest, GetProductById) {
    auto product = store.getProductById(1);
    EXPECT_TRUE(product.has_value());
    EXPECT_EQ(product->getID(), 1);
    EXPECT_EQ(product->getName(), "Apple");

    auto nonExistentProduct = store.getProductById(999);  // Assuming 999 is not a valid ID
    EXPECT_FALSE(nonExistentProduct.has_value());
}

/*-----Test Store: Admin Operation-----*/

// Test for add product
TEST_F(StoreTest, AddProduct) {

    // Simulate user input for product details
    simulateInput("4\nOrange\n20\n1\nFruit\n1\n");
    store.addProduct();

    const auto& inventory = store.getInventory();
    EXPECT_EQ(inventory.back().getID(), 4);
    EXPECT_EQ(inventory.back().getName(), "Orange");
    EXPECT_EQ(inventory.back().getQuantity(), 20);
    EXPECT_EQ(inventory.back().getPrice(), 1);
    EXPECT_EQ(inventory.back().getCategory(), "Fruit");
    EXPECT_TRUE(inventory.back().getIsStock());
}


// Test for update product info
TEST_F(StoreTest, UpdateProduct) {

    // Simulate user input for updating the product
    simulateInput("3\n2\n50\n3\n20\n");
    store.updateProduct();

    auto updatedProduct = store.getProductById(1);
    ASSERT_TRUE(updatedProduct.has_value());  
    EXPECT_EQ(updatedProduct->getQuantity(), 50);  // New quantity should be 50
    EXPECT_EQ(updatedProduct->getPrice(), 20);  // New price should be 2.0
}



















/*-----Test Customer-----*/

// Test adding items to the shopping cart
// TEST_F(StoreTest, AddItemToCart) {
//     simulateInput("1\nq\n"); // Assume customer adds id 1 to shopping cart
//     customer -> purchaseProduct();
//     EXPECT_EQ(customer -> getCartSize(), 1);  
// }

// Test removing item from the shopping cart
// TEST_F(StoreTest, RemoveItemInteractive) {
//     simulateInput("4\nq\n");  // Protend user enter '1' to remove the first item and 'q' to quit
//     customer -> removeItemFromCart();  
//     EXPECT_EQ(customer -> getCartSize(), 2);  
// }

// // Test finalizing order which might clear the cart
// TEST_F(StoreTest, FinalizeOrder) {
//     customer.finalizeOrder();
//     EXPECT_EQ(customer.getCartSize(), 0);
// }

// Test calculating total price
// TEST_F(StoreTest, CalculateTotalPrice) {
//     double totalPrice = customer.findTotalPrice();
//     EXPECT_EQ(totalPrice, 450.0);  // Total price from SetUp items
// }

// // Test providing feedback
// TEST_F(StoreTest, ProvideFeedback) {
//     simulateInput("Great service!\n");
//     customer.provideFeedback();

//     const auto& feedback = store.getFeedback(); 
//     ASSERT_FALSE(feedback.empty());  
//     EXPECT_EQ(feedback.back(), "Great service!");  // Verify the last feedback is as expected 
// }


