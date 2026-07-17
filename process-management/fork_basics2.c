#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int x=2;
    pid_t pid =fork();
     printf("%d\n",2*x);
    pid_t pid2=fork();
   printf("%d\n",2*x);

    return 0;
}