#include <stdio.h>
#include <unistd.h>
int main()
{
     printf("parent process id %d\n",getppid());
   printf("process id %d\n",getpid());
     pid_t pid=fork();
   if(pid==0)
   {
    //child process
     printf("this is child process\n");
     printf("return value of child process %d\n",pid);
     printf("PPID of child process %d\n",getppid());
     printf("process id of child process %d\n",getpid());
   }
   else
   {
   //parant process
     printf("this is  parent process\n");
     printf("return value of parent process %d\n",pid);
     printf("PPID of parent process %d\n",getppid());
     printf("process id of parent process %d\n",getpid());
   }
   return 0;
}

