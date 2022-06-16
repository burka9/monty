#include "monty.h"

instruction_t opcodes[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
};

/**
 * pall - prints all the values in the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the instruction
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * push - adds a new node to the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the instruction
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = line_number;

	if (*stack == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		new->next = *stack;
		new->prev = NULL;
		(*stack)->prev = new;
		*stack = new;
	}
}

instruction_t find_opcodes(char *str)
{
	instruction_t opcode;

	for (int i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, str) == 0)
		{
			opcode = opcodes[i];
			return opcode;
		}
	}
	opcode.opcode = NULL;
	return opcode;
}
