# Sorting of array using two independent processes with the help of fifo named pipe 

## description
this project demonstrate inter-process communication (IPC) between two independent processes using a FIFO (Named pipe)

 this project consists of two seperate programs receiver.c and sender.c.

 ### sender.c
  - takes input array size and array elements from the user .
  - transfers them to receiver.c with the help of FIFO (Named pipe) .

 ### receiver.c
  - reads array size and input elements from fifo named pipe .
  - stores array size into an int variable and array elements into an array.
  - uses quicksort sorting technique and sort all the array elements in ascending order .
  - display the result .

## concepts used
  - `mkfifo()`
  - `read()`
  - `write()`
  - `close()`
  - `open()`
  - `quicksort algorithm`
  - `(IPC) inter process communication`
  - `FIFO (Named pipe)`
  
## time complaxity of quicksort algorithm
 - ### average case `O(nlogn)`
 - ### worst case  `O(n^2)`

## compilation process
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


    


