#ifndef INTERNAL_RECORD_HPP
#define INTERNAL_RECORD_HPP

#include "BaseRecord.hpp"
#include <iostream>
using namespace std;

class InternalRecord : protected BaseRecord {
public:
    InternalRecord(string author, int key);
    int peekSecurity();
};

#endif
