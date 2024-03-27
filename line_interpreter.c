/* CODE to interprete instruction */

#include "monty.h"

/**
 * lineInterpreter - interpretes a line to determine its operation
 * @stack: the stack data structure
 * @line: the instruction line to interprete
 * @line_number: the number of the instruction in the file
 *
 * Return: 1 if successfully interpreted, 0 if instruction not found
 */

int lineInterpreter(stack_t **stack, char *line, int line_number)
{
	char *opcode, *val = NULL;

	if (is_empty(line) != 0)
		return (0);

	opcode = get_opcode(line);
	/* Handle the push opcode */
	if (strcmp(opcode, "push") == 0)
	{
		val = strtok(NULL, " ");
		if (push(stack, val, line_number) == -1)
			return (-1);
	}
	/* Handle other opcodes */
	else
	{
		if (get_func(opcode) == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			return (-1);
		}
		get_func(opcode)(stack, line_number);
	}

	printf("L%d: %s", line_number, opcode);
	printf("\n");
	return (0);
}
