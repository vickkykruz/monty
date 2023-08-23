#include "main.h"
/**
 * opcode_push - This is a function that return the pushed element to stack
 * @stack: This is an argument that reprsent the given stack
 * @cmd_line: This is an argument that reprsent the given number of cmd line
 *
 * Return: This function return a void (nothing)
 */
void opcode_push(stack_t **stack, unsigned int cmd_line)
{
	int num;
	stack_t *new_node, *tmp = *stack;

	if (!stru.str)
	{
		free_glob();
		fprintf(stderr, "L<%d>: usage: push integer\n", cmd_line);
		exit(EXIT_FAILURE);
	}

	is_digit(cmd_line);
	num = atoi(stru.str);
	if (stru.isstack == 1)
	{
		new_node = malloc(sizeof(stack_t));
		if (!new_node)
		{
			free_glob();
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		new_node->n = num;
		new_node->prev = NULL;
		new_node->next = NULL;

		if (!(*stack)) /* If stack is NULL */
			*stack = new_node;
		else
		{
			for (; tmp->next; tmp = tmp->next)
				;
			new_node->prev = tmp;
			tmp->next = new_node;
		}
	}
	else
		push_queue(stack, num);
}
/**
 * opcode_pall - This is a function return the printed stack from the top
 * @stack: This is an argument that reprsent the given stack
 * @cmd_line: This is an argument that reprsent the given command line
 *
 * Return: This function return a void (nothing)
 */
void opcode_pall(stack_t **stack, unsigned int cmd_line)
{
	stack_t *tmp = *stack;
	(void)cmd_line;

	if (tmp)
	{
		for (; tmp->next; tmp = tmp->next)
			;
		for (; tmp; tmp = tmp->prev)
			printf("%d\n", tmp->n);
	}
}
