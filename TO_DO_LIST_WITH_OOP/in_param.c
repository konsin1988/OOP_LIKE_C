#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#include "print_help.h"

int in_param(int argc, char** argv, char* operation)
{
	if(argc<=1)
	{
		printf("\n\t%s requires more parameters.\n"
			"\tSee '--help' for more information.\n", argv[0]);
	}
	else if(!strcmp(argv[1], "--help"))
	{
		print_help(argv);
	}
	else if(!strcmp(argv[1], "--add")) 
	{
		if(argc < 4)
		{
			printf("\n\t'--add' requires two parameters\n");
		}
		else
		{
			strcat(operation, "add");
			return 1;
		}
	}

	else if(!strcmp(argv[1], "--show")) 
	{
		if(argc != 2)
		{
			printf("\n\t'--show' requires no parameters\n");
		}
		else
		{
			strcat(operation, "show");
			return 1;
		}
	}

	else if(!strcmp(argv[1], "--rm")) 
	{
		if(argc != 2)
		{
			printf("\n\t'--rm' requires no parameters\n");
		}
		else
		{
			strcat(operation, "rm");
			return 1;
		}
	}
	else
	{
		printf("\n\tUnknown parameter.\n\t"
			"See '--help' for more information.\n");
	}
	return 0;
}

