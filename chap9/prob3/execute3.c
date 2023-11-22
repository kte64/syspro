#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int child, pid, status;
	pid=fork();
	if(pid==0) {
		execvp(argv[1], &argv[1]);
		fprintf(stderr, "%s:fail\n", argv[1]);
	} else {
		child=wait(&status);
		printf("[%d] Child process %d finish \n", getpid(), pid);
		printf("\tfinish code %d \n", status>>9);
	}
}
