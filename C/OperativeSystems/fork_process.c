#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int child() {
  int r = 3;
  printf("I'm the child %d, my father is %d\n", getpid(), getppid());
  return r;
}

int father() {
  int r = 4;  // Return value
  int st;     // Child memory address
  int c;      // Child return code
  printf("I'm the father %d\n", getpid());
  printf("Waiting for child\n");
  c = wait(&st);
  printf("Child pid: %d, child returned: %d\n", c, WEXITSTATUS(st));
  return r;
}

int main() {
  // Create (clone) process
  // Main infos are duplicated
  int f = fork();
  int r;
  // Returns f = 0 to the child
  if (f == -1) {
    printf("Error forking\n");
    r = 1;
  } else if (f == 0) {
    r = child();
  } else {
    r = father(f);
  }
  printf("Return value: %d\n", r);
  return 0;
}
