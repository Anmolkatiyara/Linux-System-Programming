#include <pthread.h>
#include <stdio.h>

void* worker(void *ptr)
{
    printf("hello from warker thread\n");
    return NULL;
}

int main()
{
    pthread_t tid;
    int ret=pthread_create(&tid,NULL,worker,NULL);
    if(ret!=0)
    {
        printf("error in creating a new thread\n");
        return 1;
    }
    
    printf("parent thread is waiting for worker thread \n");

    int ret2=pthread_join(tid,NULL);
    if(ret2!=0)
    {
        printf("error in waiting for worker thread\n");
        return 2;
    }

    printf("hello from parent thread\n");

    return 0;
}

