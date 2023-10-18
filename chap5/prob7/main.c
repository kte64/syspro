#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[])
{
	int fd, id;
	char c;
	struct student rec;
	if(argc<2) {
		fprintf(stderr, "How to use : %s file\n", argv[0]);
		exit(1);
	}
	if((fd=open(argv[1], O_RDWR))==-1) {
		perror(argv[1]);
		exit(2);
	}
	do {
		printf("Enter StuID to be modified: ");
		if(scanf("%d", &id)==1) {
			lseek(fd, (long) (id-START_ID)*sizeof(rec), SEEK_SET);
			if((read(fd, &rec, sizeof(rec))>0)&&(rec.id!=0)) {
				printf("StuID:%8d\t Name:%4s\t Score:%4d\n", rec.id, rec.name, rec.score);
				printf("Enter New Score: ");
				scanf("%d", &rec.score);
				lseek(fd, (long) -sizeof(rec), SEEK_CUR);
				write(fd, &rec, sizeof(rec));
			}
			else printf("Record %d Null\n", id);
		}
		else printf("Insert Error\n");
		printf("Continue?(Y/N)");
		scanf( "%c", &c);
	}
	while(c=='Y');

	close(fd);
	exit(0);
}
