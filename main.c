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
		printf("USAGE: monty file\n");
		return (1);
	}

	char *file_name = argv[1];
	FILE *file = fopen(file_name, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", file_name);
		return (1);
	}

	stack_t *stack = NULL;
	char *line;
	int counter = 0;

	while (fgets(line, MAX_BUFFER, file))
	{
		process_line(&stack, line, counter);
		counter++;
	}

	fclose(file);
	return (0);
}