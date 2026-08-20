#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

void handler(int sig)
{
   printf("SIGUSR1 received from child\n");
}

void handler2(int sig)
{
    printf("SIGUSR2 received from parent\n");
    printf("exiting child....\n");
    exit(0);
}
int main()
{
    pid_t pid=fork();
    
    if(pid<0)
    {
        printf("error in forking the process\n");
        return 1;
    }
    if(pid==0)
    {
        //child process
        signal(SIGUSR2,handler2);
        sleep(5);
         kill(getppid(),SIGUSR1);
        int i=0;
        while(i<5)
        {
        printf("child is waiting for signal from parent.....\n");
        sleep(1);
        i++;
        }
    }
    else
    {
        //parent process
        signal(SIGUSR1,handler);
        int i=0;
        while(i<5)
        {
        printf("parent is waiting for signal from child.....\n");
        sleep(1);
        i++;
        }
        sleep(5);
        kill(pid,SIGUSR2);
        wait(NULL);
        
    }
    return 0;
}
