#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int pid_array[900];//min pid =100 and max pid = 1000 datastructure size is 900.

int allocate_map()
{
  int result;//return value
  
  for(int i=0;i<900;i++)//allocating zero to empty sspaces so that it can be used to manage pid's
  {
      pid_array[i]=0;//allocating value zero
  }
  
  for(int i=0;i<900;i++)//checking the allocation
  {
      if(pid_array[i]!=0)result = 0;
      else result = 1;
  }
  return result;
}


int allocate_pid()
{
int p//temporary variable to store free pid;
for(int i=0;i<900;i++)
{
    if(pid_array[i]==0)
      {
        pid_array[i] = 1;//changing the value.
        p = i;//allocating pid to temporary variable
        break;
      }
      return p+100;//adding hundred to satisfy the constraints that pid must lie btw 100 to 1000.
}
}

void realse_pid(int p)
{
int q = p - 100;//to get correct index of the pid
pid_array[q] = 0//changing the value to free state.
}

void *test_threads(void *arg)//method to create threads which would request pid and then release them after a sleep
{
int *s = (int *)arg;
int process_id;
process_id = allocate();
printf("\tThread with Process ID : %d\n",process_id);
sleep(*s);
release_pid(process_id)
}


int main()
{
printf("\t\t\t********PROGRAM ID MANAGER********\n");
int inp,lp=1;
while(lp)
{
printf("\t1.ALLOCATE MEMORY");
printf("\t2.CREATE THREADS");
printf("\t3.!!!EXIT!!!")
printf("\n");
printf("\n");
printf("Enter your choice:\t\n");
scanf("%d",&inp);

switch(inp)
{
case 1:
{
int r = allocate_map();
if(r==1)printf("Memory allocation successfull\n");
else printf("Memory not allocated\n");
break;
}

case 2:
{
int sl,n;
pthread_t newthread;
printf("\tEnter the duration you want the thread to sleep:\t");
scanf("%d",&sl);
printf("\nEnter the no of threads you want to create:\t");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
pthread_create(&newthread,NULL,test_thread,&sl);
}
break;
}

case 3:
{
lp=0;
break;
}

default:
{
printf("Wrong Input enter again#\n");
}

}
}
}
