#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
int swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    return 0;
}
int partation(int arr[],int st,int end)
{
   int i=st-1;
   int pi=end-1;
   int j=st;
   while(j<end-1)
   {
    if(arr[j]<=arr[pi])
    {
        i++;
        swap(&arr[i], &arr[j]);
    }
    j++;
   }
    i++;
    swap(&arr[i], &arr[pi]);
   return i;
}
void quicksort(int arr[],int st,int end)
{   if(st<end)
    {
    int p=partation(arr,st,end);
    quicksort(arr,st,p);
    quicksort(arr,p+1,end);
    }
    return;
}
int main()
{
    int n;
    int fd=open("fifo",O_RDONLY);
    if(fd==-1)
    {
        printf("error in opening fifo pipe\n");
        return 1;
    }
    int bytes_received=read(fd,&n,sizeof(int));
    if(bytes_received==-1)
    {
        printf("error in reading array size\n");
        return 2;
    }
    int brr[n];
    int bytes_received2=read(fd,brr,sizeof(brr));
    if(bytes_received2==-1)
    {
        printf("error in receiving array\n");
        return 3;
    }
    if(close(fd)==-1)
    {
        printf("error in closing fifo pipe\n");
        return 4;
    }
    printf("received array : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",brr[i]);
    }
        printf("\n");
    quicksort(brr,0,n);
    printf("sorted array : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",brr[i]);
    }
     printf("\n");
    return 0;
}