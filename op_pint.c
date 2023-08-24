#include "main.h"
/**
 * pint - This is a function that return the printed value at the to of the
 * stack
 * @stack: This is an argument that reprsent the given stack
 * @cmd_line: This is an argument that reprsent the amount of lines passed
 *
 * Return: This function return a void
 */
void opcode_pint(stack_t **stack, unsigned int cmd_line)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", cmd_line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
