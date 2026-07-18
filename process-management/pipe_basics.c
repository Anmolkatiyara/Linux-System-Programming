#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd[2];
    pipe(fd);
    pid_t pid=fork();
    if(pid==0)
    {
        //child process
        printf("child reads\n");
        int arr[5];
        close(fd[1]);
        read(fd[0],arr,sizeof(arr));
        close(fd[0]);
        for(int i=0;i<5;i++)
        {
            arr[i]=arr[i]*2;
        }
        for(int i=0;i<5;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    else
    {
        //parent process
        printf("parent writes\n");
        int brr[5]={1,2,3,4,5};
        close(fd[0]);
        write(fd[1],brr,sizeof(brr));
        close(fd[1]);
        wait(NULL);
    }

    return 0;
}