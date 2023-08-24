#include "monty.h"
/**
 * opcode_push - This is a function that return the pushed element to stack
 * @stack: This is an argument that reprsent the given stack
 * @cmd_line: This is an argument that reprsent the given number of cmd line
 *
 * Return: This function return a void (nothing)
 */
void opcode_push(stack_t **stack, unsigned int cmd_line)
{
	char *num = global_stru.args;

	if ((is_digit(num)) == 0)
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", cmd_line);
		exit(EXIT_FAILURE);
	}


	if (global_stru.data == 1)
	{
		if (!add_node(stack, atoi(global_stru.args)))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!queue_node(stack, atoi(global_stru.args)))
			exit(EXIT_FAILURE);
	}
}
/**
 * opcode_pall - This is a function return the printed stack from the top
 * @stack: This is an argument that reprsent the given stack
 * @l_cnt: This is an argument that reprsent the given command line
 *
 * Return: This function return a void (nothing)
 */
void opcode_pall(stack_t **stack, unsigned int l_cnt __attribute__((unused)))
{
	print_stack(*stack);
}
