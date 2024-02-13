//
// Created by loumouli on 2/12/24.
//

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av) {
  int buff;

  puts("***********************************");
  puts("* \t     -Level00 -\t\t  *");
  puts("***********************************");
  puts("Password:");
  scanf("%d", &buff);
  if (buff != 0x149c)
    puts("\nInvalid Password!");
  else {
    puts("\nAuthenticated!");
    system("/bin/sh");
  }
  return buff != 0x149c;
}