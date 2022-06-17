#include "monty.h"

/**
 * main - main function
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0 on success
 *	1 on failure
 */
int main(int argc, char **argv)
{
	int counter;
	char *line;
	char *file_name;
	stack_t *stack;
	FILE *file;

	if (argc != 2)
	{
		stderr_usage();
		return (1);
	}

	file_name = argv[1];
	file = fopen(file_name, "r");

	if (file == NULL)
	{
		stderr_fopen(file_name);
		return (1);
	}

	stack = NULL;
	line = (char *)malloc(sizeof(char) * MAX_BUFFER);
	counter = 0;

	while (fgets(line, MAX_BUFFER - 1, file))
	{
		process_line(&stack, line, counter);
		counter++;
	}

	fclose(file);
	return (0);
}
