#include "main.h"
/**
 * initizated_global - This is a function that return the initizated global
 * arguments in the global structure
 * @file: This argument reprsent the given filename path
 * @sta: This is an argument that reprsent the given stack data
 * @str: This is an argument that reprsent the given string
 * @buffer: This is an argument that reprsent the given size buffer
 * @num: This is an arguments that reprsent the number of stacks or queue
 *
 * Return: This function return a void (nothing)
 */
void initizated_global(FILE *file, stack_t *sta, char *str, char *buffer,
int num)
{
	stru.file = file;
	stru.stack = sta;
	stru.buffer = buffer;
	stru.str = str;
	stru.isstack = num;
}
