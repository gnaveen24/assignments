#include<pthread.h>
#include<stdio.h>
#include<stdint.h>
void* test_body(void *pv)
{
	int i,ps,id =(intptr_t)pv;
	printf("Welcome %d\n",id);
	for(i=1;i<=5;i++)
	{
		printf("%d --%d\n",i,id);
	}
}
int main()
{
	int n=10,k=0,i;

	pthread_t ptarr[n];

	for(i=0;i<n;i++)
	{
		k =100+i;
		pthread_create(&ptarr[i],NULL,test_body,(void *)k);
	}

	for(i=0;i<n;i++)
	{
		pthread_join(ptarr[i],NULL);
	}

	printf("main : Thankyou\n");

	return 0;

}
