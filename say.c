#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
  int nline = 0;
  int firstarg = 1;
  if(argc > 1 && strcmp(argv[1], "-n") == 0)
  {
    nline = 1;
    firstarg = 2;
  }
  for(int i = firstarg; i < argc; i++)
  {
    printf("%s", argv[i]);
    if(i < argc - 1)
    {
      printf(" ");
    }
  }
  if(!nline)
  {
    printf("\n");
  }
  return 0;
}
