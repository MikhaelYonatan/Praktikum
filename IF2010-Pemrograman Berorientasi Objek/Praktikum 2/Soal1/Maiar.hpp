#pragma once
#include "Creature.hpp"
#include <iostream>
#include <string>

class Maiar : protected Creature{
protected:
    int power;
    Maiar(const string& name, int hp, int power);

public:
    void describe() const override;
    int getPower();
};