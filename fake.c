#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	if(argc > 1)
	{
		if(strcmp(argv[1], "--help") == 0)
		{
			printf("%s - Do nothing, unsuccessfully\n\n", argv[0]);
			printf("Usage:\n");
			printf("--help	print this help page and exit\n");
		}
	}
	return 1;
}
