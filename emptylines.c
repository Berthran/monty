/** CODE to handle different empty instruction lines */

/* Include header files */
#include "monty.h"

/**
 * is_newline - checks if an instruction line is empty
 * @inst_line: the instruction line
 *
 * Return: 1 if the instruction line is empty, 0 if not
 */
int is_newline(char *inst_line)
{
	if (inst_line != NULL)
		if (*inst_line == '\n')
			return (1);
	return (0);
}

/**
 * is_spaces - checks if an instruction line is only spaces
 * @inst_line: the instruction line
 *
 * Return: 1 if the instruction line is empty, 0 if not
 */
int is_spaces(char *inst_line)
{
	if (inst_line != NULL)
	{
		while (*inst_line != '\n')
		{
			if (*inst_line != ' ')
				return (0);
			++inst_line;
		}
	}
	return (1);
}

/**
 * is_empty - checks if an instruction line is empty
 * @inst_line: the instruction line
 *
 * Return: 1 if the instruction line is empty, 0 if not
 */

int is_empty(char *inst_line)
{
	if (is_newline(inst_line) == 1 || is_spaces(inst_line) == 1)
		return (1);
	return (0);
}
