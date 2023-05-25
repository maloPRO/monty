#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "monty.h"

void _nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

void _pchar(stack_t **stack, unsigned int line_number)
{
    stack_t *runner;
    int val;

    if (*stack == NULL)
    {
        printf("L%d: can't pchar, stack empty\n", line_number);
        error_exit(stack);
    }

    runner = *stack;
    val = runner->n;

    if (!isprint(val))
    {
        printf("L%d: can't pchar, value out of range\n", line_number);
        error_exit(stack);
    }

    putchar(val);
    putchar('\n');
}

void _pstr(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
    stack_t *runner;
    int val;

    runner = *stack;

    while (runner != NULL)
    {
        val = runner->n;
        if (val == 0)
            break;
        if (!isprint(val))
        {
            break;
        }
        putchar(val);
        runner = runner->next;
    }
    putchar('\n');
}

void _stack(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    sq_flag = 0;
}

void _queue(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    sq_flag = 1;
}

