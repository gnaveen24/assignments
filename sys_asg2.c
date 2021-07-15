#include<unistd.h>

#include<sys/types.h>

#include<fcntl.h>

#include<stdio.h>
int main(int n,char **argv)
{
	int fd,line,size,word;

	char buf[100];

	fd = open(argv[1],O_RDONLY);

	if(fd<0)
		perror("open");

	size = read(fd,buf,100);

	for(int i=0;i<size;i++)
	{
//.......to count no. of lines
		if(buf[i] == '\n')
		{
			line++;
		}
//.......to count words in a file
		else if(buf[i] == ' ')
		{
			word++;
		}
	}

	printf("The no of lines in %d\n",line);

	printf("The no. of words in %d\n",word+line);

	printf("The no. of characters in a file is %d\n",size);
}
