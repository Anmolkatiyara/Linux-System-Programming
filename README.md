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
├── README.md
└── process-management/
    ├── binary-search-using-fork/
    │   ├── README.md
    │   ├── binary_search_using_fork
    │   └── binary_search_using_fork.c
    ├── fifo/
    │   ├── 01-independent-processes-array-sorting/
    │   │   ├── README.md
    │   │   ├── receiver.c
    │   │   └── sender.c
    │   └── 02-independent-processes-structure-transfer/
    │       ├── README.md
    │       ├── receiver.c
    │       └── sender.c
    ├── fifo_named_pipe
    ├── fifo_named_pipe.c
    ├── fork_basics.c
    ├── fork_basics2.c
    ├── fork_return_value.c
    ├── multiple_fork.c
    ├── multiple_fork2.c
    ├── pipe_basic
    ├── pipe_basics.c
    ├── process_counting.c
    ├── two_way_communication.c
    ├── two_way_communication_using_fifo
    ├── two_way_communication_using_fifo.c
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