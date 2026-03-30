#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char **argv)
{
	if(argc > 1)
	{
	
		if(strcmp(argv[1], "--help") == 0)
		{
			printf("Usage: %s [OPTION]...\n", argv[0]);
      printf("   -L, --logical  print the logical path, containing symbolic links\n");
      printf("   -P, --physical print the physical path, resolving all symbolic links to their real location\n");
			printf("   --help print this help page and exit\n\n");
      printf("If no argument is specified, default to -P.\n");
			return 0;
		}
    else if(strcmp(argv[1], "--physical") == 0 || strcmp(argv[1], "-P") == 0)
    {
      char *cwd = getcwd(NULL, 0);
      if(cwd != NULL)
	    {
		    printf("%s\n", cwd);
        free(cwd);
        return 0;
	    } 
    }
    else if(strcmp(argv[1], "--logical") == 0 || strcmp(argv[1], "-L") == 0)
    {
      char *lcwd = getenv("PWD");
      if(lcwd != NULL)
      {
        printf("%s\n", lcwd);
        return 0;
      }
      else {
        printf("%s: %s\n", argv[0], strerror(errno));
        return 1;
      }
    }
	}
  else if(argc == 1)
  {
    char *cwd = getcwd(NULL, 0);
    if(cwd != NULL)
    {
      printf("%s\n", cwd);
      free(cwd);
      return 0;
    }
    else {
      printf("%s: %s\n", argv[0], strerror(errno));
      return 1;
    }
  }
  return 0;
}
