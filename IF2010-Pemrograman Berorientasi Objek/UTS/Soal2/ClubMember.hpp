#pragma once
#include <string>
using namespace std;

class ClubMember {
protected:
    string name;
    int age;
    string contractEnd;


public:
   ClubMember(string name, int age, string contractEnd);
   virtual ~ClubMember();
   virtual string getProfile() const = 0;
   virtual double calculateWage() const = 0;
   virtual void work() const = 0;
};
