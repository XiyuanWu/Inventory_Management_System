# Class Explanation

### 1. **Inventory Class**
This class represents individual inventory items.

**Attributes:**
- `id (int)`: Unique identifier for each product.
- `name (string)`: Product name.
- `quantity (int)`: Number of items available.
- `price (double)`: Cost per item.
- `category (string)`: Product category.
- `status (bool)`: Availability of the product (true for in stock, false for out of stock).

**Methods:**
- `int getID() const`: Returns the product ID.
- `string getName() const`: Returns the product name.
- `int getQuantity() const`: Returns the quantity available.
- `double getPrice() const`: Returns the price.
- `string getCategory() const`: Returns the category.
- `bool getStatus() const`: Returns the availability status.
- `void setID(int)`: Sets the product ID.
- `void setName(string)`: Sets the product name.
- `void setQuantity(int)`: Sets the quantity.
- `void setPrice(double)`: Sets the price.
- `void setCategory(string)`: Sets the category.
- `void setStatus(bool)`: Sets the availability status.

### 2. **Customer Class**
Manages customer interactions with the system.

**Attributes:**
- `feedback (vector<string>)`: List of customer feedback strings.
- `shopping_cart (vector<inventory>`: List of customer's shopping cart.

**Methods:**
- `void browseProducts() const`: Displays products available for purchase.
- `void purchaseProduct(int productID, int quantity)`: Adds product to cart and initiates purchase.
- `void displayShoppingCart()`: Shows items in the shopping cart.
- `void viewOrder() const`: Displays details of customer's orders.
- `double findPrice(int productID)`: Calculate total item prices in shopping cart.
- `void provideFeedback(string feedback)`: Allows customers to provide feedback.

### 3. **Admin Class**
Handles administrative tasks related to inventory and order management.

**Attributes:**
- `inventory (vector<Inventory>)`: A list of all inventory items.

**Methods:**
- `void addProduct(const Inventory&)`: Adds a new product to the inventory.
- `void updateProduct(int productID, const Inventory&)`: Updates existing product information.
- `void removeProduct(int productID)`: Removes a product from inventory.
- `void viewInventory() const`: Displays all items in the inventory.
- `void viewAllOrders() const`: Shows all customer orders.
- `void updateOrder(int orderID)`: Updates details of an existing order.
- `void recordSale(int productID, int quantity)`: Records a sale transaction.
- `void salesReport() const`: Generates a sales report.
- `void inventoryReport() const`: Generates an inventory status report.
- `void backupRestore()`: Handles backup and restoration of system data.
- `void systemSettings()`: Manages system settings.
- `void displayFeedback()`: Displays customer feedback.

### 4. Enhanced Class
This class offer features that enhance user interaction, simplify system operations, or provide advanced functionality.

**Attributes:**
TBD

**Methods:**
- `void searchFunctionality()`: Enhances search capabilities across the system, possibly offering advanced filtering options or a more sophisticated search algorithm that can handle complex queries.
- `void clearSession()`: Manages session data, useful for resetting or clearing user session data after a transaction or when logging out.
- `void reviewSession()`: Allows for the auditing or reviewing of session data, which could be used for security audits, troubleshooting, or enhancing user interaction patterns.
