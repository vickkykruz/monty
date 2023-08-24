#include "monty.h"
/**
 * opcode_rotl - This is a function that return the first elememt of the stack
 * @stack: This is an argument that reprsent the given stack head
 * @l_cnt: This is an argumemt that rprsent the amount of argument passed
 *
 * Return: This function return a void (nothing)
 */
void opcode_rotl(stack_t **stack, unsigned int l_cnt)
{
	stack_t *prev, *tmp;

	(void)l_cnt;
	if (!stack || !(*stack) || !((*stack)->next))
		return;

	prev = *stack;
	tmp = *stack;

	while (tmp->next)
		tmp = tmp->next;
	tmp->next = prev;
	prev->prev = tmp;
	*stack = prev->next;

	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
/**
 * opcode_rotr - This is a function that return the rotates the last node of
 * the stack_t struct
 * @stack: This is an argumemt that reprsent the stack head
 * @l_cnt: This is an argumemt that reprsent amount of argumemt passed
 *
 * Return: This function return a void (nothing)
 */
void opcode_rotr(stack_t **stack, unsigned int l_cnt)
{
	stack_t *tmp, *prev;

	(void)l_cnt;
	if (!stack || !(*stack) || !((*stack)->next))
		return;

	tmp = *stack;

	while (tmp->next)
		tmp = tmp->next;

	prev = tmp->prev;
	tmp->next = *stack;
	tmp->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
}
