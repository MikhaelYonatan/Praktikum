#include "Elf.hpp"

Elf::Elf(string name, int hp, int grace)
    :Creature(name, hp), grace(grace) {}

void Elf::describe() const {
    cout << "Elf [" << name << "] | HP: " <<  hp << " | Grace: " << grace << endl;
}

int Elf::getGrace() {
    return grace;
}