#include "main.h"
#include <stdio.h>
/**
 * _itoa - This is a function that return the converted integer to string
 * @num: This is an argument that reprsent the given integer
 *
 * Return: The function return the converted string
 */
char *_itoa(int num)
{
	char *ptr;
	int len;

	len = snprintf(NULL, 0, "%d", num);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	sprintf(ptr, "%d", num);
	return (ptr);
}
/**
 * is_digit - This is a function that check if the array of chars is a number
 * @cmd_line: This is an argument that reprsent the number command line
 *
 * Return: This function return a void (nothing)
 */
void is_digit(unsigned int cmd_line)
{
	int i, st = 0;

	if (stru.str[st] == '-' || stru.str[st] == '+')
		st++;
	for (i = st; stru.str[i]; i++)
	{
		if (stru.str[i] < '0' || stru.str[i] > '9')
		{
			fprintf(stderr, "L<%d>: usage: push integer\n", cmd_line);
			free_glob();
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * push_queue - This is a function that return the pused queue
 * @stack: This is an argument that reprsent the given queue
 * @n: This is an argument that reprsent number passed to push
 *
 * Return: This function return a void (nothing)
 */
void push_queue(stack_t **stack, int n)
{
	stack_t *new_node, *tmp = *stack;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		free_glob();
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = tmp;

	if (*stack)
		tmp->prev = new_node;
	*stack = new_node;
}
