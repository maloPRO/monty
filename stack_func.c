#include "monty.h"

/**
 * push - func
 * @stack: input
 * @line_number: input
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack = NULL;
	int value;
	char *tok_val = strtok(NULL, " \n");

	if (tok_val == NULL || !is_integer(tok_val))
		print_error(4, line_number, NULL, *stack);
	value = atoi(tok_val);

	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		print_error(5, line_number, NULL, *stack);
	}

	new_stack->next = *stack;
	new_stack->prev = NULL;
	new_stack->n = value;
	if (*stack)
		(*stack)->prev = new_stack;
	*stack = new_stack;
}


/**
 * pall - func
 * @stack: input
 * @line_number: input
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	UNUSED(stack);
	UNUSED(line_number);
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}


/**
 * pint - func
 * @stack: input
 * @line_number: input
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (is_empty(*stack))
		print_error(6, line_number, "pint", *stack);
	printf("%d\n", (*stack)->n);
}



/**
 * pop - func
 * @stack: input
 * @line_number: input
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (is_empty(*stack))
		print_error(7, line_number, NULL, *stack);

	*stack = (*stack)->next;

	if (tmp)
		free(tmp);
	tmp = NULL;
}





/**
 * swap - func
 * @stack: input
 * @line_number: input
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp = 0;

	if (is_empty(*stack) || stack_len(*stack) < 2)
		print_error(8, line_number, "swap", *stack);

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

