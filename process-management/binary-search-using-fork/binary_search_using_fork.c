#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    int n;
    printf("enter array length\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements\n");
    //taking user input
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    //initializing target
    int target;
    printf("enter target element\n");
    scanf("%d",&target);
    int p=n/2;
    //initializing pipe
    int fd[2];
    pipe(fd);
    //forking the process
    pid_t pid=fork();
    //checking error
    if(pid<0)
    {
        printf("error while forking the process\n");
        return 1;
    }

    if(pid==0)
    {
        //child process
        int st=0;
        int end=p-1;
        int mid;
        int a=-1;
        close(fd[0]);
        while(st<=end)
        {
            mid=st+(end-st)/2;
            if(arr[mid]==target)
            {
                a=1;
                break;
            }
            else if(arr[mid]>target)
            {
                end=mid-1;
            }
            else
            {
                st=mid+1;
            }
        }
        if(a==1)
        {
            write(fd[1],&mid,sizeof(int));
            close(fd[1]);
        }
        else{
            write(fd[1],&a,sizeof(int));
            close(fd[1]);
        }
        

    }
    else
    {
        //parent process
        int st=p;
        int end=n-1;
        int mid;
        int a=0;
        close(fd[1]);
        int x;
        read(fd[0],&x,sizeof(int));
        close(fd[0]);
        if(x==-1)
        {
          while(st<=end)
          {
            mid=st+(end-st)/2;
            if(arr[mid]==target)
            {
                a=1;
                printf("target found at index : %d\n",mid);
                return 0;
            }
            else if(arr[mid]>target)
            {
                end=mid-1;
            }
            else
            {
                st=mid+1;
            }
          }
           if(a==0)
           printf("target not found\n");
        }
        else{
            printf("target found at inde : %d\n",x);
        }
        wait(NULL);
    }

    return 0;
}
