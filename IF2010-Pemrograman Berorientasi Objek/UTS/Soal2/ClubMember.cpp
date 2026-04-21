#include "ClubMember.hpp"
#include "Formatter.hpp"
#include <iostream>

ClubMember::ClubMember(string name, int age, string contractEnd)
:name(name), age(age), contractEnd(contractEnd){}

ClubMember::~ClubMember() {
    Formatter::log("~ClubMember", name, "contract record cleared.");
}
