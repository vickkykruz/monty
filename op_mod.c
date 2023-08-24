#include "monty.h"
/**
 * opcode_mod - This is a function thay return the module of top next of the
 * stack
 * @stack: This is an argument that reprsent the given stack
 * @l_cnt: an argument that reprsent the amount of argumemt passed
 *
 * Return: This function return a void (nothing)
 */
void opcode_mod(stack_t **stack, unsigned int l_cnt)
{
	int num;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", l_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_cnt);
		exit(EXIT_FAILURE);
		return;
	}

	num = ((*stack)->next->n) % ((*stack)->n);
	opcode_pop(stack, l_cnt);
	(*stack)->n = num;
}
