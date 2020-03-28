#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
int pid_array[900],i;

int allocate_map()
{
int result;
for( i=0;i<900;i++)//allocating data structure 
{
pid_array[i]=0;
}

for( i=0;i<900;i++)//checking if memory is allocated properly or not
{
if(pid_array[i]!=0) result = 0;
else result = 1;
}
return result;
}

int allocate() //manages the pid allocation
{
int p;
for( i=0;i<900;i++)//checking for free pid
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

void *test_thread(void *arg)//function to create threads and test the pid_manager.
{
int *s = (int *)arg;
int process_id;
process_id = allocate();
sleep(*s);//taking input from user and make the program sleep for a while
printf("\tThread with Process ID: %d\n",process_id);
release_pid(process_id);
}

int main()
{
printf("\t\t\t\t\t\t********PROGRAM ID MANAGER********\n");
int inp,lp=1;
printf("\n");
printf("\n");
printf("\n");

printf("\t1.Allocating Memory\n");
int r = allocate_map();
if(r == 1){printf("\tMEMORY ALLOCATED SUCESSFULLY!!\n");}
else printf("\tMEMORY NOT ALLOCATED PROPERLY\n");

printf("\n");
printf("\n");
printf("\t2.Creating Threads  ( Create 100 threads which would print thier respective pid )\n");
printf("!!WAIT TILL ALL THE THREADS PRINT THIER PID AND THEN ENTER 0 to TERMINATE THE PROGRAM!! \n");
int sl;
pthread_t newthread;
printf("\n");
printf("\n");
printf("\t**Enter how much time the thread will sleep:\t");

scanf("%d",&sl);
printf("\n");
for(i=0;i<100;i++) pthread_create(&newthread,NULL,test_thread,&sl);

while(lp)//loop hich would prevent termination of prrogram and wait for user response to terminate the program
{
	int t;
	scanf("%d",&t);
	if(t==0) lp=0;
	 
}

}

