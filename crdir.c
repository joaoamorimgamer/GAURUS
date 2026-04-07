#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <sys/stat.h>
#include <errno.h>

#define PROGRAM_NAME "crdir"

#define AUTHORS "João Pedro Amorim Oliveira"

void
usage()
{
  printf("Usage: %s [OPTION]... DIRECTORY...\n", PROGRAM_NAME);
	printf("Create the DIRECTORIE(s), if they do not already exist.\n\n");
	printf("  -h, --help		print this help page and exit\n");
	printf("  -v, --version		show information about the version and exit\n");
}

int 
main(int argc, char **argv)
{
  opterr = 0;
  int c;
	float version = 1.3;
	int year = 2026;
  static struct option const longopts[] =
  {
    {"help", no_argument, NULL, 'h'},
    {"version", no_argument, NULL, 'v'},
    {NULL, 0, NULL, 0}
  };

	if(argc == 1)
	{
		printf("%s: missing operand\n", argv[0]);
		printf("Try '%s --help' for more information.\n", argv[0]);
		return 1;
	}
  while((c = getopt_long(argc, argv, "hv", longopts, NULL)) != -1)
  {
    switch(c)
    {
      case 'h':
        usage();
        return 0;
      case 'v':
        printf("%s (GAURUS coreutils) %.1lf\n", argv[0], version);
			  printf("Copyright (C) %d %s.\n", year, AUTHORS);
			  printf("License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
			  printf("This is free software: you are free to change and redistribute it.\n");
			  printf("There is NO WARRANTY, to the extent permitted by law.\n\n");
			  printf("Written by %s.\n", AUTHORS);
			  return 0;
      default:
        for(int i = 1; i < argc; i++)
        {
          if(mkdir(argv[i], 0755) == 0)
	        {
	  	      return 0;
	        }
        }
    }
	}
  for(int i = 1; i < argc; i++)
  {
    if(mkdir(argv[i], 0755) != 0)
	  {
	  	printf("%s: cannot create directory '%s': %s\n", argv[0], argv[i], strerror(errno));
	  	return 1;
	  }
  }
	return 0;
}
