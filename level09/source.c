#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>

int secret_backdoor() {
  char s[128]; // [rsp+0h] [rbp-80h] BYREF

  fgets(s, 128, stdin);
  return system(s);
}

char *set_msg(char* a1) {
  char s[1024]; // [rsp+10h] [rbp-400h] BYREF

  memset(s, 0, sizeof(s));
  puts(">: Msg @Unix-Dude");
  printf(">>: ");
  fgets(s, 1024, stdin);
  return strncpy(a1, s, *(int *)(a1 + 180));
}

int set_username(char* a1) {
  char s[140];

  memset(s, 0, 0x80uLL);
  puts(">: Enter your username");
  printf(">>: ");
  fgets(s, 128, stdin);
  for ( int i = 0; i <= 40 && s[i]; ++i )
    a1[i + 140]= s[i];
  return printf(">: Welcome, %s", a1 + 140);
}

int handle_msg() {
  char v1[140];

  set_username(v1);
  set_msg(v1);
  return puts(">: Msg sent!");
}

int main(int argc, const char **argv, const char **envp) {
  puts(
    "--------------------------------------------\n"
    "|   ~Welcome to l33t-m$n ~    v1337        |\n"
    "--------------------------------------------");
  handle_msg(
    "--------------------------------------------\n"
    "|   ~Welcome to l33t-m$n ~    v1337        |\n"
    "--------------------------------------------",
    argv);
  return 0;
}