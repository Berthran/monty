/* CODE to interprete instruction */

#include "monty.h"

/**
 * get_func - get the function of a valid opcode
 * @opcode: the opcode to validate and get a function for
 *
 * Return: pointer to the function or NULL
 */

void (*get_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t op_func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", set_stack},
		{"queue", set_queue},
		{NULL, NULL}};
	size_t i = 0;
	char *valid_opcode = op_func[i].opcode;

	do {
		if (strcmp(valid_opcode, opcode) == 0)
			return (op_func[i].f);
		++i;
		valid_opcode = op_func[i].opcode;
	} while (valid_opcode != NULL);

	return (NULL);
}
