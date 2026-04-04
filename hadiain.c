#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define PROGRAM_NAME "hadiain"

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
