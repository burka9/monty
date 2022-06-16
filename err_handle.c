#include "monty.h"

void print_stderr(char *s)
{
	fputs(s, stderr);
	exit(1);
}