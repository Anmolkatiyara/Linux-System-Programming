#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig)
{   
    sleep(5);
    printf("signal %d received\n",sig);
}
int main()
{
   signal(SIGINT,handler);
   printf("press ctrl+c to send signal\n");
   
   while(1)
   {
    printf("waiting for signal\n");
    sleep(1);
   }
    return 0;

}