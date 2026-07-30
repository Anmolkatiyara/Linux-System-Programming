# Sending Structure Between Processes Using Pipe

## Description

This project demonstrates **Inter-Process Communication (IPC)** between two independent processes using a **FIFO (Named Pipe)**.

The project consists of two separate programs:

### sender.c

- Accepts structure data from the user.
- Stores the user input in a structure.
- Transfers the complete structure to `receiver.c` through a FIFO (Named Pipe).

### receiver.c

- Reads the complete structure from the FIFO.
- Stores the received structure in memory.
- Displays all the received structure members.
- Verifies that the structure has been transferred successfully.

## Concepts Covered

- `fork()`
- `pipe()`
- `read()`
- `write()`
- `close()`
- `wait()`
- Structure handling in C
- Inter-Process Communication (IPC)

## Program Flow

1. Parent process creates a pipe.
2. Parent calls `fork()` to create a child process.
3. Parent fills a structure with data.
4. Parent writes the entire structure into the pipe.
5. Child reads the structure from the pipe.
6. Child displays the received data.
7. Parent waits for the child to finish.

## Compilation

```bash
gcc sender.c -o sender
gcc receiver.c -o receiver
```

##  execution

open two terminal

 ### terminal 1

```bash
   ./ sender
```
 ### terminal 2
 ```bash
   ./ receiver
```

## Author

Anmol Katiyara
B.Tech CSE (AI)

Learning Linux System Programming using C.