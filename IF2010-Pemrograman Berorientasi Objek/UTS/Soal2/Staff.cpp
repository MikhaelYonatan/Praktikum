#include "Staff.hpp"
#include "Formatter.hpp"

Staff::Staff(string name, int age, string contractEnd, string coachingLicense, string department)
:ClubMember(name, age, contractEnd), coachingLicense(coachingLicense), department(department) {}

double Staff::calculateWage() const {
    return 50000.0;
}

Staff::~Staff() {
    Formatter::log("~Staff", name, "session record freed.");
}