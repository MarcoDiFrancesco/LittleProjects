# Operative systems

## Introduction

## What is an OS

Un sistema operativo è un insieme di programmi che affisce come intermediario tra hardware e uomo. Il SO offre un ambiente per controllare e coordinare l'utilizzo dell'HW da parte di programmi applcativi. Può rendere efficiente l'utilizzo dell'hardware e gestisce i conflitti (e.g. due utenti accedono alla stessa risorsa).
Il SO facilita l'uso della macchina, facendo l'astrazione del codice scritto.
Il SO gesisce le risorse HW come dischi e memoria e SW come file e programmi.
Il sistema operativo si posiziona tra programmi applicativi e hardware.

![Sistema operativo](https://i.imgur.com/1xaaJlO.png)

Il SO controlla anche l'efficienza dell'astrazione. Se un programma non ha buone performance, non ha molto senso utilizzarlo.

### Generations

**Polling** is used to interact between CPU and I/O using blocking instructions. To override CPU and I/O is necessary to have an asyncronous mechanism. So the CPU stop when I/O finishes the operation, so I/O sends signal to the CPU and CPU stops what it is doing saving the state, makes the operation and start again with what it was doing.

**Direct memory access** uses the principle of polling but sends interrupt signal with a block of informaion.

**Buffering** when CPU and I/O are making the same job.  
**Spooling** when CPU and I/O are making different jobs.

The problem with spooling is that the disks are sequential, so random access disks are introduced.

## Processes

Program is a **static** instance.  
Process is a **dynamic** instance.  

Immagine in memoria:

- instructions (code)
- variables
- stack call and local variables
- dyncamic memory
- attributes (id, state, control)

![Immagine in memoria](https://i.imgur.com/lEF9Kh0.png)

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
