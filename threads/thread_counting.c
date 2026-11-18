#include <stdio.h>
#include <pthread.h>

void* counting(void* ptr)
{
    for(int i=1;i<6;i++)
    {
        printf("worker :" "%d\n",i);
    }
    return NULL;
}
int main()
{
    pthread_t tid;
    int ret=pthread_create(&tid,NULL,counting,NULL);
    if(ret!=0)
    {
        printf("error in creating a new thread\n");
        return 1;
    }


     int req2=pthread_join(tid,NULL);
    if(req2!=0)
    {
        printf("error in waiting for worker thread\n");
        return 2;
    }
     
    for(int i=100;i<106;i++)
    {
        printf("parent :" "%d\n",i);

    }

    return 0;
}