#include "monty.h"

/**
 * process_line - processes a line of the file
 * @line: line of the file
 * Return: void
 */
void process_line(stack_t **stack, char *line, unsigned int line_number)
{
	line = trim(line);
	char *code = malloc(sizeof(char) * (strlen(line) + 1));
	char *arg = malloc(sizeof(char) * (strlen(line) + 1));
	int i = 0;

	if (code == NULL || arg == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < strlen(line); i++)
	{
		if (line[i] == ' ')
		{
			code[i] = '\0';
			break;
		}
		code[i] = line[i];
	}
	while (i < strlen(line))
	{
		if (line[i] == ' ')
			i++;
		else
			break;
	}
	for (int j = 0; i < strlen(line); i++)
	{
		if (line[i] == ' ')
		{
			arg[j] = '\0';
			break;
		}
		arg[j] = line[i];
		j++;
	}

	int _arg = atoi(arg);

	execute(stack, code, _arg, line_number);
}

/**
 * execute - executes the opcode
 * @code: opcode
 * @arg: argument
 * Return: void
 */
void execute(stack_t **stack, char *code, int arg, unsigned int line_number)
{
	instruction_t opcode;
	int i = 0;

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
		printf("L%i: unknown instruction %s\n", line_number, code);
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
