#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#define HIBYTE(x)   ((unsigned char)(((unsigned short)(x) >> 8) & 0xFF))

int store_number(int *arr) {
  unsigned int read_nbr, idx;

  printf(" Number: ");
  scanf("%u", &read_nbr); 
  printf(" Index: ");
  scanf("%u", &idx); 
  if ( idx == 3 * (idx / 3) || HIBYTE(read_nbr) == 183 )
    return puts("   This index is reserved for wil!");
  arr[idx] = read_nbr;
  return 0;
}

int read_number(const int *arr) {
  int idx;
  printf(" Index: ");
  scanf("%u", &idx);
  printf(" Number at data[%u] is %u\n", idx, arr[idx]);
  return 0;
}

int main(int argc, char **argv, char **envp) {
  int  arr[100];
  int number = 0;
  char v8[20];

  memset(arr, 0, sizeof(arr));
  while (++(*argv))
    memset(*argv, 0, strlen(*argv));
  while (++(*envp))
    memset(*envp, 0, strlen(*envp));
  puts(
    "    store - store a number into the data storage    \n"
    "    read  - read a number from the data storage     \n"
    "    quit  - exit the program                        \n"
    );
  while ( 1 ) {
    printf("Input command: ");
    number = 1;
    fgets(v8, 20, stdin);
    v8[strlen(v8) - 1] = 0;
    if ( !memcmp(v8, "store", 5) ) {
      number = store_number(arr);
      goto LABEL_13;
    }
    if ( !memcmp(v8, "read", 4) ) {
      number = read_number(arr);
      goto LABEL_13;
    }
    if ( !memcmp(v8, "quit", 4) )
      return 0;
    LABEL_13:
    if ( number )
      printf(" Failed to do %s command\n", (const char *)&v8);
    else
      printf(" Completed %s command successfully\n", (const char *)&v8);
    memset(v8, 0, 20);
  }
}