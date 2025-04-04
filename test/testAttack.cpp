#include "../header/Pokemon/attack.h"
#include <iostream>

using namespace std;

int main() {
    Attack* fireSpin = new Attack(Moves::FireSpin);

    cout << "Name: " << fireSpin->getName() << endl;
    cout << "Type: " << fireSpin->typeToString(fireSpin->getType()) << endl;
    cout << "Power: " << fireSpin->getPower() << endl;
    cout << endl;

    if(fireSpin->isSuperEffective(Type::Grass)) {
        cout << fireSpin->getName() << " was Super Effective! " << endl;
    }
    if(fireSpin->isNotVeryEffective(Type::Water)) {
        cout << fireSpin->getName() << " was Not Very Effective! " << endl;
    }

    delete fireSpin;
    return 0;
}