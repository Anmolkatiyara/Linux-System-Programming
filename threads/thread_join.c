#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* worker(void* ptr)
{
    int x=*(int *)ptr;
    int *sum=malloc(sizeof(int));
    *sum=0;
    for(int i=x;i<x+10;i++)
    {
        *sum+=i;
    }
    return sum;
}

int main()
{
    int a=1,b=11;
   pthread_t tid1,tid2;
   int ret1=pthread_create(&tid1,NULL,worker,&a);
   if(ret1!=0)
   {
    printf("erroe in creating a new thread\n");
    return 1;
   }

    int ret2=pthread_create(&tid2,NULL,worker,&b);
   if(ret2!=0)
   {
    printf("erroe in creating a new thread\n");
    return 2;
   }
   void *sum1, *sum2;

   int ret3=pthread_join(tid1,&sum1);
   if(ret3!=0)
   {
    printf("error in waiting for worker thread\n");
    return 3;
   }

   int ret4=pthread_join(tid2,&sum2);
   if(ret4!=0)
   {
    printf("error in waiting for worker thread\n");
    return 4;
   }
   printf("result of worker 1 : %d\n",*(int *)sum1);
   printf("result of worker 2 : %d\n",*(int *)sum2);

   printf("final result of both workers : %d\n",*(int *)sum1+*(int *)sum2);

    return 0;
}
