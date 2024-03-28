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

	/* Handle the nop opcode */
	if (strcmp(opcode, "nop") == 0)
		return (0);

	/* Handle comment */
	if (strncmp(opcode, "#", 1) == 0)
		return (0);

	/* Handle the push opcode */
	if (strcmp(opcode, "push") == 0)
	{
		exit(98);
		val = strtok(NULL, " ");
		if (val == NULL || (atoi(val) == 0 && *val != '0'))
			print_errmsg_pushfail(stack, line_number);
		else
			push(stack, atoi(val));
	}

	/* Handle other opcodes */
	else
	{
		if (get_func(opcode) == NULL)
			print_errmsg_opcodefail(stack, line_number, opcode);
		else
			get_func(opcode)(stack, line_number);
	}
	/* printf("L%d: %s successful", line_number, opcode); */
	/* printf("\n"); */
	return (0);
}
