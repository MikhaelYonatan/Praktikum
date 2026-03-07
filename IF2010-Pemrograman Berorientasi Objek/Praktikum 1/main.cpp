#include "Paper.hpp"

int main() {
    Paper *a = new Paper('A');
    Paper *b = new Paper('B');
    Paper *c = new Paper('C');
    Paper *cc = new Paper(*c);

    a->fold();
    b->fold();
    c->fold();

    c->glue();

    delete a;
    c->setName('X');

    cc->fold();
    cc->glue();
    delete cc;
    delete c;
    delete b;

    return 0;
}