#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
int main()
{
   pid_t pid =fork();
   if(pid<0)
    return 1;
    else if(pid==0)//child process
   {  
    //sleep(2);
    printf("child process");
    for(int i=5;i<10;i++)
    {
        printf("%d\n",i);
    }
   }
   else{
     printf("parent process");
    for(int i=0;i<5;i++)
    {
        printf("%d\n",i);
    }
   }
    return 0;
}