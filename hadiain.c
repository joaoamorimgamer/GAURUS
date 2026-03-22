#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char **argv)
{
	if(argc == 2)
	{
	
		if(strcmp(argv[1], "--help") == 0)
		{
			printf("%s - what directory am i in\n", argv[0]);
			printf("Usage: hadiain [NO ARGUMENTS]\n");
			printf("--help	print this help page and exit\n");
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
