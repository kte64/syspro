#include <stdio.h>
#include <unistd.h>

int main()
{
	int pid, gid;
	printf("[Parent] PID=%d GID=%d \n", getpid(), getpgrp());
	pid=fork();
	if(pid==0) {
		printf("Child: PID=%d GID=%d \n", getpid(), getpgrp());
	}
}
