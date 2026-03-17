#include "Warrior.hpp"

Warrior::Warrior(string characterId, string name, int hp, int level, int strength)
        :Character(characterId, name, hp, level), strength(strength) {
    cout << "[CREATE] Warrior " << name << " with " << strength << " str ready" << endl;
}

Warrior::~Warrior() {
    cout << "[DELETE] Warrior " << name << " destroyed" << endl;
}

void Warrior::attack() const {
    cout << "[ATTACK] " << name << " attacks with " << strength << " strength" << endl;
}

int Warrior::getStrength() const {
    return strength;
}

