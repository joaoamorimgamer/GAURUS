#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define LINE 1024
#define END "EOF\n" "_ACEOF\n" "<<EOF\n"
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
    char buffer[LINE];
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
    else
    {
    	for (int i = 1; i < argc; i++)
    	{
		FILE *file = fopen(argv[i], "r");
		if (file == NULL)
		{
			fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));
			continue; 
		}
		else
		{
			d_stream(file);
			fclose(file);
       		}
     	}
    }
    return 0;
}
