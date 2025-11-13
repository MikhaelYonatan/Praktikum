#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
  while (currentChar == BLANK && currentChar != MARK) {
    ADV();
  }
}

void STARTWORD() {
  START();
  IgnoreBlanks();
  if (currentChar == MARK) {
    EndWord = true;
  }
  else {
    EndWord = false;
    CopyWord();
  }
}

void ADVWORD() {
  IgnoreBlanks();
  if (currentChar == MARK) {
    EndWord = true;
  }
  else {
    CopyWord();
    IgnoreBlanks();
  }
}

void CopyWord() {
  currentWord.Length = 0;
  while (currentChar != BLANK && currentChar != MARK) {
    if (currentWord.Length < NMax) {
      currentWord.TabWord[currentWord.Length] = currentChar;
      currentWord.Length++;
    }
    ADV();
  }
  currentWord.TabWord[currentWord.Length] = '\0';
}