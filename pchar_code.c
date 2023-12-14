#include "monty.h"
/**
 * _pchar - prints the char at the top of the stack
 * @stack: parameter for stack head
 * @line_number: parameter to represent to line number
*/
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack || (*stack)->n > 127 || (*stack)->n < 0)
	{
		if (!(*stack))
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		else
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(glob_t.file);
		free(glob_t.buffer);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
