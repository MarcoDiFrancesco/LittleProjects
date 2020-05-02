#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    // Create (clone) process
    // Main infos are duplicated
    int f = fork();
    // Returns f = 0 to the child
    if (f == -1) {
        printf("Error in creating fork\n");
        return 1;
    } else if (f > 0) {
        printf("I'm the father %d, my child is %d\n", getpid(), f);
    } else {
        printf("I'm the child %d, my father is %d\n", getpid(), getppid());
    }
}
