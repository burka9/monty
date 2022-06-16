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
	if (argc != 2)
	{
		print_stderr("USAGE: monty file\n");
		return (1);
	}

	char *file_name = argv[1];
	FILE *file = fopen(file_name, "r");

	if (file == NULL)
	{
		// print_stderr("Error: Can't open file %s\n", file_name);
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		return (1);
	}

	stack_t *stack = NULL;
	char *line = (char *)malloc(sizeof(char) * MAX_BUFFER);
	int counter = 0;

	while (fgets(line, MAX_BUFFER-1, file))
	{
		process_line(&stack, line, counter);
		counter++;
	}

	fclose(file);
	return (0);
}
