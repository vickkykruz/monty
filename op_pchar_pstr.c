#include "monty.h"
/**
 * opcode_pstr - a function that return the printed content of the
 * stack_t stuct as a sting
 * @stack: This is an argument that reprsent the given stack
 * @l_cnt: This is an argument that rprsent the amount of argumemt passed
 *
 * Return: This function return a void (nothing)
 */
void opcode_pstr(stack_t **stack, unsigned int l_cnt __attribute__((unused)))
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		if (tmp->n <= 0 || tmp->n > 127)
			break;
		putchar((char) tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
