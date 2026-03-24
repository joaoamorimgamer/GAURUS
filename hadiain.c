#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	if(argc == 2)
	{
	
		if(strcmp(argv[1], "--help") == 0)
		{
			printf("%s: %s\n", argv[0], argv[0]);
			printf("   Print the name of the current working directory.\n");
			printf("   Options:\n");
			printf("     --help print this help page and exit\n\n");
			printf("   Exit Status:\n");
			printf("   Returns 0 unless the current directory cannot be read.\n");
			return 0;
		}
	}
	/* This program name is strange because it stands for wHAt DIrectory Am i IN, don't judge me for bad names :) */
	
	char *cwd = malloc(sizeof(char));
	cwd = getcwd(NULL, 0);
	if(cwd != NULL)
	{
		printf("%s\n", cwd);
	}
	free(cwd);
	return 0;
}
