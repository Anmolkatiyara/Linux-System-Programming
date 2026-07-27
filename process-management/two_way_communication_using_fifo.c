#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
int main()
{
    int fd1=mkfifo("myfifo1",0666);
    if(fd1==-1)
    {
        printf("error in creating named pipe\n");
        return 1;
    }   
    int fd2=mkfifo("myfifo2",0666);
    if(fd2==-1)
    {
        printf("error in creating named pipe\n");
        return 2;
    }
    pid_t pid=fork();
    if(pid<0)
    {
        printf("error in forking the process\n");
        return 3;
    }
    if(pid ==0)
    {
        //child process
        char arr[100];
        int fd=open("myfifo1",O_RDONLY);
        if(fd==-1)
        {
            printf("error in opening myfifo1\n");
            return 4;
        }
        int bytes_received=read(fd,arr,sizeof(arr));
        if(bytes_received==-1)
        {
            printf("error in reading from myfifo1\n");
            return 5;
        }
         arr[bytes_received]='\0';
        if(close(fd)==-1)
        {
            printf("error in closing myfifo1\n");
            return 6;
        }
        int str_len=strlen(arr);
        int i=0;
        int j=str_len-1;
        while(i<j)
        {
            char temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
        int fd3=open("myfifo2",O_WRONLY);
        if(fd3==-1)
        {
            printf("error in opening myfifo2\n");
            return 7;
        }
        int bytes_transferd=write(fd3,arr,strlen(arr)+1);
        if(bytes_transferd==-1)
        {
            printf("error in writing to myfifo2\n");
            return 8;
        }
        if(close(fd3)==-1)
        {
            printf("error in closing myfifo2\n");
            return 9;
        }
    }
    else
    {
        //parent process
        int n;
        printf("enter size of string :\n");
        scanf("%d",&n);
        char arr[n+1];
        printf("enter string characters\n");
        for(int i=0;i<n;i++)
        {
            scanf(" %c",&arr[i]);
        }
        arr[n]='\0';
        int fd4=open("myfifo1",O_WRONLY);
        if(fd4==-1)
        {
            printf("error in opening myfifo1\n");
            return 10;
        }
        int bytes_written=write(fd4,arr,strlen(arr)+1);
        if(bytes_written==-1)
        {
            printf("error in writing to myfifo1\n");
            return 11;
        }
        if(close(fd4)==-1)
        {
            printf("error in closing myfifo1\n");
            return 12;
        }
        int fd5=open("myfifo2",O_RDONLY);
        if(fd5==-1)
        {
            printf("error in opening myfifo2\n");
            return 13;
        }
        char brr[100];
        int bytes_received=read(fd5,brr,sizeof(brr));
        if(bytes_received==-1)
        {
            printf("error in reading from myfifo2\n");
            return 14;
        }
         brr[bytes_received]='\0';
        if(close(fd5)==-1)
        {
            printf("error in closing myfifo2\n");
            return 15;
        }
        printf("reverse string received from child\n");
       printf("%s",brr);
        wait(NULL);
    }


    return 0;
}