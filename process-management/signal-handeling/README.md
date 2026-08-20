# Signal Handling in Linux

This directory contains my practice programs for learning **signal handling and signal-based process communication in Linux using C**.

The programs are written progressively, starting from basic signal handling and moving toward advanced topics such as signal masks, `sigaction()`, signal synchronization, and real-time signals.

---

## Topics Covered

### 1. Basic Signal Handling

- `signal()`
- Signal handlers
- `SIGINT`
- Signal disposition
- Returning from a signal handler
- Understanding how signals interrupt normal program execution

### 2. Signal Counter

- Maintaining state inside a signal handler
- `static` variables inside signal handlers
- Handling multiple occurrences of a signal

### 3. Alarm Signals

- `SIGALRM`
- `alarm()`
- Using signals as timer notifications

### 4. Signal Return Value

- Return value of `signal()`
- `SIG_ERR`
- Saving the previous signal disposition
- Restoring the previous signal disposition

### 5. Signal Dispositions

- `SIG_DFL` — default signal action
- `SIG_IGN` — ignore a signal
- Custom signal handlers

### 6. User-Defined Signals

- `SIGUSR1`
- `SIGUSR2`
- Using user-defined signals for application-specific events

### 7. Generating Signals

- `raise()`
- Sending a signal to the calling process
- Difference between `raise()` and process-to-process signal delivery

### 8. Parent-Child Signal Communication

- `fork()`
- `kill()`
- `getpid()`
- `getppid()`
- Parent → Child signal communication
- Child → Parent signal communication
- Bidirectional signal communication

---

## Directory Structure

```text
 signal-handling/
 │
 ├── basics_01.c
 ├── signal_return_value.c
 ├── SIGINT_counter.c
 ├── SIGALARM.c
 ├── raise_signal_call.c
 ├── raise_counter_2.c
 ├── signal_from_parent_to_child.c
 ├── bidirectional_signal_transfer.c
 │
 └── README.md
 ```

## Topics Covered

- Basic signal handling using `signal()`
- Signal handlers
- `SIGINT`
- Handling `Ctrl+C`
- Signal counters using `static` variables
- `SIGALRM`
- `alarm()`
- Signal disposition
- `SIG_DFL`
- `SIG_IGN`
- Return value of `signal()`
- `SIG_ERR`
- Saving and restoring previous signal disposition
- `SIGUSR1`
- `SIGUSR2`
- User-defined signals
- `raise()`
- Generating signals from the current process
- `kill()`
- Sending signals between processes
- `fork()` with signal handling
- `getpid()`
- `getppid()`
- Parent → Child signal communication
- Child → Parent signal communication
- Bidirectional signal communication
- Signal handlers returning to normal program execution
- Basic signal-based process control


## How to Compile

```bash
gcc filename.c -o program
```

Example:

```bash
gcc basics_01.c -o basics_01
```

## How to Run

```bash
./basics_01
```

## Future Plans

The following topics will be explored as I continue learning Linux signal handling:

- `pause()` and signal-based waiting
- Signal synchronization between processes
- `sigaction()`
- Signal sets
- Signal masking and blocking
- Pending signals
- `sigsuspend()`
- `SIGCHLD` and child-process management
- Advanced `sigaction()` flags
- `sig_atomic_t`
- Async-signal-safe functions
- `sigqueue()` and sending data with signals
- POSIX real-time signals
- POSIX timers and timer-generated signals
- Signal-based process management projects

The goal is to move from basic signal handling to advanced **POSIX signal mechanisms and practical inter-process communication**.