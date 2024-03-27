/** CODE to extract opcodes from the instruction line */

#include "monty.h"

/**
 * get_opcode - gets the opcode from a line and formats it properly
 * @inst_line: the instruction line
 *
 * Return: pointer to the opcode
 */

char *get_opcode(char *inst_line)
{
	char *opcode;

	if (inst_line == NULL)
		return (NULL);

	/* Strip the newline character */
	inst_line[strlen(inst_line) - 1] = '\0';

	/* Get the opcode */
	opcode = strtok(inst_line, " ");
	return (opcode);
}
