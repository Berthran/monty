/* CODE to interprete instruction */

#include "monty.h"

/**
 * get_func - gets the function of a valid opcode
 * @opcode: the opcode to validate and get a function for
 *
 * Return: pointer to the function or NULL
 */

void (*get_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t op_func[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}};
	size_t opcode_len, i = 0;
	char *valid_opcode = op_func[i].opcode;

	do {
		opcode_len = strlen(valid_opcode);
		if (strncmp(valid_opcode, opcode, opcode_len) == 0)
			return (op_func[i].f);
		++i;
		valid_opcode = op_func[i].opcode;
	} while (valid_opcode != NULL);
	return (NULL);
}
