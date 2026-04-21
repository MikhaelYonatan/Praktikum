#include "InternalRecord.hpp"

InternalRecord::InternalRecord(string author, int key)
:BaseRecord(author, key) {};

int InternalRecord::peekSecurity() {
    return calculateClearance() * 2;
}