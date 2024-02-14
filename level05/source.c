#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  char s[100];
  fgets(s, 100, stdin);
  //Call toupper on every char of the string
  for (unsigned int i = 0; i < strlen(s); ++i) {
    if (s[i] > 64 && s[i] <= 90)
      s[i] ^= 0x20u;
  }
  printf(s);
  exit(0);
}