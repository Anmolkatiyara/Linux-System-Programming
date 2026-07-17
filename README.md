# Linux System Programming

This repository contains my C programs created while learning Linux System Programming.

## Topics Covered

### Process Management

- fork()
- Return values of fork()
- getpid()
- getppid()
- wait()
- Multiple fork() examples
- Process counting

## Tools Used

- C Programming
- GCC Compiler
- Ubuntu (WSL)
- Visual Studio Code

## Folder Structure

```
Linux-System-Programming/
│
├── README.md
└── process-management/
    ├── fork_basics.c
    ├── fork_basics2.c
    ├── fork_return_value.c
    ├── multiple_fork.c
    ├── multiple_fork2.c
    ├── process_counting.c
    └── wait_basics.c
```

## How to Compile

```bash
gcc filename.c -o program
```

Example:

```bash
gcc fork_basics.c -o fork_basics
```

## How to Run

```bash
./fork_basics
```

## Future Plans

I will continue updating this repository as I learn:

- Pipes
- FIFO
- dup() and dup2()
- Signals
- Threads (Pthreads)
- Socket Programming
- Shared Memory
- Semaphores
- Message Queues