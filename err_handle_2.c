#include "monty.h"

/**
 * stderr_empty - stack empty message.
 * @line_number: line number of the instruction.
 * Return: EXIT_FAILURE
 */
void stderr_empty(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty", line_number);
	exit(EXIT_FAILURE);
}
