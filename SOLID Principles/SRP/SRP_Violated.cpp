#include <iostream>
#include <vector>

using namespace std;

// Product class represented any items of any Ecommerce.
class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price; 
    }
};

// Violating SRP: Shopping cart handling multiple responsibilities

class ShoppingCart {
private:
    vector<Product*> products;
    
public:
    void addProducts(Product* p){
        products.push_back(p);
    }

    const vector<Product*>& getProducts(){
        return products;
    }

    // 1. calculate total prince in cart
    double calculateTotal(){
        double total = 0;
        for (auto p : products){
            total += p->price;
        }
        return total;
    }

    // 2. violating SRP - Prints invoice (Should be in a seperate class)
    void printInvoice(){
        cout << "Shopping Cart Invoice:\n";
        for (auto p : products) {
            cout << p->name<< " - $ " << p->price << endl;
        }
        cout<< "total: $" << calculateTotal() << endl;
    }

    // 3. violating SRP - Save to DB (Should be in seperate class)
    void saveToDatabase(){
        cout << "Saving shoppong cart to database..."<< endl;
    }

};

int main() {
    ShoppingCart* cart = new ShoppingCart();
    
    cart->addProducts(new Product("laptop", 1500));
    cart->addProducts(new Product("Mouse", 50));

    cart->printInvoice();
    cart->saveToDatabase();

    return 0;
}