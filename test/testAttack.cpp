#include "../header/Pokemon/attack.h"
#include <iostream>

using namespace std;

int main() {
    Attack* attack = new Attack(moves::FireSpin);

    cout << "Attack name: " << attack->getName() << endl;
    cout << "Attack power: " << attack->getpower() << endl;

    return 0;
}