#pragma once
#include "Maiar.hpp"
#include <iostream>
#include <string>


class Wizard : private Maiar {
private:
    string staffName;

public:
    Wizard(string name, int hp, int power, string staffName);
    void describe() const override;
    void cast();
};