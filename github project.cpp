#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class MenuItem {
public:
    string name;
    double price;
    
    MenuItem(string n, double p) {
        name = n;
        price = p;
    }

    void displayItem() {
        cout << left << setw(20) << name << "$" << setw(6) << price << endl;
    }
};

class Order {
public:
    MenuItem* item;
    int quantity;

    Order(MenuItem* m, int q) {
        item = m;
        quantity = q;
    }

    double calculateTotal() {
        return item->price * quantity;
    }

    void displayOrder() {
        cout << left << setw(20) << item->name 
             << setw(10) << quantity 
             << "$" << setw(6) << item->price 
             << "$" << setw(6) << calculateTotal() << endl;
    }
};

class Restaurant {
private:
    vector<MenuItem> menu;
    vector<Order> orders;

public:
    Restaurant() {
        // Predefined menu items
        menu.push_back(MenuItem("Burger", 5.99));
        menu.push_back(MenuItem("Pizza", 8.99));
        menu.push_back(MenuItem("Pasta", 7.49));
        menu.push_back(MenuItem("Salad", 4.99));
        menu.push_back(MenuItem("Soda", 1.99));
    }

    void displayMenu() {
        cout << "********** Menu **********" << endl;
        for (int i = 0; i < menu.size(); ++i) {
            menu[i].displayItem();
        }
        cout << "***************************" << endl;
    }

    void takeOrder() {
        int choice, quantity;
        cout << "Enter the item number to order or 0 to finish: ";
        while (true) {
            cin >> choice;
            if (choice == 0) break;

            if (choice < 1 || choice > menu.size()) {
                cout << "Invalid item number. Try again: ";
                continue;
            }

            cout << "Enter quantity: ";
            cin >> quantity;

            orders.push_back(Order(&menu[choice - 1], quantity));
            cout << "Enter next item number or 0 to finish: ";
        }
    }

    void generateBill() {
        double total = 0;
        cout << "\n********** Bill **********" << endl;
        cout << left << setw(20) << "Item Name" 
             << setw(10) << "Quantity" 
             << setw(10) << "Price" 
             << setw(10) << "Total" << endl;

        for (int i = 0; i < orders.size(); ++i) {
            orders[i].displayOrder();
            total += orders[i].calculateTotal();
        }

        cout << "\n***************************" << endl;
        cout << "Total Bill: $" << fixed << setprecision(2) << total << endl;
        cout << "***************************" << endl;
    }
};

int main() {
    Restaurant restaurant;
    
    while (true) {
        int choice;
        cout << "\n********** Restaurant Management System **********" << endl;
        cout << "1. Display Menu" << endl;
        cout << "2. Take Order" << endl;
        cout << "3. Generate Bill" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                restaurant.displayMenu();
                break;
            case 2:
                restaurant.takeOrder();
                break;
            case 3:
                restaurant.generateBill();
                break;
            case 4:
                cout << "Thank you for using the Restaurant Management System!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
