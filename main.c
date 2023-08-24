#define _POSIX_C_SOURCE 200809L
#include "monty.h"
/**
 * file_err - This is a function that display the file error message
 * @argv: This is an argument that revent the vector index 1
 *
 * Return: This function return a void (nothing)
 */
void file_err(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}
/**
 * err_usage - This is a function that display the usage err message
 *
 * Return: This function return a void (nothing)
 */
void err_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * main - This is the entry function of the programm
 * @argc: This is an argument that reprsent the argument count
 * @argv: This is an argument that reprsent the argument vector strings
 *
 * Return: This function always return 0
 */
int main(int argc, char **argv)
{
	int status = 0;
	char *buff = NULL;
	char *s = NULL;
	size_t buff_len = 0;
	unsigned int l_cnt = 1;
	stack_t *stack = NULL;
	FILE *file;

	global_stru.data = 1;
	/* CONDITION: Check if the argument counter is not 2 */
	if (argc != 2)
		err_usage();
	file = fopen(argv[1], "r");
	if (!file)
		file_err(argv[1]);
	while ((getline(&buff, &buff_len, file)) != (-1))
	{
		if (status)
			break;
		if (*buff == '\n')
		{
			l_cnt++;
			continue;
		}
		s = strtok(buff, " \t\n");
		if (!s || *s == '#')
		{
			l_cnt++;
			continue;
		}
		global_stru.args = strtok(NULL, " \t\n");
		analysis_opcode(&stack, s, l_cnt);
		l_cnt++;
	}
	free(buff);
	f_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}
