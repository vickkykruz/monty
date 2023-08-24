#include "monty.h"
/**
 * opcode_add - This is a function that return the added first two nodes of
 * the stack
 * @stack: This is an argumemt that reprsent the given stack
 * @l_cnt: This is an argumemt that reprsent the amount to argumemt count
 *
 * Return: This function return a void (nothing)
 */
void opcode_add(stack_t **stack, unsigned int l_cnt)
{
	int num;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L<%d>: can't add, stack too short\n", l_cnt);
		exit(EXIT_FAILURE);
	}

	num = ((*stack)->next->n) + ((*stack)->n);

	opcode_pop(stack, l_cnt);
	(*stack)->n = num;
}
/**
 * opcode_nop - This is a function that return nothing
 * @stack: This is an argument that reprsent the given stack
 * @l_cnt: This is an argumemt that reprsent the amount of argument passed
 *
 * Return: This function return a void (nothing)
 */
void opcode_nop(stack_t **stack, unsigned int l_cnt)
{
	(void)stack;
	(void)l_cnt;
}
