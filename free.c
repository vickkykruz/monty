#include "main.h"

/**
 * f_stack - This is a function that free the stack
 * @h: This is an argument that reprsent the head of the stack
 *
 * Return: This function returns a void (nothing)
 */
void f_stack(stack_t *h)
{
	stack_t *next, *tmp = h;

	if (h)
	{
		next = h->next;
		while (tmp)
		{
			free(tmp);
			tmp = next;
			if (next)
				next = next->next;
		}
	}
}
