#include "monty.h"

FILE *fd;

/**
 * main - function
 * @argc: input
 * @argv: input
 * Return: int
 */
int main(int argc, char **argv)
{
	char instruct_buff[MAX_BUFFER];
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t instruction[] = {{"push", push}, {"pall", pall}, {"pint", pint},
					{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop},
					{"sub", sub}, {"div", divide}, {"mul", mul}, {"mod", mod},
					{"pchar", pchar}, {"pstr", pstr}, {NULL, NULL}};

	if (argc != 2)
		print_error1(1, 0, NULL, stack);
	fd = fopen(argv[1], "r");

	if (fd == NULL)
		print_error1(2, 0, argv[1], stack);
	while (fgets(instruct_buff, MAX_BUFFER, fd) != NULL)
	{
		int i;
		char *opcode = strtok(instruct_buff, " \n");

		line_number++;
		if (!opcode || *opcode == '#')
			continue;
		for (i = 0; instruction[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instruction[i].opcode) == 0)
			{
				instruction[i].f(&stack, line_number);
				break;
			}
		}
		if (instruction[i].opcode == NULL)
		{
			print_error(3, line_number, opcode, stack);
		}
	}
	fclose(fd);
	free_dlistint(stack);
	return (0);
}
