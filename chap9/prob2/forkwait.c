#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int pid, child, status;
	printf("[%d] Parent process start \n", getpid());
	pid=fork();
	if(pid==0) {
		printf("[%d] Child process start \n", getpid());
		exit(1);
	}
	child=wait(&status);
	printf("[%d] Child process %d  finish \n", getpid(), child);
	printf("\t final code %d\n", status>>8);
}

