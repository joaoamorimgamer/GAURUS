#include <stdio.h>
#include <errno.h>
#include <string.h>
void d_stream(FILE *ifp)
{
	int c;
	while((c = fgetc(ifp)) != EOF)
	{
		putchar(c);
	}
}
int main(int argc, char **argv)
{
    FILE *file;
    float version = 1.1;
    int year = 2026;
    if(argc == 1 || strcmp(argv[1], "-") == 0)
    {
	    d_stream(stdin);
    }
    else
    {
    	for (int i = 1; i < argc; i++)
    	{
		file = fopen(argv[i], "r");
		if(file == NULL)
		{
			if(strcmp(argv[1], "--version") != 0)
			{
				fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));
			}
			continue;
		}
		else
		{
			d_stream(file);
			fclose(file);
       		}
     	}
    }
    if(strcmp(argv[1], "--version") == 0)
    {
	printf("%s (GAURUS) %.1lf\n", argv[0], version);
	printf("Copyright (C) %d João Pedro Amorim Oliveira.\n", year);
	printf("License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
	printf("This is free software: you are free to change and redistribute it.\n");
	printf("There is NO WARRANTY, to the extent permitted by law.\n\n");
	printf("Written by João Pedro Amorim Oliveira.\n");
	return 0;
    }
    return 0;
}
