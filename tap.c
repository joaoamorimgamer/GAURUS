#include <stdio.h>
#include <errno.h>
#include <string.h>
int main(int argc, char **argv)
{
	if(argc == 1)
	{
		printf("%s: missing operand\n", argv[0]);
		return 1;
	}
	for(int i = 1; i < argc; i++)
	{
		FILE *file;
		file = fopen(argv[i], "w");
		if(file == NULL)
		{
			printf("%s: %s\n", argv[0], strerror(errno));	
			return 1;
		}
	}
	return 0;
}
