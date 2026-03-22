#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	if(argc > 1)
	{
		if(strcmp(argv[1], "--help") == 0)
		{
			printf("%s - do nothing, succesfully\n", argv[0]);
			printf("better version of 'true', by GNU Coreutils\n\n");
			printf("Usage:\n");
			printf("--help	display this help and exit\n");
		}
	}
	return 0;
}
