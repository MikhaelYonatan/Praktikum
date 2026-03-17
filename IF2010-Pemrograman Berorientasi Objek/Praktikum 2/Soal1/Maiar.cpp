#include "Maiar.hpp"

Maiar::Maiar(const string& name, int hp, int power)
      :Creature(name, hp), power(power) {

}

void Maiar::describe() const {
    cout << "Maiar [" << name << "] | HP: " <<  hp << " | Power: " << power << endl;
}

int Maiar::getPower() {
    return power;
}