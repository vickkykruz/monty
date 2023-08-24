#include "monty.h"
/**
 * analysis_opcode - This is a function that return the associated function to
 * an opcode
 * @stack: This is an argument that reprsent the opcode passed
 * @s: This is an argument that reprsent the given string
 * @l_cnt: This is an argument that reprsent the given command line
 *
 * Return: This function return the function assocaited to the opcode
 */
void analysis_opcode(stack_t **stack, char *s, unsigned int l_cnt)
{
	instruction_t opts[] = OPCODE;
	int i = 0;

	if (!strcmp(s, "stack"))
	{
		global_stru.data = 1;
		return;
	}
	if (!strcmp(s, "queue"))
	{
		global_stru.data = 0;
		return;
	}
	while (opts[i].opcode)
	{
		if (strcmp(opts[i].opcode, s) == 0)
		{
			opts[i].f(stack, l_cnt);
			return;
		}
		i++;
	}

	fprintf(stderr, "L<%d>: unknown instruction <%s>\n", l_cnt, s);
	exit(EXIT_FAILURE);
}
