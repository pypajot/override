#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, const char **argv, const char **envp)
{
  char input_password[96];
  char buff[48];
  char input_username[96];
  int v9;
  FILE *stream = NULL;

  memset(input_username, 0, sizeof(input_username));
  memset(buff, 0, 41);
  memset(input_password, 0, sizeof(input_password));
  stream = fopen("/home/users/level03/.pass", "r");
  if ( !stream )
  {
    fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
    exit(1);
  }
  v9 = fread(buff, 1, 41, stream);
  buff[strcspn(buff, "\n")] = 0;
  if ( v9 != 41 )
  {
    fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
    fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
    exit(1);
  }
  fclose(stream);
  puts("===== [ Secure Access System v1.0 ] =====");
  puts("/***************************************\\");
  puts("| You must login to access this system. |");
  puts("\\**************************************/");
  printf("--[ Username: ");
  fgets(input_username, 100, stdin);
  input_username[strcspn(input_username, "\n")] = 0;
  printf("--[ Password: ");
  fgets(input_password, 100, stdin);
  input_password[strcspn(input_password, "\n")] = 0;
  puts("*****************************************");
  if (strncmp(buff, input_password, 41))
  {
    printf("%s", input_username);
    puts(" does not have access!");
    exit(1);
  }
  printf("Greetings, %s!\n", input_username);
  system("/bin/sh");
  return 0;
}
