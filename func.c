#include "main.h"
/**
 * is_digit - This is a function check if a string is a digit
 * @str: This is an argument that reprsent the given string
 *
 * Return: This function 1 if success otherwise 0 if not
 */
int is_digit(char *str)
{
	if (!str || *str == '\0')
		return (0);
	if (*str == '-')
		str++;

	while (*str)
	{
		if (isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
