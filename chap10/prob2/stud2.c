#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	int id;
	char name[20];
	struct student *next;
};

int main()
{
	int count=0, id;
	char name[20];
	struct student *ptr, *head=NULL;

	printf("Enter id and name\n");
	while(scanf("%d %s", &id, name)==2) {
		ptr=(struct student *) malloc(sizeof(struct student));
		if(ptr==NULL) {
			perror("malloc");
			exit(1);
		}
		ptr->id=id;
		strcpy(ptr->name, name);
		ptr->next=head;
		head=ptr;
	}
	printf("\n* student's information(back) *\n");
	ptr=head;
	while(ptr!=NULL) {
		count++;
		printf("id: %d name: %s \n", ptr->id, ptr->name);
		ptr=ptr->next;
	}
	printf("%d students.\n", count);
	exit(0);
}
