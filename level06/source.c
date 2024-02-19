#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/ptrace.h>

bool auth(char *s, int a2) {
  int i, v4, v5;

  s[strcspn(s, "\n")] = 0;
  v5 = strnlen(s, 32);
  if ( v5 <= 5 )
    return 1;
  if ( ptrace(PTRACE_TRACEME, 0, 1, 0) == -1 )  {
    puts("\x1B[31m| !! TAMPERING DETECTED !!  |");
    return 1;
  }
  else {
    v4 = (s[3] ^ 0x1337) + 6221293;
    for ( i = 0; i < v5; ++i ) {
      if ( s[i] <= 31 )
        return 1;
      v4 += (v4 ^ (unsigned int)s[i]) % 0x539;
    }
    return a2 != v4;
  }
}

int main(void) {
  int v4;
  char buff[32];

  printf("-> Enter Login: ");
  fgets(buff, 32, stdin);
  printf("-> Enter Serial: ");
  scanf("%d", &v4);
  if ( auth(buff, v4) )
    return 1;
  puts("Authenticated!");
  system("/bin/sh");
  return 0;
}