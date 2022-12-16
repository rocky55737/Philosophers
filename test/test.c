#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

int main ()
{
	struct timeval time;
	size_t	s_time;

	gettimeofday(&time, 0);
	s_time = time.tv_sec;
	printf("%lu\n", s_time);
	s_time = time.tv_usec;
	printf("%lu\n", s_time);
	usleep(10);
	gettimeofday(&time, 0);
	s_time = time.tv_sec;
	printf("%lu\n", s_time);
	s_time = time.tv_usec;
	printf("%lu\n", s_time);
}