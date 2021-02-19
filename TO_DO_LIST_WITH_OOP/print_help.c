#include <stdio.h>
#include <stddef.h>
#include <string.h>

void print_help(char** argv)
{
	printf("\nSyntax:\n\t%s --add task date : for addition new task"
		"\n\t\t    --show : for print first task to do"
		"\n\t\t    --rm : for remove completed task\n", argv[0]);
}

