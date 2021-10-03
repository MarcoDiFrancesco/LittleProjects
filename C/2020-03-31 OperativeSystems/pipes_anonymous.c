#include <stdio.h>
#include <string.h>

#define READ 0
#define WRITE 1
#define MAXLEN 100

char *msg = "Content of the pipe";

int main() {
  int fd[2], bytesRead;
  char message[MAXLEN];

  // Create anonymous pipe
  pipe(fd);

  if (fork() > 0) {
    close(fd[READ]);
    write(fd[WRITE], msg, strlen(msg) + 1);
    printf("PARENT: Data written\n");
    close(fd[WRITE]);
  } else {
    close(fd[WRITE]);
    bytesRead = read(fd[READ], message, MAXLEN);
    printf("CHILD: Read %d bytes: %s\n", bytesRead, message);
    close(fd[READ]);
  }
  return 0;
}