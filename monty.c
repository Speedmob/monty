#include "monty.h"
/**
 * main - Entry point
 * argc: num of args
 * argv: args vector
 *
 * Return: Always 0 (Success)
*/
int main(int argc, char *argv[])
{
	char *buffer = NULL, *token = NULL, *delim = "\n ";
	ins_func ins;
	int len = 0, i = 0, num = 0, iter = 0, linenum = 1;
	size_t c = 0;
	FILE *open = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open = fopen(argv[1], "r");
	if (!open)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while((len = getline(&buffer, &c, open)) != EOF)
	{
		/*probably can move this part to a separate function
		 * to reduce space
		 * also stack isn't initialized
		 * and a free function for doubly LL is needed
		 * after (to not leak/lose memory)*/
		token = strtok(buffer, delim);
		ins = get_instruct(token);
		if (!ins)
		{

		}
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, delim);
			for (iter = 0; token[iter] != '\0'; iter++)
			{
				if (!isdigit(token[iter]))
				{
				printf("L%d: usage: push integer\n", linenum);
				exit(EXIT_FAILURE); }}
			num = atoi(token);
			printf("%d\n", num);
			/*ins func call with int*/
			linenum++;
			continue; }
		/*ins func call without an int*/
	}
	free(buffer);
	i = fclose(open);
	if (i == -1)
		exit(-1);
	return (0);
}
/**
 * get_instruct - gets function
 * @buffer: line
 *
 * Return: function in line
*/
/*ins_func get_instruct(char *buffer)
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
		{NULL, NULL}
	};


	while (ins[i].f && strcmp(ins[i].opcode, buffer) != 0)
			i++;
	return (ins[i].f);
}*/
ins_func get_instruct(char *buffer)
{
	/*above code doesn't work because functions aren't initialized/coded*/
	printf("%s \n", buffer);
	return (NULL);
}
