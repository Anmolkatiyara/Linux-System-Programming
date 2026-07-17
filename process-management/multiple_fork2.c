#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
    printf("PPID of program : %d",getppid());
    printf("PID of program %d",getpid());
    pid_t pid=fork();
    printf("hello");
    if(fork()==0)
    {
        printf("hello anmol");
        fork();
        printf("hello mr anmol");
    }

    return 0;
}