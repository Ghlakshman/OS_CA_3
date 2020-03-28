#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
int pid_array[900];

int allocate_map()
{
int result;
for(int i=0;i<900;i++)//allocating dat structure
{
pid_array[i]=0;
}

for(int i=0;i<900;i++)//checking if memory is allocated properly or not
{
if(pid_array[i]!=0) result = 0;
else result = 1;
}
return result;
}

int allocate()
{
int p;
for(int i=0;i<900;i++)//checking for free pid
{
if(pid_array[i]==0){pid_array[i]=1;p=i;break;}
}
return p+100;
}

void release_pid(int p)
{
p = p-100;
pid_array[p] = 0;
}

void *test_thread(void *arg)
{
int *s = (int *)arg;
int process_id;
process_id = allocate();
sleep(*s);
printf("\tThread with Process ID: %d\n",process_id);
release_pid(process_id);
}

int main()
{
printf("\t\t\t********PROGRAM ID MANAGER********\n");
int inp,lp=1;

printf("\n");
printf("\n");

printf("\t1.Allocating Memory");
int r = allocate_map();
if(r == 1){printf("\tMEMORY ALLOCATED SUCESSFULLY!!\n");}
else printf("\tMEMORY NOT ALLOCATED PROPERLY\n");
int sl;
  

printf("\t2.Creating Threads which would create 100 threads and request pid to check our pid manager");
pthread_t newthread;
printf("**\nEnter how much time the thread will sleep:\t");
scanf("%d",&sl);
pthread_create(&newthread,NULL,test_thread,&sl);
}


