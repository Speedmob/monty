#include "monty.h"
/**
 * _pint - prints the value at the top of the stack
 * @stack: parameter for stack head
 * @line_number: parameter to represent to line number
 * Return: it returns nothing
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(glob_t.file);
		free(glob_t.buffer);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
