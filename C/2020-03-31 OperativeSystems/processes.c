#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int pid, ppid, uid;
    pid = getpid();
    ppid = getppid();
    uid = getuid();
    
    printf("process id=%d\n", pid);
    printf("parent id=%d\n", ppid);
    printf("user id=%d\n", uid);
    
    return 0;
}
