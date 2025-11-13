#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

static FILE* pita;
static int retval;

void START() {
  pita = stdin;
  ADV();
}

void ADV () {
  retval = fscanf(pita, "%c", &currentChar);
  if (currentChar == MARK) {
    EOP = true;
  }
  else {
    EOP = false;
  }
}



