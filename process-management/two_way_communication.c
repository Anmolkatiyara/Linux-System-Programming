#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int fd1[2];
    if(pipe(fd1)==-1)
    {
        printf("error in creating a pipe\n");
        return 1;
    }
    int fd2[2];
    if(pipe(fd2)==-1)
    {
        printf("error in creating a pipe\n");
        return 2;
    }
    pid_t pid=fork();
    if(pid==-1)
    {
        printf("error in forking the process\n");
        return 3;
    }
    if(pid==0)
    {
        //child process
        int brr[5];
        if(close(fd1[1])==-1)
        {
            printf("error in closing the pipr\n");
            return 6;
        }
        ssize_t bytes_read=read(fd1[0],brr,sizeof(brr));
        if(bytes_read==-1)
        {
            printf("error in reading from pipe\n");
            return 13;
        }
         if(close(fd1[0])==-1)
        {
            printf("error in closing the pipe\n");
            return 4;
        }
        int sum=0;
        for(int i=0;i<5;i++)
        {
            sum+=brr[i];
        }
        if(close(fd2[0])==-1)
        {
            printf("error in closing the pipe\n");
            return 7;
        }
       ssize_t bytes_write= write(fd2[1],&sum,sizeof(sum));
       if(bytes_write==-1)
       {
        printf("error in writing from pipe\n");
        return 14;
       }
        if(close(fd2[1])==-1)
        {
            printf("error in closing the pipe\n");
            return 5;

        }
    }
    else
    {
        //parent process
        int arr[5];
        printf("enter five elements : \n");
        for(int i=0;i<5;i++)
        {
           scanf("%d",&arr[i]);
        }
       if(close(fd1[0])==-1)
        {
            printf("error in closing the pipe\n");
            return 8;
        }
       ssize_t bytes_sent= write(fd1[1],arr,sizeof(arr));
       if(bytes_sent==-1)
       {
        printf("error in writing from pipe\n");
        return 15;
       }
       if(close(fd1[1])==-1)
        {
            printf("error in closing the pipe\n");
            return 9;
        }
        int x;
       if(close(fd2[1])==-1)
        {
             printf("error in closing the pipe\n");
            return 10;
        }
        ssize_t bytes_received=read(fd2[0],&x,sizeof(x));
        if(bytes_received==-1)
        {
            printf("error in reading from pipe\n");
            return 16;
        }
       if(close(fd2[0])==-1)
        {
             printf("error in closing the pipe\n");
            return 11;
        }
        printf("sum of elements received from child process : %d",x);
        if(wait(NULL)==-1)
        {
            printf("error in waiting for child\n");
            return 12;
        }
    }

  
    return 0;
}