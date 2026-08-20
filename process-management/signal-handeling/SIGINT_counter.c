#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig)
{
   static int n;
   n++;
   printf("signal received : %d\n",n);
   if(n==5)
   {
    printf("exiting...\n");
     exit(0);
   }
}
int main()
{
    signal(SIGINT,handler);

    while(1)
    {
    printf("program running ......\n");
    sleep(1);
    }
    return 0;
}