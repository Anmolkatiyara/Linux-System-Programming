#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
int main()
{
    int pipe=mkfifo("fifo",0666);
    if(pipe==-1)
    {
        printf("error in creating fifo pipe\n");
        return 1;
    }
    struct data
    {
        char name[20];
        int age;
        int id[5];
    }emp1,emp2,emp3;
    printf("enter employee 1 details\n");
     printf("enter employee name : ");
     fgets(emp1.name,sizeof(emp1.name),stdin);
     emp1.name[strcspn(emp1.name,"\n")]='\0';
    printf("\nenter employee age : ");
    scanf("%d",&emp1.age);
    printf("\nenter employee id : ");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&emp1.id[i]);
    }
    getchar();

    printf("enter employee2 details\n");
     printf("enter employee name : ");
    fgets(emp2.name,sizeof(emp2.name),stdin);
     emp2.name[strcspn(emp2.name,"\n")]='\0';
    printf("\nenter employee age : ");
    scanf("%d",&emp2.age);
    printf("\nenter employee id : ");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&emp2.id[i]);
    }
     getchar();

    printf("enter employee3 details\n");
    printf("enter employee name : ");
     fgets(emp3.name,sizeof(emp3.name),stdin);
    emp3.name[strcspn(emp3.name,"\n")]='\0';
    printf("\nenter employee age : ");
    scanf("%d",&emp3.age);
    printf("\nenter employee id : ");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&emp3.id[i]);
    }
     getchar();
    
    int fd=open("fifo",O_WRONLY);
    if(fd==-1)
    {
        printf("error in opening fifo pipe\n");
        return 2;
    }
    int bytes_written=write(fd,&emp1,sizeof(emp1));
    if(bytes_written==-1)
    {
        printf("error in writing to the fifo pipe\n");
        return 3;
    }

     int bytes_written2=write(fd,&emp2,sizeof(emp2));
    if(bytes_written2==-1)
    {
        printf("error in writing to the fifo pipe\n");
        return 3;
    }

     int bytes_written3=write(fd,&emp3,sizeof(emp3));
    if(bytes_written3==-1)
    {
        printf("error in writing to the fifo pipe\n");
        return 3;
    }

    if(close(fd)==-1)
    {
        printf("error in closing fifo pipe\n");
        return 4;
    }
    printf("data transferred successfully");
    return 0;
}