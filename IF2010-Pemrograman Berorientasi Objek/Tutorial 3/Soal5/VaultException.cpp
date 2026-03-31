#include "VaultException.hpp"

VaultException::VaultException(const string& msg) : message(msg) {}

const char* VaultException::what() const noexcept {
    return message.c_str(); 
}

EmptyVaultException::EmptyVaultException(const string& msg) : VaultException(msg) {}

FullVaultException::FullVaultException(const string& msg, int cap) 
    : VaultException(msg), capacity(cap) {}

int FullVaultException::getCapacity() const {
    return capacity;
}

InvalidRelicException::InvalidRelicException(const string& msg, const string& relic) 
    : VaultException(msg), relicName(relic) {}

string InvalidRelicException::getRelicName() const {
    return relicName;
}