#include <unistd.h>
#include <stdio.h>

int main()
{
	int sec=0;
	alarm(5);
	printf("Loop start \n");
	while(1) {
		sleep(1);
		printf("%d second \n", ++sec);
	}
	printf("Alarm clock \n");
}
