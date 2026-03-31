#pragma once
#include <exception>
#include <string>
using namespace std;

class VaultException : public exception {
protected:
    string message;
    
public:
    VaultException(const string& message);
    const char* what() const noexcept override;
};

class EmptyVaultException : public VaultException {
public:
    EmptyVaultException(const string& msg);
};

class FullVaultException : public VaultException {
private:
    int capacity;

public:
    FullVaultException(const string& msg, int cap);
    int getCapacity() const;
};

class InvalidRelicException : public VaultException {
private:
    string relicName;

public:
    InvalidRelicException(const string& msg, const string& relic);
    string getRelicName() const;
};