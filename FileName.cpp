#include <iostream>
#include <string>

using namespace std;

// Base class
class CustomerData {
private:
    string customerName;
    string customerAddress;
    string customerPhone;
    int customerNumber;
    bool mailingList;

public:
    // Constructor
    CustomerData(string name, string address, string phone, int number, bool list)
        : customerName(name), customerAddress(address), customerPhone(phone), customerNumber(number), mailingList(list) {}

    // Display function
    void displayCustomer() const {
        cout << "Customer Name: " << customerName << endl;
        cout << "Customer Address: " << customerAddress << endl;
        cout << "Customer Phone: " << customerPhone << endl;
        cout << "Customer Number: " << customerNumber << endl;
        cout << "Mailing List: " << (mailingList ? "Yes" : "No") << endl;
    }
};

// Derived class
class PreferredCustomer : public CustomerData {
private:
    double purchasesAmount;
    double discountLevel;

public:
    // Constructor
    PreferredCustomer(string name, string address, string phone, int number, bool list, double purchases)
        : CustomerData(name, address, phone, number, list), purchasesAmount(purchases) {
        updateDiscountLevel();
    }

    // Function to update discount level based on purchases
    void updateDiscountLevel() {
        if (purchasesAmount >= 5000.0) {
            discountLevel = 0.10;
        }
        else if (purchasesAmount >= 500.0) {
            discountLevel = 0.07;
        }
        else if (purchasesAmount >= 1000.0) {
            discountLevel = 0.06;
        }
        else if (purchasesAmount >= 500.0) {
            discountLevel = 0.05;
        }
        else {
            discountLevel = 0.0;
        }
    }

    // Function to display preferred customer information
    void displayPreferredCustomer() const {
        displayCustomer();  // Inherited function from base class
        cout << "Purchases Amount: $" << purchasesAmount << endl;
        cout << "Discount Level: " << (discountLevel * 100) << "%" << endl;
    }
};

int main() {
    // Create a PreferredCustomer object
    PreferredCustomer customer("Hafsa", "273 St 78", "1234-5678", 12345, true, 1500.0);

    // Display the information
    customer.displayPreferredCustomer();

    return 0;
}
