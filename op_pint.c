#include "main.h"
/**
 * opcode_pint - This is a function that return the printed value at the top
 * of the stack
 * @stack: This is an argument that reprsent the given stack
 * @cmd_line: This is an argument reprsent the command line passed
 *
 * Return: This function return a void (nothing)
 */
void opcode_pint(stack_t **stack, unsigned int cmd_line)
{
	stack_t *tmp = *stack;

	if (!tmp)
	{
		free_glob();
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", cmd_line);
		exit(EXIT_FAILURE);
	}

	for (; tmp->next; tmp = tmp->next)
		;
	printf("%d\n", tmp->n);
}
