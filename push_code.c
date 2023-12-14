#include "monty.h"
/**
 * _push - pushes an int to stack
 * @stack: stack to push to
 * @line_number: line num
*/
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void)line_number;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(glob_t.file);
		free(glob_t.buffer);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	node->n = glob_t.num;
	node->next = *stack;
	node->prev = NULL;
	if (*stack)
		(*stack)->prev = node;
	*stack = node; }
