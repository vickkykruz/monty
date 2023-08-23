#include "main.h"
/**
 * analysis_file - This is a function that return the analysised file with tje
 * carryout commands
 * @dir: This is an argment that reprsent the file path
 *
 * Return: This function return a void (nothing)
 */
void analysis_file(char *dir)
{
	char *cmd, *val, *res;
	unsigned int cmd_line = 0;
	FILE *file;
	void (*opcode_fun)(stack_t **stack, unsigned int line_number);

	/** Open the file for only READONLY **/
	file = fopen(dir, "r");
	if (!file) /** If Failed **/
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", dir);
		exit(EXIT_FAILURE);
	}

	initizated_global(file, NULL, NULL, NULL, 1);

	while (1)
	{
		cmd_line++;
		stru.buffer = malloc(sizeof(char) * MAX_SIZE);
		if (!stru.buffer) /** If failed */
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		res = fgets(stru.buffer, MAX_SIZE, stru.file);
		if (!res)
			break;

		cmd = strtok(stru.buffer, " \t\n\r");
		val = strtok(NULL, " \t\n\r");
		if (cmd && cmd[0] != '#')
		{
			opcode_fun = get_opcode_fun(cmd, cmd_line);
			stru.str = val;
			opcode_fun(&stru.stack, cmd_line);
		}
		free(stru.buffer);
	}
	free_glob();
}
