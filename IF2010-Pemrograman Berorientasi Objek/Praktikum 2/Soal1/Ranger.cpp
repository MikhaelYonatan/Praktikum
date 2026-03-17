#include "Ranger.hpp"

Ranger::Ranger(string name, int hp, int grace, int arrow)
       :Elf(name, hp, grace), arrow(arrow){};

void Ranger::describe() const {
    cout << "Ranger [" << name << "] | HP: " <<  hp << " | Grace: " << grace << " | Arrows: " << arrow << endl;
}

void Ranger::shoot() {
    arrow -= 1;
    cout << name << " draws an arrow (grace: " << grace << ") and fires! Arrows left: " << arrow << endl;
}