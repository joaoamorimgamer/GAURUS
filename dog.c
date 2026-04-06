#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>

#define PROGRAM_NAME "dog"

#define AUTHORS "João Pedro Amorim Oliveira"

#define LINE 1024

#define END "EOF\n" "_ACEOF\n" "<<EOF\n"

void
usage()
{
  printf("Usage: %s [OPTION]... [FILE]...\n", AUTHORS);
  printf("Concatenate FILE(S) to standard output.\n\n");
  printf("If FILE is not specified or -, read standard input.\n\n");
  printf("   -h, --help print this help page and exit\n");
  printf("   -v, --version  print version information and exit\n");
}

void
d_stream(FILE *ifp)
{
	int c;
	while((c = fgetc(ifp)) != EOF)
	{
		putchar(c);
	}
}

int
main(int argc, char **argv)
{
    /* all of this is related to command line arguments */
    int c;
    int year = 2026;
    float version = 1.2;
    static struct option const longopts[] = {
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
        case '?':
          return 0;
      }
    }
    /* not anymore */
    char buffer[LINE];
    /* read what the user types and print it to stdout */ 
    if(argc == 1)
    {
	    d_stream(stdin);
      while(fgets(buffer, LINE, stdin) != NULL)
      {
        if(strcmp(buffer, END) == 0)
        {
          break;
        }
      }
    }
    /* main program function */
    else
    {
    	for (int i = 1; i < argc; i++)
    	{
        FILE *file = fopen(argv[i], "r");
		    if(file == NULL && strcmp(argv[i], "-h") != 0 && strcmp(argv[i], "--help") != 0 && strcmp(argv[i], "--version") != 0 && strcmp(argv[i], "-v") != 0)
 		    {
          fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));
          return 1;
		    }
		    else
		    {
			    d_stream(file);
			    fclose(file);
        }
        if(strcmp(argv[i], "-") == 0)
        {
          d_stream(stdin);
          while(fgets(buffer, LINE, stdin) != NULL)
          {
            if(strcmp(buffer, END) == 0)
            {
              break;
            }
          }
        }
      }
    }
    return 0;
}
