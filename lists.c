#include "monty.h"
/**
 * add_node - This is a function that return the added nodde of a stack_t
 * @stack: This is an argument that reprsent the given stack head
 * @num: This is an argument that reprsent the number of node to be added
 *
 * Return: This function return a newly list
 */
stack_t *add_node(stack_t **stack, const int num)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		return (NULL);
	}

	new_node->n = num;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;

	return (new_node);
}
/**
 * queue_node - This is a function that return the add node in the queue
 * @stack: This is an argument that reprsent the stack head
 * @num: This is an argument that reprsent the number of the node
 *
 * Return: This function create a new list otherwise NULL
 */
stack_t *queue_node(stack_t **stack, const int num)
{
	stack_t *tmp = *stack;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}

	new_node->n = num;
	if (!(*stack))
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
		return (new_node);
	}

	while (tmp)
	{
		if (!tmp->next)
		{
			new_node->next = NULL;
			new_node->prev = tmp;
			tmp->next = new_node;
			break;
		}
		tmp = tmp->next;
	}
	return (new_node);
}
/**
 * print_stack - This is a function return the printed contents of stack_t
 * @stack: This is an argument that reprsent the stack head
 *
 * Return: This is a function that retun the number of elements in the list
 */
size_t print_stack(const stack_t *stack)
{
	size_t ch = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		ch++;
	}
	return (ch);
}
