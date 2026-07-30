#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
int main()
{
    struct record{
        char name[20];
        int age;
        int id[5];
    }a,b,c;
    int fd=open("fifo",O_RDONLY);
    if(fd==-1)
    {
        printf("error in opening fifo pipe\n");
        return 1;
    }
     int bytes_received=read(fd,&a,sizeof(a));
     if(bytes_received==-1)
     {
        printf("error in reading employee 1 record from fifo pipe\n");
        return 2;
     }
     int bytes_received2=read(fd,&b,sizeof(b));
      if(bytes_received2==-1)
     {
        printf("error in reading employee 2 record from fifo pipe\n");
        return 3;
     }
     int bytes_received3=read(fd,&c,sizeof(c));
      if(bytes_received3==-1)
     {
        printf("error in reading employee 3 record from fifo pipe\n");
        return 4;
     }
     if(close(fd)==-1)
     {
        printf("error in closing fifo pipe\n");
        return 5;
     }
        printf("employee 1 details\n");
        printf("employrr name : %s ",a.name);
        printf("\nemployee age : %d ",a.age);
        printf("\nemployee id : ");
        for(int i=0;i<5;i++)
        {
            printf("%d",a.id[i]);
        }

         printf("\nemployee 2 details\n");
        printf("employrr name : %s ",b.name);
        printf("\nemployee age : %d ",b.age);
        printf("\nemployee id : ");
        for(int i=0;i<5;i++)
        {
            printf("%d",b.id[i]);
        }

         printf("\nemployee 3 details\n");
        printf("employrr name : %s ",c.name);
        printf("\nemployee age : %d ",c.age);
        printf("\nemployee id : ");
        for(int i=0;i<5;i++)
        {
            printf("%d",c.id[i]);
        }
    return 0;
}