#include<pthread.h>
#include<stdio.h>
#include<stdint.h>
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
int k=0,arr[11],val;
void* test_body(void *pv)
{
	pthread_mutex_lock(&m1);

	int i,ps,id =(intptr_t)pv;
	printf("Welcome %d\n",id);
	

	if(id ==0)
	{
		arr[id] =0;
		val =arr[id];
	}
	else
	{
		val =arr[id-1]; 
	}
	for(i=1;i<=100;i++)
	{

		val+=i;
		printf("%d --%d\n",i,val);
	}
	arr[id]=val;
	
	pthread_mutex_unlock(&m1);
}
int main()
{
	long n=10,i,arr[n];

	pthread_t ptarr[n];

	for(i=0;i<n;i++)
	{
	//	k =k+i;
		pthread_create(&ptarr[i],NULL,test_body,(void *)i);
	//	arr[i]=k;
	}

	for(i=0;i<n;i++)
	{
		pthread_join(ptarr[i],NULL);
	}

	printf("main : Thankyou\n");

	for(i=0;i<n;i++)
		printf("final total of arr[%ld] is %ld\n",i,arr[i]);

	return 0;

}
