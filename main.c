#include "main.h"
/**
 * main - This is the entry function of the programm
 * @argc: This is an argument that reprsent the argument count
 * @argv: This is an argument that reprsent the argument vector strings
 *
 * Return: This function always return 0
 */
int main(int argc, char **argv)
{
	/* CONDITION: Check if the argument counter is not 2 */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	analysis_file(argv[1]);
	return (0);
}
