#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void intHandler(int signo);

int main()
{
	signal(SIGINT, intHandler);
	while(1)
		pause();
	printf("fail \n");
}
void intHandler(int signo)
{
	printf("Interupt signal\n");
	printf("Signal number : %d\n", signo);
	exit(0);
}

