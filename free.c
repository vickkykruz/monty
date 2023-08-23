#include "main.h"
/**
 * f_stack - This is a function that free the stack
 * @h: This is an argument that reprsent the head of the stack
 *
 * Return: This function returns a void (nothing)
 */
void f_stack(stack_t *h)
{
	stack_t *prev, *tmp = h;

	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
}
/**
 * free_glob - This is a function that free the global structure
 *
 * Return: This is a function that return void (nothing)
 */
void free_glob(void)
{
	fclose(stru.file);
	free(stru.buffer);
	f_stack(stru.stack);
}
