//
// Created by loumouli on 2/13/24.
//

#include <string.h>
#include <stdio.h>

char a_user_name[100];

int verify_user_name(void) {
  puts("verifying username....\n");
  return memcmp(a_user_name, "dat_wil", 7) != 0;
}

int verify_user_pass(const void *a1) {
  return memcmp(a1, "admin", 5) != 0;
}

int main(void) {
  char s[80];

  memset(s, 0, sizeof(s));
  puts("********* ADMIN LOGIN PROMPT *********");
  printf("Enter Username: ");
  fgets(a_user_name, 256, stdin);
  int v5 = verify_user_name();
  if (v5)
    puts("nope, incorrect username...\n");
  else {
    puts("Enter Password: ");
    fgets(s, 100, stdin);
    v5 = verify_user_pass(s);
    puts("nope, incorrect password...\n");
  }
  return 1;
}