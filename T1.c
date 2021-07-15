#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
	printf("In parent : pid %d ,ppid %d",getpid(),getppid());

	int ret,max =10,status;
	sem_t *ps,*qs;
///....here we are openning to file so address will be same in parent & child
	ps = sem_open("/s1",O_CREAT,0666,1);
	qs = sem_open("/s2",O_CREAT,0666,0);

	ret = fork();

	if(ret == 0)
	{
		printf("Child pid %d,ppid %d",getpid(),getppid());
		sem_wait(ps);
		for(int i =1;i<=max;i++)
		{
			printf("child : %d\n",i);
			sleep(1);
		}
		sem_post(ps);
		sem_post(qs);
		exit(0);
	}
	else
	{
		printf("parent : pid %d ppid %d",getpid(),getppid());
		sem_wait(qs);
		sem_wait(ps);

		for(int i=1;i<=max;i++)
		{
			printf("parent : %d\n",i);
			sleep(1);
		}
		sem_post(ps);

		waitpid(-1,&status,0);

		sem_unlink("s1");
		sem_unlink("s2");

	}
	return 0;
}
