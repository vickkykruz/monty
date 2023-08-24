#include "monty.h"
/**
 * opcode_sub - This is a function that return the substracted first two node
 * @stack: This is an argument that reprsent the given stack
 * @l_cnt: This is an argument that reprsent the amount of argument passed
 *
 * Return: This function will return a void (nothing)
 */
void opcode_sub(stack_t **stack, unsigned int l_cnt)
{
	int num;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", l_cnt);
		exit(EXIT_FAILURE);
	}


	num = ((*stack)->next->n) - ((*stack)->n);
	opcode_pop(stack, l_cnt);
	(*stack)->n = num;
}
