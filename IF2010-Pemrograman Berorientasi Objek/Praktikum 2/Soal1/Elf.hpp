#pragma once
#include "Creature.hpp"
#include <iostream>
#include <string>


class Elf : public Creature {
protected:
    int grace;

public:
    Elf(string name, int hp, int grace);
    void describe() const override;
    int getGrace();
};