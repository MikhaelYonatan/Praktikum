#include "Club.hpp"
#include "Player.hpp"
#include "Staff.hpp"
#include <iostream>

Club::Club(std::string name)
:clubName(name){}

void Club::addMember(ClubMember* member) {
   roster.push_back(member);
}

void Club::printSquadReport() const {
    std::cout << "\n======================================\n";
    std::cout << "  " << clubName << " - Squad Report\n";
    std::cout << "======================================\n";
    // TODO: panggil getProfile() dari setiap member
    for (int i = 0 ; i < roster.size() ; i++) {
        std::cout << roster[i]->getProfile() << "\n";
    }
}

void Club::runTraining() const {
    std::cout << "\n--- Match Day Actions ---\n";
    // TODO: panggil work() dari setiap member
    for (int i = 0 ; i < roster.size() ; i++) {
        roster[i]->work();
    }
}

Club::~Club() {
    std::cout << "\n--- Releasing Club Roster ---\n";
    // TODO: delete semua ClubMember* di roster
    for (int i = 0 ; i < roster.size() ; i++) {
        delete roster[i];
    }
    roster.clear();
}
