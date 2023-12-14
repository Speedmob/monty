#include "monty.h"
/**
 * _add - adds first 2 elements
 * @stack: stack
 * @line_number: line number
*/
void _add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(glob_t.file);
		free(glob_t.buffer);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number); }
