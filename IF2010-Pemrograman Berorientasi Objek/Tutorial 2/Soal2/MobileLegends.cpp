#include <iostream>
#include "Hero.hpp"
#include "Layla.hpp"
#include "Tigreal.hpp"
using namespace std;

int main() {
    Layla* L1 = new Layla(10, 1000);
    L1->useSkill();
    Layla* L2 = new Layla(*L1); 
    L1->heal(5);
    Layla* L3 = new Layla(50, 200);
    L3->moveTo(15, 30);
    *L3 = *L1; 

    Tigreal* T1 = new Tigreal(200, 10);
    T1->moveTo(5, 15);
    T1->taunt(10);
    Tigreal* T2 = new Tigreal(*T1);
    Tigreal* T3 = new Tigreal(400, 20);
    T3->sacredHammer();
    Tigreal* T4 = new Tigreal(*T3);
    T2->useSkill();
    T3->useSkill();
    Tigreal* T5 = new Tigreal(300, 15);
    T5->moveTo(10, 20);
    Tigreal* T6 = new Tigreal(*T5);
    T5->taunt(5);

    delete T6;
    delete L3;
    delete L2;
    delete L1;
    delete T5;
    delete T4;
    delete T3;
    delete T2;
    delete T1;
}