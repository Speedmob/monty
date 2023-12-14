#include "monty.h"
global_t glob_t;
/**
 * main - Entry point
 * @argc: num of args
 * @argv: args vector
 *
 * Return: Always 0 (Success)
*/
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	glob_t.exit_condition = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	glob_t.file = fopen(argv[1], "r");
	if (!glob_t.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	mont_epter(&stack);
	free_stack(stack);
	if (glob_t.exit_condition)
		exit(EXIT_FAILURE);
	return (0);
}
/**
 * get_instruct - gets function
 * @buffer: line
 *
 * Return: function in line
*/
ins_func get_instruct(char *buffer)
{
	int i = 0;
		instruction_t ins[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{NULL, NULL}
	};
	while (ins[i].f && strcmp(ins[i].opcode, buffer) != 0)
		i++;
	return (ins[i].f);
}
/**
 * mont_epter - reads .m file and interpets it
 * @stack: stack
 */
void mont_epter(stack_t **stack)
{
	char *token = NULL, *delim = "\r\t\n ";
	ins_func ins;
	int len = 0, i = 0, iter = 0;
	unsigned int linenum = 1;
	size_t c = 0;

	while ((len = getline(&glob_t.buffer, &c, glob_t.file)) != EOF)
	{
		token = strtok(glob_t.buffer, delim);
		if (token == NULL || token[0] == '#')
		{
			linenum++;
			continue; }
		ins = get_instruct(token);
		if (!ins)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", linenum, token);
			glob_t.exit_condition = -1;
			break; }
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, delim);
			for (iter = 0; token[iter] != '\0'; iter++)
			{
				if (!isdigit(token[iter]) && token[0] != '-')
				{
				printf("L%d: usage: push integer\n", linenum);
				glob_t.exit_condition = -1;
				break; }}
			if (glob_t.exit_condition)
				break;
			glob_t.num = atoi(token); }
		ins(stack, linenum);
		linenum++; }
	free(glob_t.buffer);
	i = fclose(glob_t.file);
	if (i == -1)
		exit(-1);
}
