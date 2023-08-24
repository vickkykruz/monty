#include "monty.h"
/**
 * opcode_pop - This is a function that return the pop element of the stack
 * @stack: This is an argument that reprsent the given stack
 * @cmd_line: This is an argument that reprsent the amount of cmd_line passed
 *
 * Return: This function return a void (nothing)
 */
void opcode_pop(stack_t **stack, unsigned int cmd_line)
{
	stack_t *tmp = NULL;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", cmd_line);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}
