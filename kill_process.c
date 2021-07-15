#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
void main()
{
	int fd,size;

	char buf[100];
	
//	fd = open("text.c",O_CREAT|O_WRONLY,0666);

//	if(fd<0)
//		perror("open");

	pgreg -u  >a.out>test.txt;

//	write(fd,stdout,10);


	fd = open("text.c",O_RDONLY);
	if(fd<0)
		perror("open");
	size = read(fd,buf,101);

	kill(buf,9);
}

