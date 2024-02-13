//
// Created by loumouli on 2/13/24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char input_password[100];
  char password[48];
  char input_user[96];
  int retval = 0;
  FILE *stream = NULL;

  memset(input_user, 0, sizeof(input_user));
  memset(password, 0, 41);
  memset(input_password, 0, sizeof(input_password));
  stream = fopen("/home/users/level03/.pass", "r");
  if (stream == NULL) {
    fwrite("ERROR: failed to open password file\n", 1uLL, 0x24uLL, stderr);
    exit(1);
  }
  retval = fread(password, 1, 41, stream);
  password[strcspn(password, "\n")] = 0;
  if (retval != 41) {
    fwrite("ERROR: failed to read password file\n", 1uLL, 0x24uLL, stderr);
    fwrite("ERROR: failed to read password file\n", 1uLL, 0x24uLL, stderr);
    exit(1);
  }
  fclose(stream);
  puts("===== [ Secure Access System v1.0 ] =====");
  puts("/***************************************\\");
  puts("| You must login to access this system. |");
  puts("\\**************************************/");
  printf("--[ Username: ");
  fgets(input_user, 100, stdin);
  input_user[strcspn(input_user, "\n")] = 0;
  printf("--[ Password: ");
  fgets(input_password, 100, stdin);
  input_password[strcspn(input_password, "\n")] = 0;
  puts("*****************************************");
  if (strncmp(password, input_password, 41))   {
    printf(input_user);
    puts(" does not have access!");
    exit(1);
  }
  printf("Greetings, %s!\n", input_user);
  system("/bin/sh");
  return 0;
}