#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig)
{
    int i = 1;
    while (i <= 5)
    {
        printf("counter : %d\n", i);
        sleep(1);
        i++;
    }
    printf("counter ended\n");
}
int main()
{
    printf("program started\n");
    signal(SIGUSR1, handler);
    printf("counter started\n");
    raise(SIGUSR1);
    return 0;
}
