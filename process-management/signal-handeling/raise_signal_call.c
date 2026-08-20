#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig)
{
    static int i=1;
    printf("SIGUSR received : %d\n",i);
    i++;
  
}
int main()
{
    signal(SIGUSR1,handler);
    printf("counter started\n");
    int i=0;
    while(i<5)
    {
        raise(SIGUSR1);
        sleep(1);
        i++;
    }
    printf("counter ended\n");
    
    return 0;
}
