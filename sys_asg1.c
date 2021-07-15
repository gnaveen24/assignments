#include<unistd.h>

#include<sys/types.h>

#include<fcntl.h>

#include<stdio.h>
int main(int n,char **argv)
{
	int fd,size,fd2;

	char buf[100];

	fd = open(argv[1],O_RDONLY);

	if(fd<0)
		perror("open");

//....Toread file data
	size = read(fd,buf,100);

	printf("The size of file %d\n",size);

//....To write data to anorher file
//
	fd2 = open(argv[2],O_CREAT|O_WRONLY,0666);

	if(fd2<0)
		perror("open");
//...to copy data to file.txt
	
	 write(fd2,buf,size);

	

}

