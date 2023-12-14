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
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(glob_t.file);
		free(glob_t.buffer);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	i = *stack;
	*stack = i->next;
	free(i);
}
