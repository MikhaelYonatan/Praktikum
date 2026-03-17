#pragma once
#include "Maiar.hpp"
#include <iostream>
#include <string>


class Balrog : public Maiar {
private:
    string whipName;

public:
    Balrog(string name, int hp, int power, string whipName);
    void describe() const override;
    void rage();
};