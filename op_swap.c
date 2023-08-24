#include "monty.h"
/**
 * opcode_swap - This is a function that returns the top to the prev
 * @stack: This is an argument that reprsent the given stack
 * @l_cnt: This is an argument that reprsent the amount of lines passed
 *
 * Return: This function return a void (nothing)
 */
void opcode_swap(stack_t **stack, unsigned int l_cnt)
{
	int n = 0;
	stack_t *tmp = NULL;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l_cnt);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	n = tmp->n;
	tmp->n = n;

	tmp->n = tmp->next->n;
	tmp->next->n = n;
}
