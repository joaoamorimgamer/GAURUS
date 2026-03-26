#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
int main(int argc, char **argv)
{
	float version = 1.0;
	int year = 2026;
	if(argc == 1)
	{
		//mkdir(argv[1], 755);
		printf("%s: missing operand\n", argv[0]);
		printf("Try '%s --help' for more information.\n", argv[0]);
		return 1;
	}
	else if(argc > 1)
	{
		if(strcmp(argv[1], "--help") == 0)
		{
			printf("Usage: %s [OPTION]... DIRECTORY...\n", argv[0]);
			printf("Create the DIRECTORIE(s), if they do not already exist.\n\n");
			printf("  -p, --parents		creates child directories\n");
			printf("  -v, --verbose		prints a message for every directory created\n");
			printf("  --help		print this help page and exit\n");
			printf("  --version		show information about the version and exit\n");
			return 0;
		}
		else if(strcmp(argv[1], "--version") == 0)
		{
			printf("%s (GAURUS) %.1lf\n", argv[0], version);
			printf("Copyright (C) %d João Pedro Amorim Oliveira.\n", year);
			printf("License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
			printf("This is free software: you are free to change and redistribute it.\n");
			printf("There is NO WARRANTY, to the extent permitted by law.\n\n");
			printf("Written by João Pedro Amorim Oliveira.\n");
			return 0;
		}
		/*else if(strcmp(argv[1], "--parents") == 0)
		{

			return 0;
		}
		*/
	}	
       	if(mkdir(argv[1], 755) != 0)
	{
		printf("%s: cannot create directory '%s': %s\n", argv[0], argv[1], strerror(errno));
		return 1;
	}
	return 0;
}
