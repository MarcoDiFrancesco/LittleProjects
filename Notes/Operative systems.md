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
16:40