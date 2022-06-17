#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the instruction
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		stderr_empty(line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	temp->prev = NULL;
	*stack = temp;
}
