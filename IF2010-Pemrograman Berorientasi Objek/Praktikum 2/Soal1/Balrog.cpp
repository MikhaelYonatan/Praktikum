#include "Balrog.hpp"

Balrog::Balrog(string name, int hp, int power, string whipName) 
       :Maiar(name, hp, power), whipName(whipName){};

void Balrog::describe() const {
    cout << "Balrog [" << name << "] | HP: " <<  hp << " | Power: " << power << " | Whip: " << whipName << endl;
}

void Balrog::rage() {
    cout << name << " cracks " << whipName << " with " << Maiar::getPower() << " power!\n";
}