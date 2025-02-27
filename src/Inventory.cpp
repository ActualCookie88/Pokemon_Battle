#include "../header/Inventory.h"

Inventory::~Inventory()
{
    for (int i = 0; i < items.size(); ++i)
    {
        delete items.at(i);
    }
}

void Inventory::store()
{
    bool flag = true;
    int choice = 0;
    cout << endl << "Welcome to the Poké Mart!" << endl << endl;

    while (flag)
    {
        cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        cout << " __________________________________________________" << endl;
        cout << "|                                                  |" << endl;
        cout << "|     _____   _______   _____   _____    _____     |" << endl;
        cout << "|    |  ___| |__   __| |  _  | |  _  \\  |  ___|    |" << endl;
        cout << "|    | |___     | |    | | | | | |_)  | | |___     |" << endl;
        cout << "|    |___  |    | |    | | | | |  _  /  |  ___|    |" << endl;
        cout << "|     ___| |    | |    | |_| | | | \\ \\  | |___     |" << endl;
        cout << "|    |_____|    |_|    |_____| |_|  \\_\\ |_____|    |" << endl;
        cout << "|                                                  |" << endl;
        cout << "|__________________________________________________|" << endl;
        cout << endl;
        cout << "Options:" << endl;
        cout << "(1) Buy Items" << endl;
        cout << "(2) Sell Items" << endl;
        cout << "(3) View My Items" << endl;
        cout << "(4) Exit Poké Mart" << endl << endl;
        cout << "Current Balance: " << getMoney() << "¥" << endl << endl;
        cout << "Select an option: ";
        cin >> choice;
        cout << endl;

        while (cin.fail() || choice < 1 || choice > 4)
        {
            cout << "Invalid option. Try again: ";
            choice = clearInputHelper();
        }
        if (choice == 1)
        {
            buyItem();
        }
        else if (choice == 2)
        {
            sellItem();
        }
        else if (choice == 3)
        {
            viewMyItems();
        }
        else if (choice == 4)
        {
            flag = false;
        }
    }
}

void Inventory::viewMyItems()
{
     cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << " _____________________________________________________" << endl;
    cout << "|                                                     |" << endl;
    cout << "|     _______   _______   _____   _     _   _____     |" << endl;
    cout << "|    |__   __| |__   __| |  ___| | \\   / | |  ___|    |" << endl;
    cout << "|       | |       | |    | |___  |  \\ /  | | |___     |" << endl;
    cout << "|       | |       | |    |  ___| | |\\ /| | |___  |    |" << endl;
    cout << "|     __| |__     | |    | |___  | |   | |  ___| |    |" << endl;
    cout << "|    |_______|    |_|    |_____| |_|   |_| |_____|    |" << endl;
    cout << "|                                                     |" << endl;
    cout << "|_____________________________________________________|" << endl;
    cout << endl;
    cout << "Current Items:" << endl << endl;

    for (int i = 0; i < items.size(); ++i)
    {
        cout << "(" << i + 1 << ") Name: " << items.at(i)->getName() << endl;
        cout << "    Amount: " << items.at(i)->getAmount() << endl;
        if (i != items.size() - 1)
        {
            cout << endl;
        }
    }
}

void Inventory::storeItems()
{
    int count = 1;
    cout << "Store:" << endl;

    for (int i = 0; i < items.size(); ++i)
    {
        cout << "(" << i + 1 << ") ";
        items.at(i)->displayInformation();
        cout << endl;
    }
}

void Inventory::buyItem()
{
    int i = 0;
    int amount = 0;
    bool flag = true;

    while (flag)
    {
        storeItems();
        cout << "(9) Go Back" << endl << endl;
        cout << "Current Balance: " << getMoney() << "¥" << endl << endl;
        cout << "Select which item to buy: ";
        i = selectOptionHelper1();

        if (i == 8)
        {
            return;
        }
        else
        {
            amount = amountHelper();

            if (items.at(i)->getPrice() * amount > money)
            {
                cout << "Insufficient funds." << endl << endl;
            }

            else
            {
                items.at(i)->addAmount(amount);
                money -= items.at(i)->getPrice() * amount;
                cout << "Item(s) added!" << endl << endl;
            }
        }
        cout << "(1) Buy another item" << endl;
        flag = selectOptionHelper2();
    }
}

void Inventory::sellItem()
{
    int i = 0;
    int amount = 0;
    bool flag = true;

    while (flag)
    {
        viewMyItems();
        
        cout << "(9) Go Back" << endl << endl;
        cout << "Current Balance: " << getMoney() << "¥" << endl << endl;
        cout << "Select which item to sell: ";

        i = selectOptionHelper1();

        if (i == 8)
        {
            return;
        }
        else
        {
            amount = amountHelper();
            
            if (items.at(i)->getAmount() < amount)
            {
                cout << "Insufficient amount." << endl << endl;
            }
            else
            {
                items.at(i)->sellAmount(amount);
                money += (items.at(i)->getPrice() / 2) * amount;
                cout << "Item(s) sold." << endl << endl;
            }
        } 
        cout << "(1) Sell another item" << endl;
        flag = selectOptionHelper2();
    }
}

void Inventory::addMoney(int amount)
{
    money += amount;
}

int Inventory::getMoney()
{
    return money;
}

int Inventory::clearInputHelper()
{
    int i = 0;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> i;
    --i;
    cout << endl;

    return i;
}

int Inventory::selectOptionHelper1()
{
    int i = 0;

    cin >> i;
    --i;
    cout << endl;


    while (cin.fail() || i < 0 || i > 8)
    {
        cout << "Invalid option. Try again: ";
        i = clearInputHelper();
    }

    return i;
}

int Inventory::amountHelper()
{
    int amount = 0;
    cout << "Enter amount: ";
    cin >> amount;

    while (cin.fail() || amount < 1)
    {
        cout << "Invalid amount. Try again: ";
        amount = clearInputHelper();
    }

    return amount;
}

bool Inventory::selectOptionHelper2()
{
    bool flag = true;
    int i = 0;
    cout << "(2) Go Back" << endl;
    cout << "Current Balance: " << getMoney() << "¥" << endl;
    cout << "Select an option: ";

    cin >> i;
    cout << endl; 

    while (cin.fail() || i < 1 || i > 2)
    {
        cout << "Invalid option. Try again: ";
        i = clearInputHelper();
    }

    if (i == 2)
    {
        flag = false;
    }

    return flag;
}

bool Inventory::useItems(string name)
{
    if (name == "Pokeball")
    {
        if (items.at(0)->getAmount() == 0)
        {
            cout << "You don't have any Pokeballs!" << endl;
            return false;
        }
    }
    else if (name == "Great Ball")
    {
        if (items.at(0)->getAmount() == 0)
        {
            cout << "You don't have any Great Balls!" << endl;
            return false;
        }
    }
    else if (name == "Ultra Ball")
    {
        if (items.at(0)->getAmount() == 0)
        {
            cout << "You don't have any Ultra Balls!" << endl;
            return false;
        }
    }
    else if (name == "Potion")
    {
        if (items.at(0)->getAmount() == 0)
        {
            cout << "You don't have any Potions!" << endl;
            return false;
        }
    }
    else if (name == "Super Potion")
    {
        if (items.at(0)->getAmount() == 0)
        {
            cout << "You don't have any Super Potions!" << endl;
            return false;
        }
    }
    else if (name == "Hyper Potion")
    {
        if (items.at(0)->getAmount() == 0)
        {
            cout << "You don't have any Hyper Potions!" << endl;
            return false;
        }
    }
    else if (name == "Revive")
    {
        if (items.at(0)->getAmount() == 0)
        {
            cout << "You don't have any Revives!" << endl;
            return false;
        }
    }
    else if (name == "Max Revive")
    {
        if (items.at(0)->getAmount() == 0)
        {
            cout << "You don't have any Max Revives!" << endl;
            return false;
        }
    }

    return true;
}