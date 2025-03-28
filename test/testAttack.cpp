#include "../header/Pokemon/attack.h"
#include <iostream>

using namespace std;

int main() {
    Attack* fireSpin = new Attack(Moves::FireSpin);

    cout << "Name: " << fireSpin->getName() << endl;
    cout << "Type: " << fireSpin->typeToString(fireSpin->getType()) << endl;
    cout << "Power: " << fireSpin->getPower() << endl;

    delete fireSpin;
    return 0;
}