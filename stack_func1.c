#include "monty.h"


/**
 * add - func
 * @stack: input
 * @line_number: input
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (is_empty(*stack) || stack_len(*stack) < 2)
		print_error(8, line_number, "add", *stack);

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}




/**
 * nop - func
 * @stack: input
 * @line_number: input
 */
void nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}




/**
 * sub - func
 * @stack: input
 * @line_number: input
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (is_empty(*stack) || stack_len(*stack) < 2)
		print_error(8, line_number, "sub", *stack);

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}




/**
 * divide - func
 * @stack: input
 * @line_number: input
 */
void divide(stack_t **stack, unsigned int line_number)
{
	if (is_empty(*stack) || stack_len(*stack) < 2)
		print_error(8, line_number, "div", *stack);

	if ((*stack)->n == 0)
		print_error(9, line_number, NULL, *stack);

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}



/**
 * mul - func
 * @stack: input
 * @line_number: input
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (is_empty(*stack) || stack_len(*stack) < 2)
		print_error(8, line_number, "mul", *stack);

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}




