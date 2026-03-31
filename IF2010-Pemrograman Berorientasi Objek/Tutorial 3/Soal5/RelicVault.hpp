#pragma once
#include <string>
#include <stack>
#include "VaultException.hpp"
using namespace std;

class RelicVault {
private:
    stack<string> relics;
    int maxCapacity;

public:
    RelicVault(int capacity);

    void push(const string& name);
    string pop();
    string top() const;
    
    int size() const;
    int capacity() const;
    bool empty() const;
};