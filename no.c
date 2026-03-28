#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	if(argc == 2 && strcmp(argv[1], "--help") == 0)
	{
			printf("%s: [OPTION]... [STRING]\n",argv[0]);
			printf("Print a string repeatedly until killed.\n\n");
			printf("   --help	print this help page and exit\n");
			return 0;
	}
	if(argc == 1)
	{
		while(0==0)
		{
			printf("y\n");
		}
	}
	while(1)
	{
		for(int i = 1; i < argc; i++)
		{
			printf("%s", argv[i]);
			if(i < argc - 1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
