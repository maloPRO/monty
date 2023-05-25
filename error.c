#include "monty.h"

/**
 * print_error - func
 * @error: input
 * @line_number: input
 * @opcode: input
 * @stack: input
 */
void print_error(int error, unsigned int line_number, char *opcode,
		stack_t *stack)
{
	free_dlistint(stack);
	switch (error)
	{
		case 3:
			fprintf(stderr, "L%d: Unknown instruction %s\n", line_number, opcode);
			break;
		case 4:
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			break;
		case 5:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 6:
			fprintf(stderr, "L%d: can't %s, stack empty\n", line_number, opcode);
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
			break;
		case 8:
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, opcode);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n", line_number);
			break;
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			break;
	}
	fclose(fd);
	exit(EXIT_FAILURE);
}


/**
 * print_error1 - func
 * @error: input
 * @line_number: input
 * @opcode: input
 * @stack: input
 */
void print_error1(int error, unsigned int line_number, char *opcode,
		stack_t *stack)
{
	UNUSED(stack);
	UNUSED(line_number);

	switch (error)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", opcode);
			break;
	}
	exit(EXIT_FAILURE);
}
