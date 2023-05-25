#include "monty.h"

/**
 * free_dlistint - frees memory
 * @head: input
 */
void free_dlistint(stack_t *head)
{
	stack_t *node = head;

	while (node)
	{
		stack_t *tmp = node;

		node = node->next;
		free(tmp);
	}
}
