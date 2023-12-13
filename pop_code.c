#include "monty.h"
/**
 * _pop - program that removes the top element of the stack
 * @stack: parameter for stack head
 * @line_number: parameter for line number
 * Return: it returns nothing
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *i;

	if (*stack == NULL)
	{
		fprintf(stderr, "L<line_number>: can't pop an empty stack\n");
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	i = *stack;
	*stack = i->next;
	free(i);
}
