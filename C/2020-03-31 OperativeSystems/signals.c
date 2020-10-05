#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int counter = 1;

void sighandle_int(int sig) {
  printf("\nSigint %d\n", counter);
  if (counter++ == 3)
    signal(SIGINT, SIG_DFL);
}

/*
From process to process we can use
int kill(pid, int signal);

Or if we want to send to the same program:
like wait 60 seconds before interupting
unsigned int alarm (
  unsigned int seconds
)
*/

int main() {
  signal(SIGINT, sighandle_int);
  while (1) {
    printf(".");
    sleep(1);
    fflush(stdout);  // Force stdout
  }
  return 0;
}