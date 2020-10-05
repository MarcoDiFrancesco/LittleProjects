#include <stdio.h>
#include <unistd.h>

#define READ 0
#define WRITE 1

char *msg = "Content of the pipe";

/*
Named pipe aka fifo
This program makes moves the file descriptor from the input to
a command and the ouput to another commans
*/
int main(int argc, char *argv[]) {
  int fd[2];
  pipe(fd);
  if (fork() > 0) {  // Partent
    close(fd[READ]);
    // Make channel 1 (video output) go to write file descriptor
    dup2(fd[WRITE], 1);
    close(fd[WRITE]);
    execlp(argv[1], argv[1], NULL);
    perror("Error");
  } else {
    close(fd[WRITE]);
    // Channel 0 is for reading
    dup2(fd[READ], 0);
    close(fd[READ]);
    execlp(argv[2], argv[2], NULL);
    perror("Error");
  }
}