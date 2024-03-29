/* CODE to implement converting string to integer */

#include "monty.h"

/**
 * stoi - converts a string representation of an integer to an interger
 * @str: the string to convert
 *
 * Return: -1 on error, the integer on success
 */

int stoi(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 && str[i] == '-')
		{
			if (str[i + 1] == '\0')
				return (0);
			continue;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			continue;
		else
			return (0);
	}
	return (atoi(str));
}
