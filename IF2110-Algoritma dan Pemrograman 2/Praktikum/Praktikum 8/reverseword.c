#include <stdio.h>
#include <string.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

// int main () {
//   STARTWORD();
//   while (!EndWord) {
//     for (int i = 0 ; i < currentWord.Length ; i++) {
//       printf("%c", currentWord.TabWord[i]);
//       if (i == currentWord.Length-1) {
//         printf("\n");
//       }
//     }
//     ADVWORD();
//   } 
//   return 0;
// }

void reverse(Word base, char* res) {
  for (int i = 0 ; i < base.Length ; i++) {
    res[i] = base.TabWord[base.Length - 1 - i];
  }
  res[base.Length] = '\0';
}

int main () {
  STARTWORD();
  while (!EndWord) {
    char res[currentWord.Length + 1];
    reverse(currentWord, res);
    printf("%s\n", res);
    ADVWORD();
  }
}