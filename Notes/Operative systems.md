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

The kernel executed in a **separately enviroment** uses a part of the memory that is not used by any other process, it is more priviledged than other processes. This was used in momolitic kernel once apon a time.

The kernel executed in **user processes** so each process has the structures to call all functionalities of the kernel (a reference to them). The kernel functionalities are not replicated in each process, they are poining to a process contining all of the functionalities.
This type of kernel is more performant, because when there is a system call, the switch between user mode and kernel mode is faster than making a mod switch because we are in the same process, if we would be in two different processes, we would require to make the context switch.

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
The short therm scheduler select the processes to be put in the CPU.  
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

This solution is not making less complex the system so between hardware and sofware doesn't really metter.  
The solution to this is using semaphores.

### Semaphores

Semaphores are way reasier than the algorithms seen before.  
The semaphores are implemented in newer opeative systems.  
Semaphores reduces complexity, and the busy waiting situation.

Semaphores actions are:

- V that increments S of 1
- P waits
  - if S > 0, decrement S of 1
  - else, needs to wait

Semaphores can be either binary (0 or 1, sometimes True and False) or generic (value int > 0).

Conceptual execution of **binary** semaphores:

![Semaphores](https://i.imgur.com/dcssv4G.png)

Conceptual execution of **generic** semaphores:

![Semaphores](https://i.imgur.com/gEuzSsU.png)

These 2 piece of code are evaluated in one time, so in a atomic trasnsaction.

There are two implementation:

- **with busy waiting**: the process wastes memrory waiting for itself to end
- **without busy waiting**: the process ends immedialy and switches to the next process immedialy

Busy waiting is also called **spin lock**, spin because of the while (watch next pic), lock because it locks the process.

Implemenation with busy waiting:

![semaphore implementation with busy waiting](https://i.imgur.com/syuoNlm.png)

In this implementation the Swap is a atomic transaction, so it is ensured by the hardware that this transaction cannot be stopped in the middle.

For the implementation with non binary semaphores **with busy waiting**:

![implementation with non binary semaphores](https://i.imgur.com/XWokXUH.png)

Implementation on V **without busy waiting**:

![implementation V no busy waiting](https://i.imgur.com/C8zXRJm.png)

In this implementation there is a list of all the processes (PCB or process control block).  
In this case the process is appended to the list and it's put into sleep, so it leaves the CPU making other process run. So P(delay) is not run, saving computing time.

Implementation on P **without busy waiting**:

![implementation P no busy waiting](https://i.imgur.com/DqBQM8K.png)

This wakes up the processes in case there are processes that are waiting.  
The problem with this implemenation is the starvation that could occure if we have a list with priorities, if we have FCFS this doesn't happen.

Usually in the OS the **busy waiting is accepted** and implemented instead of the list of processes.

The execution is normally:

![execution of semaphores](https://i.imgur.com/xwHdt26.png)

Here s could be called in other ways, the important thing is that P and V are called with their names.

### Semaphores exercises

I want to execute before A, then B:

![exerxise 1 semaphores](https://i.imgur.com/ACBNqtS.png)

Processes that wait each other:

![exerise 2 semaphores](https://i.imgur.com/OwS7Wmi.png)

A limitation of the semaphores is the **deadlock**.

![deadlock example](https://i.imgur.com/ztiS9RS.png)

Another problem is **starvation**, for example if I forget a V, then a process is never run.

### Producer and consumer problem

The **problem of the producer and consumer** has the buffer of N elements that need to be checked (if there is space to produce or consume) before entering the produce or consume section.  
We need to introduce **full** and **empty** semaphores.

![producer and consumer problem](https://i.imgur.com/7eCx9yV.png)

### Dinning philosophers problem

![problem](https://i.imgur.com/ZpoKAJv.png)

We can solve this problem trying to take the right and left sticks, then eating.

![sol 1](https://i.imgur.com/rtNDJw1.png)

Here we have the deadlock situation, because if everyone takes the right strick, then no one eats.

Wrong solutions:

![wrong soulutions](https://i.imgur.com/VqUaicU.png)

All of these change what the problem asked, so they are wrong.  
For example the first one remove one filosopher, but the problem asked for all of them at the same time.  
Or the third one adds a token, not allowed.  

Soultion:

![solution part1](https://i.imgur.com/IJer85Y.png)

Is this solution is really important to avoid describing the Think() and Eat() because these two do not have problems of concurrecy.

The solution is in testing if the two pilosophers close to me are hungry on not. If they are, I don't take sticks.  

![solution part2](https://i.imgur.com/ZTwQPQT.png)

![solution part3](https://i.imgur.com/eOSecjT.png)

In this part I don't only putj the fork back to available, I also put the philosophers close to me in eating state, in the case they were hungry.  
This last step **avoid deadlock** but **not starvation** (only in the case of spare number of philosophers).  
The starvation problem is solved by adding some sort of priority to the solution.

### Sleepy barber problem

Problem:

![problem](https://i.imgur.com/qWaKOiY.png)

Solution:

![solution](https://i.imgur.com/XTFQnlk.png)

### Limitation of the semaphores

The main problem with semaphores is the raising complexity going up with the complexity of the problem.

There are alternatives to this that are: monitor and java syncronized casses in Java.

## Monitor

The monitor is used as a subsititute to the semaphores. The main difference is that the semaphores are implemented directly by the programmer, and the monitors are implemented through high level programming languages like Java.

The monitors garants mutex, so **only one** shared variable at a time will be accessed, so mutex are not needed.

In monitors there are condition variables, these are used to sync monitors. These conditions can receive `wait()` and `signal()`, that are not the same as P and V of the semaphores. Example: `x.wait()`.

The `wait()` stops the process anyway, in the semaphores the P checks if value is 1 or 0 to stop or not.  
The `signal()` wakes up a process, also this is different from V because in the semaphores if 2 V consecutive are called, then 2 processes are called, with signal only the first one is, so the second one does not do anything.

Monitor producer and consumer:

![Monitor producer and consumer](https://i.imgur.com/18U8M4m.png)

### Writes and readers problem

Rules:

- readers can only read
- writers can only write
- more than one readers can read the same file
- only one writer can write in a file
- if a writer is writing, a reader can't read it

Writers solution:

![writers](https://i.imgur.com/FLERJ9u.png)

Readers solution:

![readers](https://i.imgur.com/pqiCrsq.png)

The problem with this solution is **starvation**.

## Deadlock

The deadlock happens when processes are waiting for resources to be freed, and these resources are occupied by resources that are waiting for other locked resources.

![deadlock example](https://i.imgur.com/V1S7GjY.png)

The problem above can be solved with preemption of rollback. With preemption we don't allow more than one car at a time in the bridge, with rollback, we make a car go back to it's track, the problem with this is that if there are more than one car to rollback, then there rollback is not light in performances.

Ececution of 2 processes:

![Ececution of 2 processes](https://i.imgur.com/2PqjCEF.png)

Deadlock possibilities:

![Deadlock possibilities](https://i.imgur.com/8PXEu3g.png)

In the execution above, in the 6 possibilities, 2 of them go into a deadlock situation.

The conditions to have a deadlock are:

![conditions to have a deadlock](https://i.imgur.com/UXhzZYi.png)

A model to understand if there are deadlock is RAG.

### RAG - Resouce Allocation Graph

The RAG is:

![rag](https://i.imgur.com/ABF8wFh.png)

Rag example:

![rag example](https://i.imgur.com/IibLWFY.png)

Here we need to check if we have cycles inside:

![cycles check](https://i.imgur.com/wF5BnVx.png)

In this example we have a cycle between P1 and P3.  
We also have a cycle inside the second exaple, but in the case R1 is locked by P2, when P2 frees up, then P3 is able to run, the same thing with P4. In the first case it isn't the same thing, because both R1 and R2 are waiting for P2, in the case it is blocked, then R2 and R3 are blocked, whitch create a deadlock.

What to do when something like this happens? Static prevention; dynamic prevention; detenction and recovery; not doing anything.

### Static prevention

With hold and wait the process allocate all the resources that it needs to use, then if a context switch comes and another process is waiting for that resource, it won't be able to do anything, so there is a waste of memory. Hold and wait can also cause starvation.

Another possibility to solve the deadlock problem is forcing a process to release all it's resources before locking others.  
The problem with this solution is that not all the processes can do thing, take for instance a printer, it can't be stopped after printing 3 pages, do something else and then come back doing what it was doing in the other process.

Static prevention in not used in real world applications because of its cost.

### Dynamic prevention

The dynamic prevention requires to know the used resources by the processes. If it doesn't have this information, it will use the maximum possible resources used, and this could lead into resources waste.

This prevention checks if the system is in a safe state, this means no deadlock. The system is in a safe state if using the resources it's possible to allocate in some order the processes available. If there isn't a safe state, then it's unsafe, so a deadlock could occure.

![example](https://i.imgur.com/DNYTO1W.png)

In this example the state is safe in the orfer P1 P0 P2.

The dynamic prevention requires every process that is accessed to be in a safe state.

There are 2 Dynamic prevention algorithms:

- RAG slightly modified
- Banker's algorithm

RAG example:

![rag example](https://i.imgur.com/yaJ49No.png)

### Banker's algorithm

the idea of this algorighm is that the bank that have 1000 bank accounts with in total 1.000.000 euros, the money that it needs to have available to give back to the users is way lower than the amount of money that the user really have, because cases like all the users come in the same day and closes all the accounts is almost impossible. If a user ask for a small amount of money, the bank gives it immedialy, if requires a big amount, the bank ask him to come back in some days.

The algorithm requires that the processes to know the used resources. If a process ask resources, if the state is still in a safe state without that resources, then the resources are allocated, if not the resources are not allocated.

The banker algorithm is divided in 2 algorithms:

Allocation algorithm:

![allocation algorithm](https://i.imgur.com/LYQ6Erc.png)

Verification algorithm:

![verification algorithm](https://i.imgur.com/u2zB6ty.png)

Banker's algorithm exercise:

![Banker's algorithm exercise pt1](https://i.imgur.com/7KZPYeB.png)

![Banker's algorithm exercise pt2](https://i.imgur.com/4Rto8bn.png)

### Deadlock & restore

This solution is taken if a process goes in deadlock, and we need to restore from it.

The main **advantage** of this tecnique is that it's not necessary to know before the amount of resources required.

The main **disadvantage** is that there is an high cost to recover.

There are 2 solutions to this:

- Using RAG (sesource allocation graph)
- Rilevamento using kind of banker's algorithm

Restoring **using RAG**:

![restoring using graph](https://i.imgur.com/h8paGix.png)

The RAG is used removing the resources, and watching the processes.  
In this case there is a dealock situation because there is a cycle in P2, P3, P4, P1.

Rilevamento **using kind of banker's agorithm**:

It checks only for the safe state, not a possible allocation (like in the banker's algorithm), it is also not called every time a new process is added, it will be called every n processes executed.

The main difference with the banker's algorithm is that there is no computation of the order that the processes need to be executed not to have deadlock, we just know that there is one that works.

Code:

![Deadlock & restore](https://i.imgur.com/HUev0B7.png)

**Rilevamento exercise** part 1 and 2:

![Rilevamento exercise pt1](https://i.imgur.com/0WXL7MF.png)

![Rilevamento exercise pt2](https://i.imgur.com/JzEiTaq.png)

### Restore

To restore from a deadlock the possibilities are 2:

- kill the processes in deadlock
- preemption of the resources of the locked processes

The soution with **killing the processes** are 2:

- killing all in one
- killing one by one, the problem that comes is, in what order we do it?

A solution to this can be [aging](#Starvation).

### Conclusion

A good solution for deadlock is a combination of the soulutions OR using the **ostrich** (struzzo) solution, so don't handle the deadlocks.
