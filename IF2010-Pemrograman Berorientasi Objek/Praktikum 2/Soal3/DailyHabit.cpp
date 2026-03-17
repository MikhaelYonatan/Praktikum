#include "DailyHabit.hpp"
using namespace std;

DailyHabit::DailyHabit(const string& name)
           :Activity(name) {
    streak = 0;
}

int DailyHabit::complete() {
    streak++;
    return 10 * streak;
}

string DailyHabit::getStatus() const {
    string content = "[HABIT] " + name + " - Streak: " + to_string(streak);
    return content;
}

DailyHabit::~DailyHabit() {
    cout << "Menghapus DailyHabit " << name << endl;
}