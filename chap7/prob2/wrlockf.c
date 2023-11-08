#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[])
{
	int fd, id;
	struct student rec;

	if(argc<2) {
		fprintf(stderr, "How to use : %s File\n", argv[0]);
		exit(1);
	}
	if((fd=open(argv[1], O_RDWR))==-1) {
		perror(argv[1]);
		exit(2);
	}

	printf("\nEnter StudentID you want to modify : ");
			while(scanf("%d", &id)==1) {
			lseek(fd, (long) (id-START_ID)*sizeof(rec), SEEK_SET);
			if(lockf(fd, F_LOCK, sizeof(rec))==-1) {
				perror(argv[1]);
				exit(3);
			}
			if((read(fd, &rec, sizeof(rec))>0)&&(rec.id!=0))
				printf("Name:%s\t StuID:%d\t Score:%d\n", rec.name, rec.id, rec.score);
			else printf("No record %d \n", id);

			printf("Enter new score: ");
			scanf("%d", &rec.score);
			lseek(fd, (long) -sizeof(rec), SEEK_CUR);
			write(fd, &rec, sizeof(rec));

			lseek(fd, (long) (id-START_ID)*sizeof(rec), SEEK_SET);
			lockf(fd, F_ULOCK, sizeof(rec));
			printf("\nEnter StudentID you want to modify : ");
			}
			close(fd);
			exit(0);
}
