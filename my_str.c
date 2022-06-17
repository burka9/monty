#include "monty.h"

/**
 * process_line - processes a line of the file
 * @stack: pointer to the top of the stack
 * @line: line of the file
 * @line_number: line number of the instruction
 * Return: void
 */
void process_line(stack_t **stack, char *line, unsigned int line_number)
{
	char *code, *arg;
	int i, j, casted;

	i = 0;
	j = 0;
	line = trim(line);
	code = malloc(sizeof(char) * (strlen(line) + 1));
	arg = malloc(sizeof(char) * (strlen(line) + 1));

	if (code == NULL || arg == NULL)
	{
		stderr_malloc();
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < (int)strlen(line); i++)
	{
		if (line[i] == ' ')
			break;
		code[i] = line[i];
	}
	code[i] = '\0';
	while (i < (int)strlen(line))
	{
		if (line[i] != ' ')
			break;
		i++;
	}
	for (j = 0; i < (int)strlen(line); i++)
	{
		if (line[i] == ' ')
			break;
		arg[j] = line[i];
		j++;
	}

	arg[j] = '\0';

	casted = atoi(arg);
	execute(stack, code, casted, line_number);
}

/**
 * execute - executes the opcode
 * @stack: pointer to the top of the stack
 * @code: opcode
 * @arg: argument
 * @line_number: line number of the instruction
 * Return: void
 */
void execute(stack_t **stack, char *code, int arg, unsigned int line_number)
{
	instruction_t *opcodes;
	instruction_t opcode;
	int i = 0;

	opcodes = (instruction_t *)malloc(sizeof(instruction_t) * 4);

	if (opcodes == NULL)
	{
		stderr_malloc();
		exit(EXIT_FAILURE);
	}

	set_opcodes(opcodes);

	if (strcmp(code, "pall") != 0 && arg == 0)
	{
		stderr_int(line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, code) == 0)
		{
			opcode = opcodes[i];
			break;
		}
	}
	if (opcodes[i].opcode == NULL)
	{
		stderr_unknown(code, line_number);
		exit(EXIT_FAILURE);
	}

	opcode.f(stack, arg);
}

/**
 * ltrim - removes leading whitespace from a string
 * @s: string to be trimmed
 * Return: pointer to trimmed string
 */
char *ltrim(char *s)
{
	while (isspace(*s))
		s++;
	return (s);
}

/**
 * rtrim - removes leading and trailing whitespace
 * @s: string to trim
 * Return: pointer to trimmed string
 */
char *rtrim(char *s)
{
	char *back = s + strlen(s);

	while (isspace(*--back))
		;
	*(back + 1) = '\0';
	return (s);
}

/**
 * trim - removes leading and trailing whitespace
 * @s: string to be trimmed
 * Return: trimmed string
 */
char *trim(char *s)
{
	return (rtrim(ltrim(s)));
}
