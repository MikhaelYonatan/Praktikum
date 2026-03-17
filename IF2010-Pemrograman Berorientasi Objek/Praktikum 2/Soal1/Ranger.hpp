#pragma once
#include "Elf.hpp"
#include <iostream>
#include <string>


class Ranger : public Elf {
private:
    int arrow;

public:
    Ranger(string name, int hp, int grace, int arrow);
    void describe() const override;
    void shoot();
};