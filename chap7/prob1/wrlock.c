#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[])
{
	int fd, id;
	struct student rec;
	struct flock lock;

	if(argc<2) {
		fprintf(stderr, "How to use : %s File \n", argv[0]);
		exit(1);
	}

	if((fd=open(argv[1], O_RDWR))==-1) {
		perror(argv[1]);
		exit(2);
	}

	printf("\nEnter StudentID you want to modify : ");
	while(scanf("%d:", &id)==1) {
		lock.l_type=F_WRLCK;
		lock.l_whence=SEEK_SET;
		lock.l_start=(id-START_ID)*sizeof(rec);
		lock.l_len=sizeof(rec);
		if(fcntl(fd,F_SETLKW, &lock)==-1) {
			perror(argv[1]);
			exit(3);
		}

		lseek(fd, (long) (id-START_ID)*sizeof(rec), SEEK_SET);
		if((read(fd, &rec, sizeof(rec))>0)&&(rec.id!=0)) {
			printf("Name:%s\t StuID:%d\t Score:%d\n", rec.name, rec.id, rec.score);
			printf("Enter new score: ");
			scanf("%d", &rec.score);
			lseek(fd, (long) -sizeof(rec), SEEK_CUR);
			write(fd, &rec, sizeof(rec));
			lock.l_type=F_UNLCK;
			fcntl(fd, F_SETLK, &lock);
		}
	else printf("No ecord %d\n", id);
	printf("\nEnter StudentID you want to modify : ");
	}
	close(fd);
	exit(0);
}
