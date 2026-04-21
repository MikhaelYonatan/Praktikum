#pragma once
#include "ClubMember.hpp"
#include <string>

class Player : public virtual ClubMember
{
protected:
    string position;
    int stamina;
    double rating;

public:
   Player(string name, int age, string contractEnd, string position, int stamina, double rating);
   virtual ~Player();
   double calculateWage() const override;
   virtual double calculateRating() const = 0;
};
