#include <stdio.h>
#include <pthread.h>

void *worker(void *ptr)
{
    int x=*(int*)ptr;
    printf("table of %d :\n",x);
    for(int i=1;i<11;i++)
    {
       printf("%d * %d = %d\n",x,i,x*i);
    }
    return NULL;

}

int main()
{
    pthread_t tid1,tid2,tid3;
    int a=5,b=7,c=9;
    int ret1=pthread_create(&tid1,NULL,worker,&a);
    if(ret1!=0)
    {
        printf("error in creatiing a new thread\n");
        return 1;
    }

    int ret2=pthread_create(&tid2,NULL,worker,&b);
    if(ret2!=0)
    {
        printf("error in creatiing a new thread\n");
        return 2;
    }

    int ret3=pthread_create(&tid3,NULL,worker,&c);
    if(ret3!=0)
    {
        printf("error in creatiing a new thread\n");
        return 3;
    }

    int ret4=pthread_join(tid1,NULL);
    if(ret4!=0)
    {
        printf("error in waiting for worker thread\n");
        return 4;
    }

    int ret5=pthread_join(tid2,NULL);
    if(ret5!=0)
    {
        printf("error in waiting for worker thread\n");
        return 5;
    }

    int ret6=pthread_join(tid3,NULL);
    if(ret6!=0)
    {
        printf("error in waiting for worker thread\n");
        return 6;
    }

    return 0;

}