#include "monty.h"
/**
 * _pall - prints all in stack
 * @stack: stack
 * @line_number: line number
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void)line_number;

	node = *stack;
	while (node)
	{
		printf("%d\n", node->n);
		node = node->next; }
}
