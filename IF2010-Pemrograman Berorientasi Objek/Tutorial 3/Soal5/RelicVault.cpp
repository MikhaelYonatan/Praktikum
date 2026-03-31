#include "RelicVault.hpp"

using namespace std;

RelicVault::RelicVault(int capacity) : maxCapacity(capacity) {}

void RelicVault::push(const string& name) {
    if (name.length() < 3) {
        throw InvalidRelicException("Error: Nama relic tidak valid - nama terlalu pendek", name);
    }
    
    for (char c : name) {
        if (isdigit(c)) {
            throw InvalidRelicException("Error: Nama relic tidak valid - mengandung angka", name);
        }
    }

    if (relics.size() == maxCapacity) {
        throw FullVaultException("Error: Vault sudah penuh", maxCapacity);
    }

    relics.push(name);
}

string RelicVault::pop() {
    if (relics.empty()) {
        throw EmptyVaultException("Error: Vault kosong");
    }
    
    string item = relics.top();
    relics.pop();
    
    return item;
}

string RelicVault::top() const {
    if (relics.empty()) {
        throw EmptyVaultException("Error: Vault kosong");
    }

    return relics.top();
}

int RelicVault::size() const {
    return relics.size();
}

int RelicVault::capacity() const {
    return maxCapacity;
}

bool RelicVault::empty() const {
    return relics.empty(); 
}