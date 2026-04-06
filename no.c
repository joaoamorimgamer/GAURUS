#include <stdio.h>
#include <string.h>
#include <getopt.h>

#define PROGRAM_NAME "no"

#define AUTHORS "João Pedro Amorim Oliveira"

void
usage()
{
  printf("%s: [OPTION]... [STRING]\n", PROGRAM_NAME);
	printf("Print a string repeatedly until killed.\n\n");
	printf("   -h, --help	print this help page and exit\n");
  printf("   -v, --version  print version information and exit\n");
}

int
main(int argc, char *argv[])
{
  int c;
  int year = 2026;
  float version = 1.3;

  static struct option const longopts[] =
  {
    {"help", no_argument, NULL, 'h'},
    {"version", no_argument, NULL, 'v'},
    {NULL, 0, NULL, 0}
  };
  while((c = getopt_long(argc, argv, "hv", longopts, NULL)) != -1)
  {
    switch(c)
    {
      case 'h':
        usage();
        return 0;
      case 'v':
        printf("%s (GAURUS coreutils) %.1f\n", argv[0], version);
        printf("Copyright (C) %d GAURUS Project\n", year);
        printf("License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
        printf("This is free software: you are free to change and redistribute it.\n");
        printf("There is NO WARRANTY, to the extent permitted by law.\n\n");
        printf("Written by %s.\n", AUTHORS);
        return 0;
    }
  }
	if(argc == 1)
	{
		while(1)
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
