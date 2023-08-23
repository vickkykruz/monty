#include "main.h"
/**
 * opcode_mul - This is a function that multiplies the top element of the
 * stack by the top element of the secound stack
 * @stack: This is an argument that reprsent the given stack
 * @cmd_line: This is an argument that reprsent the number of cmd line
 *
 * Return: This function return a void (nothing)
 */
void opcode_mul(stack_t **stack, unsigned int cmd_line)
{
	stack_t *tmp = *stack;
	int prev_stack;
	char *str;

	if (!(*stack) || !(*stack)->next)
	{
		free_glob();
		fprintf(stderr, "L<%d>: can't mul, stack too short\n", cmd_line);
		exit(EXIT_FAILURE);
	}

	for (; tmp->next->next; tmp = tmp->next)
		;
	str = _itoa(tmp->n * tmp->next->n);

	opcode_pop(stack, cmd_line);
	opcode_pop(stack, cmd_line);

	stru.str = str;
	prev_stack = stru.isstack;
	stru.isstack = 1;
	opcode_push(stack, cmd_line);
	stru.isstack = prev_stack;

	free(str);
}
/**
 * opcode_div - The function that return the divided elemrnt of the second top
 * from the top element of the stack
 * @stack: This is an argument that reprsent the given stack
 * @cmd_line: This is an arguemnt that reprsent the given number of cmd line
 *
 * Return: This function return a void (nothing)
 */
void opcode_div(stack_t **stack, unsigned int cmd_line)
{
	stack_t *tmp = *stack;
	int prev_stack;
	char *str;

	if (!(*stack) || !(*stack)->next)
	{
		free_glob();
		fprintf(stderr, "L<%d>: can't div, stack too short\n", cmd_line);
		exit(EXIT_FAILURE);
	}

	for (; tmp->next->next; tmp = tmp->next)
		;

	if (tmp->next->n == 0)
	{
		fprintf(stderr, "L<%d>: division by zero\n", cmd_line);
		free_glob();
		exit(EXIT_FAILURE);
	}

	str = _itoa(tmp->n / tmp->next->n);

	opcode_pop(stack, cmd_line);
	opcode_pop(stack, cmd_line);

	stru.str = str;
	prev_stack = stru.isstack;
	stru.isstack = 1;
	opcode_push(stack, cmd_line);
	stru.isstack = prev_stack;

	free(str);
}
