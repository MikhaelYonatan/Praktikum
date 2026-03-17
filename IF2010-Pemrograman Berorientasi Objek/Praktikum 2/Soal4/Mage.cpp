#include "Mage.hpp"

Mage::Mage(string characterId, string name, int hp, int level, int mana)
     :Character(characterId, name, hp, level), mana(mana) {
    cout << "[CREATE] Mage " << name << " with " << mana << " mana ready" << endl;
}

Mage::~Mage() {
    cout << "[DELETE] Mage " << name << " destroyed" << endl;
}

void Mage::castSpell() const {
    cout << "[CAST] " << name << " casts a spell using " << mana << " mana" << endl;
}
int Mage::getMana() const {
    return mana;
}