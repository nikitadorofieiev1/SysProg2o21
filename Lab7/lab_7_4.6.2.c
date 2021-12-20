#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 128

int read_FIFO(int fd, int* result) 
{
	char 	buf[BUF_SIZE];
	size_t  bytes, i;

	if  ((bytes = read(fd, buf, BUF_SIZE - 1)) != 0) {
		buf[bytes] = 0;
		for (i = 0; i < bytes; ++i)
			*result += (int)(buf[i] - '0');
	}

	return bytes;
}

int main() 
{
	int 	sum = 0;
	int	eof1 = 1;
	int	eof2 = 1;
	int	fd1 = open("./in1", O_RDONLY);
	int	fd2 = open("./in2", O_RDONLY);
	
	if (fd1 == -1 || fd2 == -1) {
		fprintf(stderr, "Error opening file\n");
		return 1;
	}

	fd_set 	read_set;
	
	while (eof1 || eof2) {
		FD_ZERO(&read_set);
		FD_SET(fd1, &read_set);
		FD_SET(fd2, &read_set);

		int res = select(fd2 + 1, &read_set, NULL, NULL, NULL);
		if (res) {
			if (FD_ISSET(fd1, &read_set))
				eof1 = read_FIFO(fd1, &sum);
			if (FD_ISSET(fd2, &read_set))
				eof2 = read_FIFO(fd2, &sum);
		} 		
	}
	printf("%d\n", sum);
	close(fd1);
	close(fd2);	
	return 0;
}
