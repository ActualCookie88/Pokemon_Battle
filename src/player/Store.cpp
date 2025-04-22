#include "../../header/player/Store.h"
#include "../../header/Display.h"
#include <iostream>
#include <limits>

Store::~Store() {
    for (Item* item : storeItems) {
        delete item;
    }
    storeItems.clear();
}

void Store::initiateStore() {
    bool flag = true;
    int choice;

    while (flag) {
        display->displayStoreScreen();
        cout << "BALANCE: " << getMoney() << "¥" << endl << endl;
        cout << "Select an option: ";
        choice = selectOptionHelper(1, 4);

        while (cin.fail() || choice < 1 || choice > 4) {
            cout << "INVALID OPTION. TRY AGAIN: ";
            choice = clearInputHelper();
        }
        if (choice == 1) {
            buyItem();
        }
        else if (choice == 2) {
            sellItem();
        }
        else if (choice == 3) {
            viewMyItems(true);
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
        cout << "(9) BACK" << endl << endl;
        cout << "BALANCE: " << getMoney() << "¥" << endl << endl;
        cout << "(Enter CANCEL to cancel choice)" << endl << endl;
        cout << "Select item to buy: ";

        i = selectOptionHelper(1, storeItems.size()+1);
        if (i == -1) {
            cout << "BUY CANCELED" << endl;
            break;
        }

        if (i == 9) {
            return;
        }
        else {
            i -= 1;
            amount = amountHelper();
            if (amount == -1) {
                cout << "BUY CANCELED" << endl;
                break;
            }

            if (storeItems.at(i)->getCost() * amount > money) {
                cout << "INSUFFICIENT FUNDS." << endl << endl;
            }

            else {
                int moneyLost = storeItems.at(i)->getCost() * amount;
                money -= moneyLost;
                playerItems.at(i)->addAmount(amount);
                display->border();
                
                cout << "PURCHASED " << amount << " " << storeItems.at(i)->getName() 
                    << "(s) FOR " << moneyLost << "¥." << endl << endl;
            }
        }
        cout << "Options: " << endl;
        cout << "(1) BUY AGAIN" << endl;
        flag = selectOptionHelper2();
    }
}    

void Store::sellItem() {
    int i = 0;
    int amount = 0;
    bool flag = true;

    while (flag) {
        viewMyItems(false);
        cout << "(9) BACK" << endl << endl;
        cout << "BALANCE: " << getMoney() << "¥" << endl << endl;
        cout << "(Enter CANCEL to cancel choice)" << endl << endl;
        cout << "Select item to sell: ";
        i = selectOptionHelper(1, playerItems.size()+1);
        
        if (i == -1) {
            cout << "SELL CANCELED" << endl;
            break;
        }
        if (i == 9) {
            return;
        }
        else {
            i -= 1;
            amount = amountHelper();
            if (amount == -1) {
                cout << "SELL CANCELED" << endl;
                break;
            }
            
            if (playerItems.at(i)->getAmount() < amount) {
                
                cout << "INSUFFICIENT AMOUNT." << endl << endl;
            }
            else {  
                playerItems.at(i)->sellAmount(amount);
                int moneyGained = (playerItems.at(i)->getCost() / 2) * amount;
                money += moneyGained;
                display->border();
                cout << amount << " " << storeItems.at(i)->getName() << "(s) SOLD. "
                     << "RECEIVED " << moneyGained << "¥." << endl << endl;
            }
        } 
        cout << "(1) SELL AGAIN" << endl;
        flag = selectOptionHelper2();
    }
}

void Store::viewMyItems(bool isViewing) {
    int i = 0;
    display->displayItemScreen();

    for (int i = 0; i < playerItems.size(); ++i) {
        if(!isViewing) {
            cout << "(" << i + 1 << ") ";
        }  
        playerItems.at(i)->displayInfo2();
        if (i != playerItems.size()) {
            cout << endl;
        }
    }
    if(isViewing) {
        cout << "(1) BACK" << endl << endl;
        cout << "Select an option: ";
        cin >> i;
        while (cin.fail() || i != 1) {
            cout << "INVALID OPTION. TRY AGAIN: ";
            i = clearInputHelper();
        }
        return;
    }
}

void Store::viewStoreItems() const {
    int count = 1;
    display->border();
    cout << "STORE: " << endl << endl;

    for (int i = 0; i < storeItems.size(); ++i) {
        cout << "(" << i + 1 << ") ";
        storeItems.at(i)->displayInfo();
        cout << endl;
    }
}

void Store::viewItemStats(int itemNum) const {
    display->border();
    cout << "(" << itemNum << ") ";
    storeItems.at(itemNum-1)->displayInfo();
    cout << endl;
}

void Store::setAllAmount(int amount) {
    for( Item* item : playerItems) {
        item->setAmount(amount);
    }
}

int Store::clearInputHelper() {
    int i = 0;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> i;
    cout << endl;
    return i;
}

int Store::selectOptionHelper(int min, int max) {
    string input;
    int number;
    while (true) {
        cin >> input;
        cout << endl;

        if (input == "CANCEL") {
            return -1;
        }

        try {
            number = stoi(input); // if fails, throws exception to catch
        } catch (...) {
            cout << "INVALID OPTION. TRY AGAIN: ";
            continue;
        }

        if (number >= min && number <= max) {
            return number;
        } else {
            cout << "INVALID OPTION. TRY AGAIN: ";
        }
    }
}

int Store::validateInput(int input, int min, int max) {
    while (cin.fail() || input < min || input > max) {
        cout << "INVALID OPTION. TRY AGAIN: ";
        input = clearInputHelper();
    }
    return input;
}

int Store::amountHelper() {
    string input;
    int amount;

    cout << "Select amount: ";

    while (true) {
        cin >> input;
        cout << endl;

        if (input == "CANCEL") {
            return -1;
        }

        try {
            amount = stoi(input); // throws if not a number
        } catch (...) {
            cout << "INVALID AMOUNT. TRY AGAIN: ";
            continue;
        }

        if (amount >= 1) {
            return amount;
        } else {
            cout << "INVALID AMOUNT. TRY AGAIN: ";
        }
    }
}

bool Store::selectOptionHelper2() {
    bool flag = true;
    int i = 0;
    cout << "(2) BACK" << endl << endl;
    cout << "BALANCE: " << money << "¥" << endl << endl;
    cout << "Select an option: ";

    cin >> i;
    cout << endl; 

    while (cin.fail() || i < 1 || i > 2) {
        cout << "INVALID OPTION. TRY AGAIN: ";
        i = clearInputHelper();
    }

    if (i == 2) {
        flag = false;
    }

    return flag;
}