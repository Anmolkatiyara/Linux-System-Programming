#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
int main()
{
    if(mkfifo("myfifo",0666)==-1)                     //creating named pipe -> "myfifo"
    {
        printf("error in creating named pipe\n");     //0666 -> read and write permission for user group and others.
        return 1;                                 
     }                                              
     pid_t pid=fork();
     if(pid<0)
     {
        printf("error in forking the process\n");
        return 2;
     }
        if(pid==0)
        {
            //child process
            char arr[100];
            int fd=open("myfifo",O_RDONLY);
            if(fd==-1)
            {
                printf("error in opening the named pipe\n");
                return 3;
            }
           int bytes_received= read(fd,arr,sizeof(arr));  //child reads from the pipe
           if(bytes_received==-1)
           {
            printf("error in reading from named pipe\n");
            return 4;
           }
            if(close(fd)==-1)
            {
                printf("error in closing the pipe\n");
                return 5;
            }
            printf("%s\n",arr);
        }
        else
        {
            //parent process
            char brr[100]={"hello from parent process"};
            int fd=open("myfifo",O_WRONLY);
            if(fd==-1)
            {
                printf("error in opening the named pipe\n");
                return 6;
            }
            int bytes_written=write(fd,brr,strlen(brr)+1);      //parent writing to the pipe
            if(bytes_written==-1)
            {
                printf("error in writing to the naemd pipe\n");
                return 7;
            }
            if(close(fd)==-1)
            {
                printf("error in closing the named pipe\n");
                return 8;
            }
            wait(NULL);   //parent waits for child to finish execution
            
        }

    return 0;
}