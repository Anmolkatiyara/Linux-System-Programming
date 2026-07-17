#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    printf("parent process id %d\n",getppid());
    printf("process id %d\n",getpid());

    pid_t pid =fork();
    if(pid==0){
      //child process
      printf("return value %d\n",pid);
      printf("PPID is %d\n",getppid());
      printf("PID is %d\n",getpid());
    }
    else
    {
       // parent process
       wait(NULL);
       printf("return value %d\n",pid);
       printf("PPID is %d\n",getppid());
       printf("PID is %d\n",getpid());
    }
     return 0;
}