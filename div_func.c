#include "monty.h"
/**
 * _div - divs first 2 elements
 * @stack: stack
 * @line_number: line number
*/
void _div(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next || !(*stack)->n)
	{
		if (*stack && !(*stack)->n)
			fprintf(stderr, "L%d: division by zero\n", line_number);
		else
			fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(glob_t.file);
		free(glob_t.buffer);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	(*stack)->next->n /= (*stack)->n;
	_pop(stack, line_number); }
