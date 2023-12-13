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
		fprintf(stderr, "L<line_number>: can't pint, stack empty\n");
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
