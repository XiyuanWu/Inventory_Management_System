#include "gtest/gtest.h"
#include "./header/Admin.h"
#include "./header/Customer.h"
#include "./header/Inventory.h"
#include "./header/Store.h"
#include <sstream>
#include <gtest/gtest.h>

using namespace std;

class InventoryTest : public ::testing::Test {
  protected:
    void SetUp() override {
        inventory.push_back(Inventory(1, string("Apple"), 10, 5.0, string("Fruit"), true));
        inventory.push_back(Inventory(2, string("Beef"), 5, 20.0, string("Meat"), true));
        inventory.push_back(Inventory(3, string("Fish"), 20, 15.0, string("Seafood"), true));

        for (const auto& item: inventory) {
            store.addProduct(item);
        }
    }

    vector<Inventory> inventory;
    Store store;
    Admin admin;
    Customer customer;

    void simulateInput(const string& input) {
        static istringstream iss(input);
        cin.rdbuf(iss.rdbuf());   // Redirect cin to read from iss
    }
};

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*-----Test Store-----*/

// Test for getInventory
TEST_F(InventoryTest, GetInventory) {
    const auto& inv = store.getInventory();
    EXPECT_EQ(inv.size(), 3);  // We added 3 items in SetUp
    EXPECT_EQ(inv[0].getName(), "Apple");
    EXPECT_EQ(inv[1].getName(), "Beef");
    EXPECT_EQ(inv[2].getName(), "Fish");
}

// Test for getOrderHistory
TEST_F(InventoryTest, GetOrderHistory) {
    const auto& orderHistory = store.getOrderHistory();
    EXPECT_TRUE(orderHistory.empty());  // Initially, order history should be empty
}

// Test for isProductInInventory
TEST_F(InventoryTest, IsProductInInventory) {
    EXPECT_TRUE(store.isProductInInventory(1));  
    EXPECT_TRUE(store.isProductInInventory(2));  
    EXPECT_TRUE(store.isProductInInventory(3)); 
    EXPECT_FALSE(store.isProductInInventory(999));  
}

// Test for getProductById
TEST_F(InventoryTest, GetProductById) {
    auto product = store.getProductById(1);
    EXPECT_TRUE(product.has_value());
    EXPECT_EQ(product->getID(), 1);
    EXPECT_EQ(product->getName(), "Apple");

    auto nonExistentProduct = store.getProductById(999);  // Assuming 999 is not a valid ID
    EXPECT_FALSE(nonExistentProduct.has_value());
}

/*-----Test Customer-----*/

// Test adding items to the shopping cart
TEST_F(InventoryTest, AddItemToCart) {
    simulateInput("1\nq\n"); // Assume customer adds id 1 to shopping cart
    customer.purchaseProduct();
    EXPECT_EQ(customer.getCartSize(), 1);  
}

// // Test removing item from the shopping cart
// TEST_F(InventoryTest, RemoveItemInteractive) {
//     simulateInput("4\nq\n");  // Protend user enter '1' to remove the first item and 'q' to quit
//     customer.removeItemFromCart();  
//     EXPECT_EQ(customer.getCartSize(), 3);  
// }

// // Test finalizing order which might clear the cart
// TEST_F(InventoryTest, FinalizeOrder) {
//     customer.finalizeOrder();
//     EXPECT_EQ(customer.getCartSize(), 0);
// }

// Test calculating total price
// TEST_F(InventoryTest, CalculateTotalPrice) {
//     double totalPrice = customer.findTotalPrice();
//     EXPECT_EQ(totalPrice, 450.0);  // Total price from SetUp items
// }

// // Test providing feedback
// TEST_F(InventoryTest, ProvideFeedback) {
//     simulateInput("Great service!\n");
//     customer.provideFeedback();

//     const auto& feedback = store.getFeedback(); 
//     ASSERT_FALSE(feedback.empty());  
//     EXPECT_EQ(feedback.back(), "Great service!");  // Verify the last feedback is as expected 
// }


