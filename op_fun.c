#include "monty.h"

/**
 * set_opcodes - sets the opcodes
 * @opcodes: pointer to the opcodes
 * Return: void
 */
void set_opcodes(instruction_t *opcodes)
{
	opcodes[0].opcode = "push";
	opcodes[0].f = push;
	opcodes[1].opcode = "pall";
	opcodes[1].f = pall;
}

/**
 * pall - prints all the values in the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the instruction
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;
	
	temp = (*stack);

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
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		stderr_malloc();
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
