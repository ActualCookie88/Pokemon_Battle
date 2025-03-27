#pragma once
#include <string>
#include "moves.h"
#include "type.h"
using std::string;

class Attack {
    private:
        Moves name;
        Type type;
        int power;
        
    public:
        Attack();
        Attack(Moves name);
        Attack& operator=(const Attack& other);
        // actions
        bool isSuperEffective(Type targetType) const;
        bool isNotVeryEffective(Type targetType) const;
        string typeToString(Type type);
        // getters
        string getName() const;
        Type getType() const;
        int getPower() const;
};
