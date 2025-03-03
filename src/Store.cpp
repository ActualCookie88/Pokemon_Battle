#include "../header/Store.h"
#include "../header/Display.h"
#include <iostream>
#include <limits>

void Store::initiateStore() {
    bool flag = true;
    int choice = 0;
    Display* display;

    while (flag) {
        display->displayStoreScreen();
        cout << "Current Balance: " << getMoney() << "¥" << endl << endl;
        cout << "Select an option: ";
        cin >> choice;
        cout << endl;

        while (cin.fail() || choice < 1 || choice > 4) {
            cout << "Invalid option. Try again: ";
            choice = clearInputHelper();
        }
        if (choice == 1) {
            buyItem();
        }
        else if (choice == 2) {
            sellItem();
        }
        else if (choice == 3) {
            viewMyItems();
        }
        else if (choice == 4) {
            flag = false;
        }
    }
}

void Store::buyItem() {
    int i = 0;
    int amount = 0;
    bool flag = true;

    while (flag) {
        viewStoreItems();
        cout << "(9) Go Back" << endl << endl;
        cout << "Current Balance: " << getMoney() << "¥" << endl << endl;
        cout << "Select which item to buy: ";
        i = selectOptionHelper1();

        if (i == 8) {
            return;
        }
        else {
            amount = amountHelper();

            if (storeItems.at(i)->getCost() * amount > money) {
                cout << "Insufficient funds." << endl << endl;
            }

            else {
                storeItems.at(i)->addAmount(amount);
                money -= storeItems.at(i)->getCost() * amount;
                cout << "Item(s) added!" << endl << endl;
            }
        }
        cout << "(1) Buy another item" << endl;
        flag = selectOptionHelper2();
    }
}    

void Store::sellItem() {
    int i = 0;
    int amount = 0;
    bool flag = true;

    while (flag) {
        viewMyItems();
        if(playerItems.size() < 1) {
            cout << "(1) Go Back" << endl;
            cout << "Select an option: ";
            cin >> i;
            while (cin.fail() || i != 1) {
                cout << "Invalid option. Try again: ";
                i = clearInputHelper();
            }
            return;
        }
        
        cout << "(9) Go Back" << endl << endl;
        cout << "Current Balance: " << getMoney() << "¥" << endl << endl;
        cout << "Select which item to sell: ";

        i = selectOptionHelper1();

        if (i == 8) {
            return;
        }
        else
        {
            amount = amountHelper();
            
            if (playerItems.at(i)->getAmount() < amount)
            {
                cout << "Insufficient amount." << endl << endl;
            }
            else
            {
                playerItems.at(i)->sellAmount(amount);
                money += (playerItems.at(i)->getCost() / 2) * amount;
                cout << "Item(s) sold." << endl << endl;
            }
        } 
        cout << "(1) Sell another item" << endl;
        flag = selectOptionHelper2();
    }
}

void Store::viewMyItems() {
    Display* display;
    display->displayItemScreen();

    if(playerItems.size() < 1) {
        int i;
        cout << "No items owned!" << endl << endl;
        cout << "(1) Go Back" << endl;
            cout << "Select an option: ";
            cin >> i;
            while (cin.fail() || i != 1) {
                cout << "Invalid option. Try again: ";
                i = clearInputHelper();
            }
            return;
        return;
    }

    for (int i = 0; i < playerItems.size(); ++i) {
        cout << "(" << i + 1 << ") Name: " << playerItems.at(i)->getName() << endl;
        cout << "    Amount: " << playerItems.at(i)->getAmount() << endl;
        if (i != playerItems.size() - 1) {
            cout << endl;
        }
    }
}

void Store::viewStoreItems() const {
    int count = 1;
    cout << "Store:" << endl;

    for (int i = 0; i < storeItems.size(); ++i)
    {
        cout << "(" << i + 1 << ") ";
        storeItems.at(i)->displayInfo();
        cout << endl;
    }
}

int Store::amountHelper() {
    int amount = 0;
    cout << "Enter amount: ";
    cin >> amount;

    while (cin.fail() || amount < 1) {
        cout << "Invalid amount. Try again: ";
        amount = clearInputHelper();
    }

    return amount;
}

int Store::clearInputHelper() {
    int i = 0;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> i;
    //--i;
    cout << endl;

    return i;
}

int Store::selectOptionHelper1() {
    int i = 0;

    cin >> i;
    --i;
    cout << endl;


    while (cin.fail() || i < 0 || i > 8) {
        cout << "Invalid option. Try again: ";
        i = clearInputHelper();
    }

    return i;
}

bool Store::selectOptionHelper2() {
    bool flag = true;
    int i = 0;
    cout << "(2) Go Back" << endl;
    cout << "Current Balance: " << getMoney() << "¥" << endl;
    cout << "Select an option: ";

    cin >> i;
    cout << endl; 

    while (cin.fail() || i < 1 || i > 2) {
        cout << "Invalid option. Try again: ";
        i = clearInputHelper();
    }

    if (i == 2) {
        flag = false;
    }

    return flag;
}