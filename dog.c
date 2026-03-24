#include <stdio.h>
#include <string.h>
#include <errno.h>
int main(int argc, char **argv)
{
	FILE *file = fopen(argv[1], "r");
	char c;
	float version = 1.0;
	int year = 2026;
	char stdinp[50];
	while(argc == 1 || strcmp(argv[1], "-") == 0)
	{
		/* prints to standard output what the user has typed until killed. */
		fgets(stdinp, sizeof(stdinp), stdin);
		printf("%s", stdinp);
	}
	/* useless stuff */
	if(strcmp(argv[1], "--help") == 0)
	{
		printf("Usage: %s [OPTION]... [FILE]...\n", argv[0]);
		printf("Concatenate FILE(S) to standard output.\n\n");
		printf("--help	print this help page and exit\n");
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
	else if(strcmp(argv[1], "-v") == 0)
	{
		printf("%s (GAURUS) %.1lf\n", argv[0], version);
		printf("Copyright (C) %d João Pedro Amorim Oliveira.\n", year);
		printf("License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
		printf("This is free software: you are free to change and redistribute it.\n");
		printf("There is NO WARRANTY, to the extent permitted by law.\n\n");
		printf("Written by João Pedro Amorim Oliveira.\n");
		return 0;

	}
	/* end of useless stuff */
	if(file == NULL)
	{
		/* prints what error code errno gave. */
		printf("%s: %s\n", argv[0], strerror(errno));
		return 1;
	}
	/* print file */
	while((c = fgetc(file)) != EOF)
	{
		putchar(c);
	}
	fclose(file);
	return 0;
}
