#pragma once
#include "Player.hpp"
#include "Staff.hpp"

class PlayerCoach : public Player, public Staff
{
private:
    int yearsAsPlayer;
    bool isCurrentlyPlaying;

public:
    PlayerCoach(string name, int age, string contractEnd, string position, 
    int stamina, double rating, string license, int yearsAsPlayer, bool isCurrentPlaying);
    ~PlayerCoach();

    void work() const override;

    double calculateRating() const override;
    double calculateWage() const override;
    string getSpecialty() const override;
    string getProfile() const override;

};
