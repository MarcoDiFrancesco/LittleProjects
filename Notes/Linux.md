# Linux

## Commands

`env` to get enviroment variables  
`$VAR` and `${VAR}` are the same thing, the second one allows things like `${VAR}m`.  
`${VAR:-PrintThisInCaseIsEmpty}`  
`PATH=$PATH:/home/dir` to concatenate to a string.  
`$1` to `$255`, `$@` returns all, `$?` returns code of the function (0 if well corrected), `$$` returns what is running now, `$!` returns last processes that's running in background.

`export VAR` allows the child processes to use that variable.  
`./script.sh` makes the script run in a children process, `source script.sh` makes it run in the current enviroment, so reading reviroment variables.  
Normally variables inside funtions are exported also outside the function. Local variables can be created using `local VAR`.

`exit` exit the script (like break in C)
`return` exit the function (like return in C)

---

### Shared memory

![Shared memory](https://i.imgur.com/05DtMsL.png)

![Shared memory](https://i.imgur.com/3cjTM58.png)

![Shared memory](https://i.imgur.com/3cjTM58.png)

### System calls

When making a system call, the system can return a code between 1 and 255. If the code is -1, this means that the system call failed. System call fail means that the system wasn't able to execute the call, not that for example the proviledges were not high enough.

**We need to check every time if -1 was returned**.

System call examples:

![System call examples](https://i.imgur.com/7NTlVA8.png)

### Creation of shared memory

When memory is **shared**, a piece of memory is attached to the heap.

![Attach](https://i.imgur.com/jc2ZxTn.png)

This is an example:

```C
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main() {
  key_t key;
  int   i,a;
  int  shm, shm1;
  char *addr, *addr1;
  struct shmid_ds buf;

  key = ftok("pathname", 3);
  printf("key=%d\n",key);

  shm1 = shmget(key, 100, IPC_CREAT+S_IRUSR+S_IWUSR);
  addr1 = shmat (shm1, NULL, 0);

  addr1 = shmat (shm1, NULL, 0);

  printf("P4: identifier of the shared memory shm1= %d\n", shm1);
  printf("P4 read from shared memory %s\n", addr1);
  sprintf(addr1, " P4 wrote on shared memory: bruno crispo");
  printf("%s\n", addr1);

  shmdt(addr1);
  shmctl(shm1,IPC_RMID,0);
 }
```

## Pipe

Pipes make communicate two processes.

### Ordinary pipe

**Ordinary pipe** have a producer and a cosumer.  
The producer writes in the write-end.  
The consumer reads in the read-end.  
Two processes can be both producer and consumer.  
To use pipes two processes need to be father and child.

### Pipe with name

**Pipes with name** don't need to be parent and child and more than one process can communicate through this pipe.

An example of **writer** is:

```C
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
    char * myfifo = "./myfifo";

    /* create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);

    /* write "Hi" to the FIFO */
    fd = open(myfifo, O_WRONLY);
    write(fd, "I am your named pipe", sizeof("I am your named pipe"));
    close(fd);

    /* remove the FIFO */
    unlink(myfifo);

    return 0;
}
```

An example of **reader** is:

```C
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 1024

int main()
{
  int fd;
  char * myfifo = "./myfifo";
  char buf[MAX_BUF];

  /* open, read, and display the message from the FIFO */
  fd = open(myfifo, O_RDONLY);
  read(fd, buf, MAX_BUF);
  printf("Received: %s\n", buf);
  close(fd);

  return 0;
}
```
