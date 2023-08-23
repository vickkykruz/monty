#include "main.h"
/**
 * opcode_pop - This is a function that return the exectution of the top
 * element from the stack
 * @stack: This is an argument that reprsent the given stack
 * @cmd_line: This is an argument that reprsent the given num of cmd line
 *
 * Return: This function return a void (nothing)
 */
void opcode_pop(stack_t **stack, unsigned int cmd_line)
{
	stack_t *tmp = *stack, *prev_node;

	if (!tmp)
	{
		free_glob();
		fprintf(stderr, "L<%d>: can't pop an empty stack\n", cmd_line);
		exit(EXIT_FAILURE);
	}

	if (!tmp->next)
	{
		*stack = NULL;
		free(tmp);
		return;
	}

	for (; tmp->next->next; tmp = tmp->next)
		;
	prev_node = tmp->next;
	tmp->next = NULL;

	free(prev_node);
}
