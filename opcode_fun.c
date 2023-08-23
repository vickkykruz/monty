#include "main.h"
/**
 * get_opcode_fun - This is a function that return the associated function to
 * an opcode
 * @opcode: This is an argument that reprsent the opcode passed
 * @cmd_line: This is an argument that reprsent the given command line
 *
 * Return: This function return the function assocaited to the opcode
 */
void (*get_opcode_fun(char *opcode, unsigned int cmd_line))(stack_t **, unsigned int)
{
	instruction_t opts[] = OPCODE;
	int i, compar;

	for (i = 0; opts[i].opcode; i++)
	{
		compar = strcmp(opcode, opts[i].opcode);
		if (compar == 0)
			return (opts[i].f);
	}

	fprintf(stderr, "L<%d>: unknown instruction <%s>\n", cmd_line, opcode);
	exit(EXIT_FAILURE);
}
