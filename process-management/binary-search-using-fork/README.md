# binary search using fork() and pipe()

## description

 this program demonstrates how to use `fork()` and `pipe()` in linux.
 the child process searches for the first half part of array and sends the result to parent process through an unnamed pipe.
 if child does not find the target than parent searches for remaining half of the array .

## concepts used 

- fork()
- pipe()
- wait()
- read()
- write()
- close()
- binary search

## compilation
 ```bash
 gcc binary_search_using_fork.c -o binary_search_using_fork
 ```
## run
```bash
./binary_search_using_fork
```

## note 
 the classical binary search approach is faster then this approach. main objective to implement this method is to understand the concepts linux system programming concepts not to overcome the classical binary search approach 
