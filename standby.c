#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("%s: missing operand\n", argv[0]);
		return 1;
	}
	sleep((unsigned int) atoi (argv[1]));	
	return 0;
}
