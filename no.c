#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	if(argc == 2 && strcmp(argv[1], "--help") == 0)
	{
			printf("%s: [OPTION]... [STRING]\n",argv[0]);
			printf("Print a string repeatedly until killed.\n\n");
			printf("--help	print this help page and exit\n");
			return 0;
	}
	else if(argc ==	1)
	{
		while(0==0)
		{
			printf("y\n");
		}
	}
	else if(argc == 2)
	{
		while(0==0)
		{
			printf("%s\n", argv[1]);
		}
	}
	else if(argc == 3)
	{
		while(0==0)
		{
			printf("%s %s\n", argv[1], argv[2]);
		}
	}
	return 0;
}
