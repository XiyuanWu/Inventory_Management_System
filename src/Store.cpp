#include "../header/Store.h"

using namespace std;

/*-----Get inventory content-----*/
bool Store::isProductInInventory(int id) const {

    return any_of(inventory.begin(), inventory.end(), [id](const Inventory& item) {
        return item.getID() == id;
    });
}

optional<Inventory> Store::getProductById(int id) const {

    for (const auto& product: inventory) {
        if (product.getID() == id) {
            return product;
        }
    }
    return nullopt;
}
