#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
void handler(int sig)
{
    printf("signal received\n");
    printf("exiting child process\n");
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
        signal(SIGUSR1,handler);
        //child process
        while(1)
        {
            printf("child is running ....\n");
            sleep(1);
        }

    }
    else
    {
        //parent process
        sleep(5);
        printf("parent is sending signal to child\n");
        kill(pid,SIGUSR1);
    }
    return 0;

 }
