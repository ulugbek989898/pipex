#include <stdio.h>
#include <unistd.h>
# include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>

int	main()
{
	int	fd1 = open("test1", O_RDWR);
	int	fd2 = open("test2", O_RDWR);
	fd1 = dup(fd2);
	write(fd1, "ssdfsdf", 7);
		
}