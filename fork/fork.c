#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#define KB (1024)
#define MB (1024 * KB)
#define GB (1024 * MB)
int main()
{

	pid_t pid;
	int *mem;
	while (1)
	{
		pid = fork();
		if (pid == 0)
		{
			mem = (int*)malloc(MB);
			memset(mem,1, KB);
		}
	}
	
	return 0;
}
