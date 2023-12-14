#include "monty.h"
/**
 * _pstr - prints all in stack
 * @stack: stack
 * @line_number: line number
*/
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void)line_number;

	node = *stack;
	while (node && node->n <= 127 && node->n > 0)
	{
		printf("%c", node->n);
		node = node->next; }
	printf("\n");
}
