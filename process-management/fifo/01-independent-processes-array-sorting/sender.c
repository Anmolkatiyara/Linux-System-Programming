#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
int main()
{   int n;
    printf("enter number of elements\n");
    scanf("%d",&n);
    int arr[n];
    int pipe=mkfifo("fifo",0666);
    if(pipe==-1)
    {
        printf("error in craeting fifo pipe\n");
        return 1;
    }
    printf("enter array elememnts\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int fd=open("fifo",O_WRONLY);
    if(fd==-1)
    {
        printf("errorn in opening fifo pipe\n");
        return 2;
    }
    printf("sending data to receiver end\n");
    int bytes_transferd=write(fd,&n,sizeof(int));
    if(bytes_transferd==-1)
    {
        printf("error in writing array size to the fifo pipe\n");
        return 3;
    }
    int bytes_transferd2=write(fd,arr,sizeof(arr));
    if(bytes_transferd2==-1)
    {
        printf("error in writing array to fifo pipe\n");
        return 4;
    }
     if(close(fd)==-1)
    {
        printf("errorn in closing fifo pipe\n");
        return 5;
    }
         printf("data send successfully\n");
         return 0;
}