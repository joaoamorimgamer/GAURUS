#include <stdio.h>
#include <getopt.h>

#define AUTHORS "João Pedro Amorim Oliveira"

#define PROGRAM_NAME "real"

void
usage()
{
  printf("Usage: %s [ignored command line arguments]\n", PROGRAM_NAME);
  printf("or:    %s OPTION\n\n", PROGRAM_NAME);
  printf("Exit with a status code indicating success.\n\n");
  printf("   --help print this help page and exit\n");
  printf("   --version output version information and exit\n");
}
int
main(int argc, char **argv)
{
  int year = 2026;
  float version = 1.3;
  static struct option const longopts[] =
  {
    {"help", no_argument, NULL, 'h'},
    {"version", no_argument, NULL, 'v'},
    {NULL, 0, NULL, 0}
  };
  int c;
  while((c = getopt_long(argc, argv, "hv", longopts, NULL)) != -1)
  {
    switch (c)
    {
      case 'h':
        usage();
        break;
      case 'v':
        printf("%s (GAURUS) %.1f\n", argv[0], version);
        printf("Copyright (C) %d %s.\n", year, AUTHORS);
        printf("License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
        printf("This is free software: you are free to change and redistribute it.\n");
        printf("There is NO WARRANTY, to the extent permitted by law.\n\n");
        printf("Written by %s\n", AUTHORS);
        break;
    }
  }
  return 0;
}
