#pragma once
#include "ClubMember.hpp"
#include <string>

class Staff : public virtual ClubMember
{
protected:
    string coachingLicense;
    string department;

public:
    Staff(string name, int age, string contractEnd, string coachingLicense, string department);
    virtual ~Staff();
    double calculateWage() const override;
    virtual string getSpecialty() const = 0;
};
