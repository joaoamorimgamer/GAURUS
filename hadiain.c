#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define PROGRAM_NAME "hadiain"

#define AUTHORS "João Pedro Amorim Oliveira"

void usage()
{
  printf("Usage: %s [OPTION]...\n", PROGRAM_NAME);
  printf("   -L, --logical  print the logical path, containing symbolic links\n");
  printf("   -P, --physical print the physical path, resolving all symbolic links to their real location\n");
	printf("   --help print this help page and exit\n\n");
  printf("If no argument is specified, default to -P.\n");
}

int main(int argc, char **argv)
{
  char *cwd;
  char *lcwd;
  int c;
  float version = 1.1;
  int year = 2026;
  struct option longopts[] =
  {
    {"physical", no_argument, NULL, 'P'},
    {"logical", no_argument, NULL, 'L'},
    {"help", no_argument, NULL, 'h'},
    {"version", no_argument, NULL, 'v'},
    {NULL, 0, NULL, 0}
  };

  while((c = getopt_long(argc, argv, "hvLP", longopts, NULL)) != -1)
  {
    switch(c)
    {
      case 'h':
        usage();
        break;
      case 'v':
        printf("%s (GAURUS) %.1lf\n", argv[0], version);
        printf("Copyright (C) %d %s.\n", year, AUTHORS);
        printf("License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
        printf("This is free software: you are free to change and redistribute it.\n");
        printf("There is NO WARRANTY, to the extent permitted by law.\n\n");
        printf("Written by %s.\n", AUTHORS);
        break;
      case 'L':
        lcwd = getenv("PWD");
        if(lcwd != NULL)
        {
          printf("%s\n", lcwd);
        }
        break;
      case 'P':
        cwd = getcwd(NULL, 0);
        if(cwd != NULL)
        {
          printf("%s\n", cwd);
        }
        break;
    }
  }
  if(argc == 1)
  {
    cwd = getcwd(NULL, 0);
    printf("%s\n", cwd);
    return 0;
  }
  return 0;
}
