#ifndef DISPLAYSCREEN_H
#define DISPLAYSCREEN_H

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class DisplayScreen {
    public:
        virtual void displayMenu() const = 0;

        virtual ~DisplayScreen() = default;
};

#endif