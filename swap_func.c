#include "monty.h"
/**
 * _swap - swap top 2
 * @stack: stack
 * @line_number: num of lines
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int temp;

	node = *stack;
	if (!node || !node->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(glob_t.file);
		free(glob_t.buffer);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = node->n;
	node->n = node->next->n;
	node->next->n = temp;
}
