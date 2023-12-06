#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int pid;
void alarmHandler();
int main(int argc, char *argv[])
{
	int child, status, limit;
	signal(SIGALRM, alarmHandler);
	sscanf(argv[1], "%d", &limit);
	alarm(limit);

	pid=fork();
	if(pid==0) {
		execvp(argv[2], &argv[2]);
		fprintf(stderr, "%s:fail\n", argv[1]);
	} else {
		child=wait(&status);
		printf("[%d] child process %d exit \n", getpid(), child);
	}
}
void alarmHandler()
{
	printf("[notice] child process %d time over\n", pid);
	kill(pid, SIGINT);
}
