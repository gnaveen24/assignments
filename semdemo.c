#include<stdio.h>
#include<signal.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t software_int;

void handler(int signo)
{
	printf("software interrupt -post to semaphore\n");
	sem_post(&software_int);
}

void* fun1(void *pv)
{
	int i;
	for(i=0;i<5;i++)
	{
		sem_wait(&software_int);
		printf("Received signal %d time\n",i);

	}

	pthread_exit(NULL);
}

void* fun2(void *pv)
{
	printf("Posting semaphore to thread-1 from thread-2\n");
	sem_post(&software_int);
	pthread_exit(NULL);
}

int main()
{
	pthread_t td1,td2;
	printf("Welcome : pid %d ,ppid %d\n",getpid(),getppid());

	signal(SIGINT,handler);
	
	sem_init(&software_int,0,1);

	pthread_create(&td1,NULL,fun1,NULL);
	pthread_create(&td2,NULL,fun2,NULL);

	pthread_join(td1,NULL);
	pthread_join(td2,NULL);

	return 0;
}
