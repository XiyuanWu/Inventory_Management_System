// #include "gtest/gtest.h"
// #include "../src/Customer.h"
// #include "../src/Admin.h"
// #include "../header/Inventory.h"
// #include <sstream>

// using namespace std;

// class CustomerTest : public ::testing::Test {
//   protected:
//     void SetUp() override {
//         inventory.push_back(Inventory(1, "Apple", 10, 5.0, "Fruit", true));
//         inventory.push_back(Inventory(2, "Beef", 5, 20.0, "Meat", true));
//         inventory.push_back(Inventory(3, "Fish", 20, 15.0, "Seafood", true));

//         for (const auto& item : inventory) {
//             admin.addProduct(item);
//         }

//         customer = new Customer(admin);
//     }

//     void TearDown() override {
//         delete customer;
//     }

//     vector<Inventory> inventory;
//     Admin admin;
//     Customer* customer;
// };

// // Test case for browseProducts method
// TEST_F(CustomerTest, BrowseProductsTest) {
//     testing::internal::CaptureStdout();
//     customer->browseProducts();
//     string output = testing::internal::GetCapturedStdout();
//     EXPECT_NE(output.find("Product1"), string::npos);
//     EXPECT_NE(output.find("Product2"), string::npos);
//     EXPECT_NE(output.find("Product3"), string::npos);
// }

// // Test case for provideFeedback method
// TEST_F(CustomerTest, ProvideFeedbackTest) {
//     testing::internal::CaptureStdout();
//     istringstream input("Great product!\n");
//     cin.rdbuf(input.rdbuf());
//     customer->provideFeedback();
//     string output = testing::internal::GetCapturedStdout();
//     EXPECT_NE(output.find("Please provide your feedback here:"), string::npos);
//     // Check that the feedback was added
//     // Assuming there is a way to retrieve feedback
// }

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
