#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>

int main()
{
	printf("my realistc user id : %d(%s) \n", getuid(), getpwuid(getuid())->pw_name);
	printf("my valid user id : %d(%s) \n", geteuid(), getpwuid(geteuid())->pw_name);
	printf("my realistc group id : %d(%s) \n", getgid(), getgrgid(getgid())->gr_name);
	printf("my valid group id : %d(%s) \n", getegid(), getgrgid(getgid())->gr_name);
}
