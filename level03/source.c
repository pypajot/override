#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <intring.h>

int decrypt(char a1) {
  char v4[29];

  *(int *)&v4[17] = readgsdword(0x14);
  strcpy(v4, "Q}|u`sfg~sf{}|a3");
  unsigned int v3 = strlen(v4);
  for (unsigned int i = 0; i < v3; ++i )
    v4[i] ^= a1;
  if (!strcmp(v4, "Congratulations!"))
    return system("/bin/sh");
  else
    return puts("\nInvalid Password");
}

int test(int a1, int a2) {
  switch ( a2 - a1 ) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 16:
  case 17:
  case 18:
  case 19:
  case 20:
  case 21:
    return decrypt(a2 - a1);
  default:
    return decrypt(rand());
  }
}

int main(void) {
  int user_input;

  srand(time(NULL));
  puts("***********************************");
  puts("*\t\tlevel03\t\t**");
  puts("***********************************");
  printf("Password:");
  scanf("%d", &user_input);
  test(user_input, 322424845);
  return 0;
}
