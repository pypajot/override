#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/prctl.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>

void gets(char *);

int main(void) {
  int status_child = 0;
  char buff[156];
  int retval_ptrace = 0;

  pid_t pid = fork();
  memset(buff, 0, sizeof(buff));
  if (pid) {
    do {
      wait(&status_child);
      if (WIFEXITED(status_child) || WIFSIGNALED(status_child)) {
        puts("child is exiting...");
        return 0;
      }
      retval_ptrace = ptrace(PTRACE_PEEKUSER, pid, 44, 0); //check the latest syscall
    }
    while (retval_ptrace != 11); //if the latest syscall is execve
    puts("no exec() for you");
    kill(pid, 9); // We kill the child
  }
  else {
    prctl(1, 1);
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    puts("Give me some shellcode, k");
    gets(buff);
  }
  return 0;
}