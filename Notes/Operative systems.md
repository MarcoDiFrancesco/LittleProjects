# Operative systems

## Introduction

[Useful Youtube playlist](https://www.youtube.com/playlist?list=PLEbnTDJUr_IcPtUXFy2b1sGRPsLFMghhS)

## What is an OS

Un sistema operativo è un insieme di programmi che affisce come intermediario tra hardware e uomo. Il SO offre un ambiente per controllare e coordinare l'utilizzo dell'HW da parte di programmi applcativi. Può rendere efficiente l'utilizzo dell'hardware e gestisce i conflitti (e.g. due utenti accedono alla stessa risorsa).
Il SO facilita l'uso della macchina, facendo l'astrazione del codice scritto.
Il SO gesisce le risorse HW come dischi e memoria e SW come file e programmi.
Il sistema operativo si posiziona tra programmi applicativi e hardware.  
The operative system is always on (or at least a part of the kernel), because it needs to have the control over the machine.

![Sistema operativo](https://i.imgur.com/1xaaJlO.png)

Il SO controlla anche l'efficienza dell'astrazione. Se un programma non ha buone performance, non ha molto senso utilizzarlo.

### Generations

**Polling** is used to interact between CPU and I/O using blocking instructions. To override CPU and I/O is necessary to have an asyncronous mechanism. So the CPU stop when I/O finishes the operation, so I/O sends signal to the CPU and CPU stops what it is doing saving the state, makes the operation and start again with what it was doing.

**Direct memory access** uses the principle of polling but sends interrupt signal with a block of informaion.

**Buffering** when CPU and I/O are making the same job.  
**Spooling** when CPU and I/O are making different jobs.

The problem with spooling is that the disks are sequential, so random access disks are introduced.

### Kernel

The kernel can be executed in 3 different ways:

- kernel executed separately
- kernel executed on a user process
- kernel executed as a process

The kernel executed in a **separately enviroment** uses a part of the memoty that is not used by any other process, it is more priviledged than other processes. This was used in momolitic kernel once apon a time.

The kernel executed in **user processes** so each process has the structures to call all functionalities of the kernel (a reference to them). The kernel functionalities are not replicated in each process, they are poining to a process contining all of the functionalities.
This type of kernel is more performant, because when there is a system call, the switch between user mode and kernel mode is faster making a mod switch because we are in the same process, if we would be in two different processes, we would require to make the context switch.

The kernel stack contain all the processes that are running.  
The shared address space is shared across all processes.

Kernel as user process:

![Shared kernel model](https://i.imgur.com/AQ1If7H.png)

## Processes

Program is a **static** instance.  
Process is a **dynamic** instance.  

The image of the memory contains:

- instructions (code)
- variables
- stack call and local variables
- dyncamic memory
- attributes (id, state, control)

![Image memory](https://i.imgur.com/lEF9Kh0.png)

### Process states

![Process states](https://i.imgur.com/rJxqp6k.png)

### Dispathcher

Dispatcher is used by CPU to manage processes:

- Context switch
  - operation where the state is saved in the process control block
  - operation where the state is restored from the process control block
- Kernel mode to user mode
- Caricamento nel program counter del prossimo processo

![Process flow](https://i.imgur.com/wD59Jtx.png)

When a process is created it is attached to the father process.  
When a fork is made to create a clild process.
The father process can wait for the child process to finish or can run in asyncronous mode (concurrent).

### Thread

In a process there are multiple threads. A thread is the minimum usage of the CPU and the process is the minimum usage of resources.

A thread is always attached to a process.

The thread has:

- execution state (stopped, running, ...)
- program counter (the following process that needs to be executed)
- registers (of the CPU)
- stack

![Thread](https://i.imgur.com/in1TxZu.png)

The threads have been created because if a process has a thread blocked, can still run in other threads.  
The thread have also the memory shared, so the access in memory is faster.
The context switch is way faster in threads, compared to processes.
For example in Solaris the creation of a process is 30 time slower than the creation of a thread. And the context switch is 5 time slower.
Another vantage is scalabity, a process is not possible to be scaled and with a thread it is.

### Thread statuses

Threads can be:

- ready
- in execution
- waiting

When a process waits it can block the other threads in the process or can make them running, depending on the implementation.

![Kernel](https://i.imgur.com/Z3LFyUE.png)

### Mapping threads user space to kernel space

Threads can be implemented on kernel level or user level.
All OSs(Linux, Unix, Windows) make a combination of the 2, so some threads are mapped one to one from kernel space to user space, some are mapped such as some threads in user space (for example 3) are mapped to some in kernel space (for example 2). This happens because at kernel space the threads are a fixed number, in user space can possibly be infinite.

Advantages of user-level kernel: faster and no context-switch needed, programmers can work with threads.  
A disadvantage is that once a kernel in user mode is locked, the process locks (can be solved by programmers), another one is that kkis not possible to use parallelism.  
Advantages kernel-level thread: if a process blocks it can continue, parallelism is possible.  
Disadvantage kernel-level thread: low efficiency.

### Inter Process Communication (Communication between processes)

Inter process communication is the technique to make 2 processes communicate. This needs to be fast and secure, the information inside a process needs to be protected.  
This can be done in a shared space or can be done by the kernel.  
Memory can be shared between one or more processes.
General purpouse OSs implements both.  

![Inter process communication](https://i.imgur.com/6WXAmyZ.png)

Advantages of kernel mediation are: more secure because kernel checks everything and in the shared space the processes need to remember that they are working with information that is shared.  

Advantages of shared memory: faster because context switch is easier.

### IPC (Inter Process Communication) message passing

Inter Process Communication message passing make the communication between the processes.  
**Symmetric** IPC are done through `send(Process1, message)` and `receive(Process2, message)`.  
**Asymmetric** IPC are done through `send(Process1, message)` and `receive(id, message)`, it's used id because it can receive from more than 2 processes.  
If you want to send to more than one processes a message, it's convenient to use **mailboxes**. So can be used `send(MailboxA, message)` and `receive(MailboxA, message)`.

Send and receiveive can be **blocking**. If a send is blocking the receiver blocks until the message is received. If a receive is blocking the receiver blocks until the message is available.

## Scheduler

The scheduler assigns the processes to the CPU.  
The processes, when they are ready, they go into the queue.  
A process can be waiting for somthing, like waiting for an input or waiting for a device to be plugged in.  
There are multiple queues of processes, for example for each I/O device there is a different queue. The processes in the queue are attached in head each other.

![Processes queue](https://i.imgur.com/njJCIuU.png)

The scheduler manages these processes.

### Short and long therm schedulers

The long therm scheduler select the processes to be put in the queue.  
The short  therm scheduler select the processes to be put in the CPU.  
The short therm scheduler needs to be really fast. Short therm scheduler can be slower.  
A long therm scheduler needs to mix the I/O bound (short CPU bust) and CPU bound (long CPU bust).  
The mid term scheduler uses virtual memory, that moves the processes from the RAM in the ready queue to the memory in order to execute other (more important) processes.

![Mid therm scheduler](https://i.imgur.com/TQ6qhLm.png)

### CPU scheduler (short therm scheduler)

This is how CPU distributes the load:

![CPU scheduler](https://i.imgur.com/z5wJerR.png)

### Preemption

**Preemptive shedulers** can force the CPU to leave the process and put it back to queue.  
**Non-preemptive schedulers** need to wait for the process.

![Preemptive scheduler](https://i.imgur.com/U4G0Lhd.png)

Processes view with swapped processes.

![Processes frow](https://i.imgur.com/d0DhyEi.png)

The schedulers metrics are:

- **use of CPU**, most use of the CPU
- **throughput**: number of processes for time unit
- **waiting time**: time spent in queue for a process
- **turnaround time**: time to execute a process from the moment of submission to the moment of completion
- **response time**: time from the moment a request is submitted to the moment a reponse is received

Maximize:

- use of CPU
- throughput

Minimize:

- waiting time
- turnaround time
- response time

Goes to [Scheduling algorithms](#Scheduling-algorithms)

### Creation of shared memory

When memory is **shared**, a piece of memory is attached to the heap.

![Attach](https://i.imgur.com/jc2ZxTn.png)

This is an example:

``` C
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

``` C
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

``` C
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

## Scheduling algorithms

### First-Come First-Served algorithm

This is a FIFO algorithm.  
It's really easy to implement.

This is an algorithm without [preemption](#preemption), this mean writing-time(Tw) and response-time (Tr) are always 0.

The problem with this algorithm is that if a process with a large burst is exectured, the writing-time (when all the process started, but still are not done) will be long.

![FCFS algorithm](https://i.imgur.com/kYWkGj7.png)

### Shortest-Job-First

The SJF gives priority to the processes with shortest burst.  
Of this schema there are two versions: preemptive and not preemtive.  
The non-preemptive version makes no more than what desctibed above.  
The preemptive version interrupt the running process if a process with a shorter burst comes, so if a process with remaning burst=8 and a process comes to the queue with a burst=6 the switch is made.

The preemptive version has the **best waiting-time**.  

Non-preemptive example:

![Non-preemptive example](https://i.imgur.com/vkBv98E.png)

Preemptive example, aka **Shortest Remaining Time First** (in this example the switch time is not counted):

![Preemptive example](https://i.imgur.com/MlL0Cao.png)

### Time approximation

The problem with the algorithms above is that the CPU burst time is not known, to solve this, an estimation needs to be made with the time burst of the past.

![Time estimation](https://i.imgur.com/w33odLr.png)

### Priority of processes

![Priority](https://i.imgur.com/VPGxDcQ.png)

Priority example:

![Priority example](https://i.imgur.com/o4RXGV1.png)

### Starvation

With the priority comes the problem of **starvation**. This means that if a process has a low priority, the process could never be executed if there is always a process with a higher priority.

A solution to this could be **aging**, this means if I've been waiting for too long I get a higher priority.

### Higher Response Ratio Next

The HRRN is **non-preemptive algorithm** and it uses the aging method.

Is calculated as: `(t_waiting + t_burst)/t_burst` = `1 + (t_waiting/t_burst)`.

The priority could be calculated:

- each time a process finishes (more expensive)
- each time a process finishes but only if a new process is added (cheaper)

HRRN example calculating each time the priority:

![HRRN example](https://i.imgur.com/vnkQwMt.png)

### Round robin

The processes are divided by quants, then the round robin algorithm takes one process and execute it for a quant of time, then [preempted](#preemption). The queue is **circular**.  
The quant varies **from 10 to 100 millisenconds**.  
If I finish my job (or wait for another process) before the quant finieshes, I leave the CPU before my assigned time terminates. But the next process will have only the usual assigned time, e.g. it takes for me 50ms of burst over 100ms of quant, then the next process won't have 150ms, but just 100.  
This is a good algorithm for time sharing, so for a machine with **shared user** usage because users.  
This algorithm is a FCFS.  
The quant can't be chosen bigger than the burst of all services, because then it would be a FCFS. If it's too small then there will be too many context switches.  
The quant usually is chosen so 80% of the processes execute before the quant expire.  
The quant is **chosen dinamically**, so the OS change it on the fly.

Round robin example with quant = 2:

![Round robin](https://i.imgur.com/OcXzpXz.png)

Processes exercises:

![Exercises processes 1](https://i.imgur.com/zcxTZl1.png)

![Exercises processes 2](https://i.imgur.com/j78ZoNn.png)

### Multilevel queue without feedback

The algorithm seen before are different from what's used in real life. In real life, different queues are used for diffrent types of processes. For example an algotitm for foreground processes could be round robin and one for background processes could be FCFS.

To manage the various queue there is the sheduling based on time slice. This means for example:

- 80% of time for foreground with RR
- 20% of time for background with FCFS

and when the CPU finishes the 20% of time (for example 100ms) then it's forced to switch to background processes.

Example priority of queue:

![Example queue](https://i.imgur.com/lNLmeRn.png)

In the static queues the processes are evaluated only the first time I see that process, there it remains until it ends. Here there is the problem that the processes are not evaluated watching the code, if I miss the category, I could have a less performant execution.  

### Multilevel queue with feedback

In real systems there are the **multilevel queue with feedback**, so the process can move between queues depending on characteristics.

![Multilevel queue with feedback example](https://i.imgur.com/VruCjGg.png)

This is the order:

![Multilevel queue with feedback example 2](https://i.imgur.com/1jml5gT.png)

### Fair share

Fair share divides the CPU in more slices and here the processes are ran by app. So if an app have 2 processes and an app have 10, this avoids that the process with the most processes to have priority.

![Fair share example](https://i.imgur.com/VP81fwI.png)

### Models to evalutate an algorithm

**Deterministic algorithm** is the model we made in the previous exercises. So if we know the processes that go into it, we can predict the output. The problem is that if we change processes the output changes.

**Model with network of queues** we can make predictions with distribution of CPU burst and IO burst with the likelyhood that they happen, and we can show in a graph for example the distribution of the processes.

**Model with simulation** uses real patterns (historic data) or the statistic data used before.

**Implementation** tries in real life.

## Sync between processes

Because there are shared resources an algorithm that manages the order of the execution of the processes needs to think also to syncronization of the processes.

Problem of producer and consumer:

- profucer: make the message
- consumer: uses the message

The execution of these read and write needs to be synced and the buffer used is limited in size.

Buffer used by the processes **is circular**:

- **in** has the first free position
- **out** has the first busy position

![Buffer](https://i.imgur.com/bbcguZZ.png)

Code:

![Buffer code](https://i.imgur.com/25tnV1a.png)

The problem with this script is that the CPU can stop the process in any time, so for example in the consumer script it could stop the execution before the line `counter++` and this would mean not updating the counter. And this is an example that could happen (counter is shared between processes):

![Buffer code](https://i.imgur.com/Wgepsvb.png)

And this would resolve in inconsistency.

The soulution to this is **critical section**.

### Critical section

Critical section is a piece of code in which we acess a shared resource.

The criteria that critical section needs to respect are:

- **mutex** (mutua esclusione): one process at a time can access resources
- **progress**: only processes that are entring can decide how enters
- **bounded waiting**: there must be a max number of times on which the process will wait, so the wait is not infinite

These 3 criateria can be associates with the bathroom:

- only one person can enter
- only people that are outside the bathroom decide who enters (the person that was inside the bathroom doesn't decide)
- the people that wait outside have a limited time to wait

Critical section of a program is written by the programmer, the programmer must write only it's critical section, not the one of other programs.

Algorithm 1, **wrong** algorithm:

![Algorithm 1](https://i.imgur.com/CuC4C8N.png)

The problem with this algorithm is that if a process exits, then the other one wait for him and never enters. For example j terminate, then i wait for ever there. So **progress** is not respected.

Algorithm 2, **wrong** algorithm:

![Algorithm 2](https://i.imgur.com/atbpwPr.png)

The problem of the process waiting forever is solved, because in case one goes away it will have the flag set to false. So process is now respected.
The problem is that the flag could be set to true before the while is entered (critical section) so there will be a deadlock situation:

![Deadlock](https://i.imgur.com/z27D6m4.png)

Algorithm 3:

![Algorithm 3](https://i.imgur.com/EICjmVo.png)

This algorithm checks both if it's the correct turn and if the process has the key. Now we need to solve the problem for more than one processes.

### Lamport's bakery algorithm

Here we solve the problem of having more than 2 processes.

Algorithm 1, **wrong**:

![Lamport's bakery algorithm 1](https://i.imgur.com/TglFJ93.png)

The problem with this soulution is that the `max(number[0], ... , number[N-1])` is atomic, so it could be calculated and the the context switch made without the `number[i]`.

Algorithm 2, **wrong**:

![Lamport's bakery algorithm 2](https://i.imgur.com/4HqbWCw.png)

What is changing here is that if a process did not finish to choose the number in which it will enter the queue, the processes will not be executed because they wait for everyone to choose it's number.

Algorithm 3, **right**:

![Lamport's bakery algorithm 3](https://i.imgur.com/jzpQAhK.png)

There were the software solution, the problem is that it's really a complex solution and there is a lot of time wasting checking in the while.

### Hardware solutions

A solution is to diable interupt while a shared variable is being accessed, the problem is that then a process can take how much time it wants and possibly blocking the acess to other processes.

One solution is **test and set**:

![Test and set 1](https://i.imgur.com/hAAv0u1.png)

![Test and set 2](https://i.imgur.com/FueM0xu.png)

This test is always atomic. This function allows to set the lock to the processes that are called are return the previous state of them, if it was set to FALSE, so the lock was open then it would enter the critical section.

Onther solution is **swap**:

![Swap 1](https://i.imgur.com/EHKHvYg.png)

![Swap 2](https://i.imgur.com/lNDZ8Lx.png)

The problem with swap and test and set is that a process could always be executed, terminate and come back in the critical section continuously, never leaving time for the other processes to enter.  

Here is the solution to this problem:

![Test and set sol 2](https://i.imgur.com/6tu26mY.png)

This solution allows to set FALSE to the lock only in the case there are no other processes that are waiting to go in the critic section.
