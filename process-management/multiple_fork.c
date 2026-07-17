#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid1=fork();
    pid_t pid2=fork();
    if(pid1<0)
    {
      printf("error while forking the process\n");
      return 1;
    }
     if(pid2<0)
    {
        printf("error in forking the process\n");
        return 2;
    }
    if(pid1==0&&pid2>0)//child1
    {
        printf("this is child 1\n");
        printf("%d\n",pid1);
        printf("%d\n",pid2);
    }
    else if(pid2==0&&pid1>0){//parent process
        printf("this is child2\n");
        printf("%d\n",pid1);
        printf("%d\n",pid2);
    }
    else if(pid2==0&&pid1==0)
    {
         printf("this is child3\n");
        printf("%d\n",pid1);
        printf("%d\n",pid2);

    }
    else{
        printf("this is parent process\n");
         printf("%d\n",pid1);
        printf("%d\n",pid2);
    }


    return 0;
}