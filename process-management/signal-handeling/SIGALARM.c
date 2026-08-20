#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig)
{
    printf("times up !!\n");
    exit(0);
}
int main()
{
    signal(SIGALRM,handler);
    alarm(5);
    while(1)
    {
        printf("program is running.....\n");
        sleep(1);
    }
}

