#include "monty.h"
/**
 * opcode_mul - This is a function that return the multiped top next elememt
 * of the stack
 * @stack: This is an argument that reprsent the givem stack
 * @l_cnt: This is an argumemt that reprsent the amount of argument passed
 *
 * Return: This function return a void (nothing)
 */
void opcode_mul(stack_t **stack, unsigned int l_cnt)
{
	int num;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", l_cnt);
		exit(EXIT_FAILURE);
		return;
	}

	num = ((*stack)->next->n) * ((*stack)->n);
	opcode_pop(stack, l_cnt);
	(*stack)->n = num;
}
/**
 * opcode_div - This is a function that return the divided top next elements
 * of the stack
 * @stack: This is an argument that reprsent the given stack
 * @l_cnt: This is an argumemt that reprsent tje amount of argumemt passed
 *
 * Return: This function return a void (nothing)
 */
void opcode_div(stack_t **stack, unsigned int l_cnt)
{
	int num;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", l_cnt);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_cnt);
		exit(EXIT_FAILURE);
		return;
	}

	num = ((*stack)->next->n) / ((*stack)->n);
	opcode_pop(stack, l_cnt);
	(*stack)->n = num;
}
