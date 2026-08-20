#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

  void(*old)(int);
void handler(int sig)
{
  printf("signal received\n");
   printf("updating default action\n");
  sleep(2);
  printf("press ctrl+c to exit\n");
  signal(SIGINT,old);
}

int main()
{
      old=signal(SIGINT,handler);

     if(old==SIG_ERR)
    {
        printf("signal error\n");
        return 1;
    }

     printf("press ctrl+c to send the signal\n");
     while(1)
     {
        printf("waiting for the signal.....\n");
        sleep(1);
     }
    return 0;
}